#include <stdio.h>
#include "raylib.h"
#include "gameFunctions.h"

int main(){
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "CSnake");

    SetTargetFPS(60);

    InitGame();
    
    while (!WindowShouldClose()){
        UpdateDrawFrame();    
    }

    UnloadGame();
    CloseWindow();

    return 0;
}