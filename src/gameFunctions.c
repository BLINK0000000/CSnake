#include "gameFunctions.h"
#include <stdio.h>
#include "raylib.h"
#include "player.h"
#include <time.h>
#include <stdlib.h>
#include "fruit.h"

void UpdateDrawFrame(Player *player, Fruit* fruit){
    UpdateGame(player, fruit);
    DrawGame(player, fruit);
}

void UpdateGame(Player *player, Fruit* fruit){
    // PlayerMove(player, fruit);
    PlaceFruit(fruit);
}

void DrawGame(Player *player, Fruit* fruit){
    BeginDrawing();
        ClearBackground(RAYWHITE);
        
        for (int i = 0; i <= player->score; ++i){
            DrawRectangle(player[i].position.x, player[i].position.y, player->size.x * player->deque.size, player->size.y, BLUE);
        }
        
        DrawCircle(fruit->position.x, fruit->position.y, fruit->size, GREEN);

    EndDrawing();
}

void UnloadGame(void){

}

void InitGame(Player* player, Fruit* fruit){
    srand(time(NULL));
    InitPlayer(player);
    InitFruit(fruit);
}

int RandomNumber(int max, int min, bool abs){
    int number = rand() % (max + 1 - min) + min;

    if (!abs){
        int coeff = rand();

        if (coeff < (RAND_MAX / 2)){
            number *= -1;
        } 
    }

    return number;
}