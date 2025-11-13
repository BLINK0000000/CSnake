#include <stdio.h>
#include "raylib.h"
#include "gameFunctions.h"
#include "player.h"

#define FPS 180
//TODO: Need to add game over state when colliding with screen
int main(){
    const int screenWidth = 800;
    const int screenHeight = 450;

    Player player = {0};

    InitWindow(screenWidth, screenHeight, "CSnake");

    Rectangle screenRect = (Rectangle){0, 0, GetScreenWidth(), GetScreenHeight()};

    SetTargetFPS(FPS);

    InitGame(&player);

    while (!WindowShouldClose()){
        UpdateDrawFrame(&player);    
    }

    UnloadGame();
    CloseWindow();

    return 0;
}