#include <stdio.h>
#include "raylib.h"
#include "player.h"

#define PLAYER_SPEED 250

void InitPlayer(Player* player){
    player->size = (Vector2){GetScreenWidth()/30, GetScreenWidth()/30};
    player->position = (Vector2){GetScreenWidth()/2 - player->size.x/2, GetScreenHeight()/2 - player->size.y/2};
    player->velocity = (Vector2){0, 0};
    player->score = 0;
    player->active = true;
}
void PlayerMove(Player* player){
    
    if (IsKeyPressed(KEY_W)){
        player->velocity = (Vector2){0, 0};
        player->velocity.y = PLAYER_SPEED * -1;
    }
    if (IsKeyPressed(KEY_S)){
        player->velocity = (Vector2){0, 0};
        player->velocity.y = PLAYER_SPEED;
    }
    if (IsKeyPressed(KEY_A)){
        player->velocity = (Vector2){0, 0};
        player->velocity.x = PLAYER_SPEED * -1;
    }
    if (IsKeyPressed(KEY_D)){
        player->velocity = (Vector2){0, 0};
        player->velocity.x = PLAYER_SPEED;
    } 

    player->position.y += player->velocity.y * GetFrameTime();
    player->position.x += player->velocity.x * GetFrameTime();

    if (CollisionWithScreenPlayer(player)){
        player->active = false;
        player->position = (Vector2){GetScreenWidth()/2 - player->size.x/2, GetScreenHeight()/2 - player->size.y/2};
        player->velocity = (Vector2){0, 0};
    }

}

bool CollisionWithScreenPlayer(Player* player){
    if ((player->position.x > GetScreenWidth()) || (player->position.x < 0) || (player->position.y < 0) || (player->position.y > GetScreenHeight())){
        return true;
    }
    else return false;
}
