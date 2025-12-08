#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "gameFunctions.h"
#include "player.h"
#include "fruit.h"

#define FPS 180
//TODO: Need to add game over state when colliding with screen
int main(){
    const int screenWidth = 800;
    const int screenHeight = 450;

    //Player player = {0};
    Player *player = (Player *)malloc(sizeof(Player) * 2);

    if (player == NULL){
        printf("Memory allocation of player failed");
        exit(0);
    }
    Fruit fruit = {0};

    InitWindow(screenWidth, screenHeight, "CSnake");

    Rectangle screenRect = (Rectangle){0, 0, GetScreenWidth(), GetScreenHeight()};

    SetTargetFPS(FPS);

    InitGame(player, &fruit);

    while (!WindowShouldClose()){
        UpdateDrawFrame(player, &fruit);    
    }

    UnloadGame();
    free(player);
    player = NULL;
    CloseWindow();

    return 0;
}