#include <stdio.h>
#include "raylib.h"
#include "player.h"
#include "fruit.h"

#define PLAYER_SPEED 250

void InitPlayer(Player* player){
    player[0].size = (Vector2){GetScreenWidth()/30, GetScreenWidth()/30};
    player[0].position = (Vector2){GetScreenWidth()/2 - player->size.x/2, GetScreenHeight()/2 - player->size.y/2};
    player[0].velocity = (Vector2){0, 0};
    player[0].score = 0;
    player[0].active = true;

    player[1].size = player[0].size;
    player[1].position = player[0].position;
    player[1].velocity = (Vector2){0, 0};
    player[1].score = 0;
    player[1].active = true;
}
void PlayerMove(Player* player, Fruit* fruit){
    //TODO Player cannot change 180 degrees, only 90
    if ((IsKeyPressed(KEY_W)) && (player->velocity.y == 0)){
        player[0].velocity = (Vector2){0, 0};
        player[0].velocity.y = PLAYER_SPEED * -1;
    }
    if ((IsKeyPressed(KEY_S)) && (player->velocity.y == 0)){
        player[0].velocity = (Vector2){0, 0};
        player[0].velocity.y = PLAYER_SPEED;
    }
    if ((IsKeyPressed(KEY_A)) && (player->velocity.x == 0)){
        player[0].velocity = (Vector2){0, 0};
        player[0].velocity.x = PLAYER_SPEED * -1;
    }
    if ((IsKeyPressed(KEY_D)) && (player->velocity.x == 0)){
        player[0].velocity = (Vector2){0, 0};
        player[0].velocity.x = PLAYER_SPEED;
    } 

    //TODO update all positions of each player entity, record the last position every frame
    for (int i = 1; i <= player[0].score + 1; ++i){
        player[i].position.x = player[i-1].position.x + player[i].size.x;
        player[i].position.y = player[i-1].position.y + player[i].size.y;
    }

    player[0].position.y += player[0].velocity.y * GetFrameTime();
    player[0].position.x += player[0].velocity.x * GetFrameTime();

    if (CollisionScreenPlayer(player)){
        player[0].active = false;
        player[0].position = (Vector2){GetScreenWidth()/2 - player->size.x/2, GetScreenHeight()/2 - player->size.y/2};
        player[0].velocity = (Vector2){0, 0};
    }

    if (CheckCollisionCircleRec(fruit->position, fruit->size, (Rectangle){player->position.x, player->position.y, player->size.x, player->size.y})){
        fruit->ate = true;
        player[0].score += 1;
    }

}

void GrowPlayer(Player* player){
    //TODO realloc array and add another player to array
}

bool CollisionScreenPlayer(Player* player){
    if (((player->position.x + player->size.x) > GetScreenWidth()) || (player->position.x < 0) || (player->position.y < 0) || (player->position.y + player->size.y > GetScreenHeight())){
        return true;
    }
    else return false;
}
