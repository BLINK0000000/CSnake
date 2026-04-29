#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "player.h"
#include "fruit.h"
#include "deque.h"

#define PLAYER_SPEED 250

void InitPlayer(Player* player){

    initDeque(&player->deque);
    player->size = (Vector2){GetScreenWidth()/30, GetScreenWidth()/30};

    // Create first node to have position at centre of screen
    insertFront(&player->deque, (Vector2){GetScreenWidth()/2 - player->size.x/2, GetScreenHeight()/2 - player->size.y/2});

    player->score = 0;
    player->active = true;
}

// Must be a better way to do this, maybe change whole design to be a state machine so it's all easier to manage
void PlayerMove(Player *player, Fruit* fruit){
    
    if ((IsKeyPressed(KEY_W)) && (player->velocity.y == 0)){

        player->velocity = (Vector2){0, 0};
        
        player->velocity.y = -1;
    }
    if ((IsKeyPressed(KEY_S)) && (player->velocity.y == 0)){
        player->velocity = (Vector2){0, 0};
        
        player->velocity.y = 1;
    }
    if ((IsKeyPressed(KEY_A)) && (player->velocity.x == 0)){
        player->velocity = (Vector2){0, 0};
        
        player->velocity.x = -1;
    }
    if ((IsKeyPressed(KEY_D)) && (player->velocity.x == 0)){
        player->velocity = (Vector2){0, 0};
        
        player->velocity.x = 1;
    } 

    if (player->velocity.x == 1){
            insertFront(&player->deque, (Vector2){player->deque.front->position.x + player->size.x, player->deque.front->position.y});
            deleteRear(&player->deque);
    }
    if (player->velocity.x == -1){
            insertFront(&player->deque, (Vector2){player->deque.front->position.x - player->size.x, player->deque.front->position.y});
            deleteRear(&player->deque);
    }
    if (player->velocity.y == 1){
            insertFront(&player->deque, (Vector2){player->deque.front->position.x, player->deque.front->position.y + player->size.y});
            deleteRear(&player->deque);
    }
    if (player->velocity.y == -1){
            insertFront(&player->deque, (Vector2){player->deque.front->position.x, player->deque.front->position.y - player->size.y});
            deleteRear(&player->deque);
    }
    

    if (CollisionScreenPlayer(player)){
        player->active = false;
    }

    if (CheckCollisionCircleRec(fruit->position, fruit->size, (Rectangle){player->deque.front->position.x, player->deque.front->position.y, player->size.x, player->size.y})){
        fruit->ate = true;
        player->score += 1;

        if (player->velocity.x == 1){
            GrowPlayer(player, (Vector2){player->deque.rear->position.x - player->size.x, player->deque.rear->position.y}); // maybe change it so it multiplies by velocity, and have an initial velocity when respawning
        }
        if (player->velocity.x == -1){
            GrowPlayer(player, (Vector2){player->deque.rear->position.x + player->size.x, player->deque.rear->position.y});
        }
        if (player->velocity.y == 1){
            GrowPlayer(player, (Vector2){player->deque.rear->position.y - player->size.y, player->deque.rear->position.x});
        }
        if (player->velocity.y == -1){
            GrowPlayer(player, (Vector2){player->deque.rear->position.y + player->size.y, player->deque.rear->position.x});
        }
        
    }

    // if (!player->active){
    //     reset(player);
    //     player->active = true;
    // }

}

void GrowPlayer(Player* player, Vector2 pos){
    
    insertRear(&player->deque, pos);
}

// void reset(Player* player){
    
//     void init

// }

bool CollisionScreenPlayer(Player* player){
    if (((player->deque.front->position.x + player->size.x) > GetScreenWidth()) || (player->deque.front->position.x < 0) || (player->deque.front->position.y < 0) || (player->deque.front->position.y + player->size.y > GetScreenHeight())){
        return true;
    }
    else return false;
}
