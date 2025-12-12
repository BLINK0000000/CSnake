#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "player.h"
#include "fruit.h"

#define PLAYER_SPEED 250
#define INITIAL_PLAYER_SIZE 2

void InitPlayer(Player* player){
    player->size = (Vector2){GetScreenWidth()/30, GetScreenWidth()/30};
    player->position = (Vector2){GetScreenWidth()/2 - player->size.x/2, GetScreenHeight()/2 - player->size.y/2};
    player->velocity = (Vector2){0, 0};
    player->score = 0;
    player->active = true;

    player[1].size = player->size;
    player[1].position = player->position;
    player[1].velocity = (Vector2){0, 0};
    player[1].score = 0;
    player[1].active = true;
}
void PlayerMove(Player **player, Fruit* fruit){
    //TODO Player cannot change 180 degrees, only 90
    if ((IsKeyPressed(KEY_W)) && ((*player)->velocity.y == 0)){
        (*player)->velocity = (Vector2){0, 0};
        (*player)->velocity.y = PLAYER_SPEED * -1;
    }
    if ((IsKeyPressed(KEY_S)) && ((*player)->velocity.y == 0)){
        (*player)->velocity = (Vector2){0, 0};
        (*player)->velocity.y = PLAYER_SPEED;
    }
    if ((IsKeyPressed(KEY_A)) && ((*player)->velocity.x == 0)){
        (*player)->velocity = (Vector2){0, 0};
        (*player)->velocity.x = PLAYER_SPEED * -1;
    }
    if ((IsKeyPressed(KEY_D)) && ((*player)->velocity.x == 0)){
        (*player)->velocity = (Vector2){0, 0};
        (*player)->velocity.x = PLAYER_SPEED;
    } 

    //TODO update all positions of each player entity, record the last position every frame
    // Update in reverse order 
    for (int i = ((*player)->score) + 1; i > 0; --i){
        if ((*player)->velocity.x > 0){
            (*player)[i].position.x = (*player)[i - 1].position.x - (*player)->size.x;
            (*player)[i].position.y = (*player)[i - 1].position.y;
        }
        if ((*player)->velocity.x < 0){
            (*player)[i].position.x = (*player)[i - 1].position.x + (*player)->size.x;
            (*player)[i].position.y = (*player)[i - 1].position.y;
        }
        if ((*player)->velocity.y > 0){
            (*player)[i].position.y = (*player)[i - 1].position.y - (*player)->size.y;
            (*player)[i].position.x = (*player)[i - 1].position.x;
        }
        if ((*player)->velocity.y < 0){
            (*player)[i].position.y = (*player)[i - 1].position.y + (*player)->size.y;
            (*player)[i].position.x = (*player)[i - 1].position.x;
        }
    }

    (*player)->position.y += (*player)->velocity.y * GetFrameTime();
    (*player)->position.x += (*player)->velocity.x * GetFrameTime();

    if (CollisionScreenPlayer(*player)){
        (*player)->active = false;
    }

    if (CheckCollisionCircleRec(fruit->position, fruit->size, (Rectangle){(*player)->position.x, (*player)->position.y, (*player)->size.x, (*player)->size.y})){
        fruit->ate = true;
        (*player)->score += 1;
        GrowPlayer(player);
    }

    if (!(*player)->active){
        reset(player);
        (*player)->active = true;
    }

}

void GrowPlayer(Player **player){
    //TODO realloc array and add another player to array
    Player *tempGrowth = (Player *)realloc(*player, (INITIAL_PLAYER_SIZE + (*player)->score - 1) * sizeof(Player));

    if (tempGrowth == NULL){
        printf("Growth reallocation failed");
        exit(0);
    }
    else{
        *player = tempGrowth;
    }

}

void reset(Player **player){
    Player *tempPlayer = (Player *)realloc(*player, INITIAL_PLAYER_SIZE * sizeof(Player));

    if (tempPlayer == NULL){
        printf("Memory reallocation failed");
        exit(0);
    }
    else{
        *player = tempPlayer;
    }

    (*player)->score = 0;
    (*player)->position = (Vector2){GetScreenWidth()/2 - (*player)->size.x/2, GetScreenHeight()/2 - (*player)->size.y/2};
    (*player)->velocity = (Vector2){0, 0};

}

bool CollisionScreenPlayer(Player* player){
    if (((player->position.x + player->size.x) > GetScreenWidth()) || (player->position.x < 0) || (player->position.y < 0) || (player->position.y + player->size.y > GetScreenHeight())){
        return true;
    }
    else return false;
}
