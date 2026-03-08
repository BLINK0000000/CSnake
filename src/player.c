#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "player.h"
#include "fruit.h"
#include "deque.h"

#define PLAYER_SPEED 250
#define INITIAL_PLAYER_SIZE 3

void InitPlayer(Player* player){

    initDeque(&player->deque);
    player->position = (Vector2){GetScreenWidth()/2 - player->size.x/2, GetScreenHeight()/2 - player->size.y/2};
    player->size = (Vector2){GetScreenWidth()/30, GetScreenWidth()/30};

    for (int i = 0; i <= INITIAL_PLAYER_SIZE; ++i){
        GrowPlayer(player);
    }

    player->score = 0;
    player->active = true;
}

// void PlayerMove(Player *player, Fruit* fruit){
    

//     if (CollisionScreenPlayer(*player)){
//         (*player)->active = false;
//     }

//     if (CheckCollisionCircleRec(fruit->position, fruit->size, (Rectangle){(*player)->position.x, (*player)->position.y, (*player)->size.x, (*player)->size.y})){
//         fruit->ate = true;
//         (*player)->score += 1;
//         GrowPlayer(player);
//     }

//     if (!(*player)->active){
//         reset(player);
//         (*player)->active = true;
//     }

// }

void GrowPlayer(Player* player){
    insertRear(&player->deque, 1);
}

// void reset(Player **player){
    
    

// }

bool CollisionScreenPlayer(Player* player){
    if (((player->position.x + player->size.x) > GetScreenWidth()) || (player->position.x < 0) || (player->position.y < 0) || (player->position.y + player->size.y > GetScreenHeight())){
        return true;
    }
    else return false;
}
