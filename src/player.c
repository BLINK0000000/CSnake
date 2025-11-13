#include <stdio.h>
#include "raylib.h"
#include "player.h"

void InitPlayer(Player* player){
    player->size = (Vector2){GetScreenWidth()/10, GetScreenHeight()/10};
    player->position = (Vector2){GetScreenWidth()/2, GetScreenHeight()/2};
    player->velocity = (Vector2){0, 0};
    player->score = 0;
    player->active = false;
}
void PlayerMove(Player* player){

}
