#include "gameFunctions.h"
#include <stdio.h>
#include "raylib.h"
#include "player.h"

void UpdateDrawFrame(Player* player){
    UpdateGame(player);
    DrawGame(player);
}

void UpdateGame(Player* player){
    PlayerMove(player);
}

void DrawGame(Player* player){
    BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawRectangle(player->position.x, player->position.y, player->size.x, player->size.y, BLUE);

    EndDrawing();
}

void UnloadGame(void){

}

void InitGame(Player* player){
    InitPlayer(player);
}