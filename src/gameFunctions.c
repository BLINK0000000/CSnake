#include "gameFunctions.h"
#include <stdio.h>
#include "raylib.h"

void UpdateDrawFrame(void){
    UpdateGame();
    DrawGame();
}

void UpdateGame(void){

}

void DrawGame(void){
    BeginDrawing();
        ClearBackground(RAYWHITE);
        
    EndDrawing();
}

void UnloadGame(void){

}

void InitGame(void){
    
}