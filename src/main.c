#include <stdio.h>
#include "raylib.h"
#include "gameFunctions.h"
#include "player.h"

#define FPS 60

int main(){
    const int screenWidth = 800;
    const int screenHeight = 450;

    Player player = {0};

    InitWindow(screenWidth, screenHeight, "CSnake");

    SetTargetFPS(FPS);

    InitGame(&player);

    while (!WindowShouldClose()){
        UpdateDrawFrame(&player);    
    }

    UnloadGame();
    CloseWindow();

    return 0;
}