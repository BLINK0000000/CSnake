#include "gameFunctions.h"
#include <stdio.h>
#include "raylib.h"
#include "player.h"
#include <time.h>
#include <stdlib.h>
#include "fruit.h"
#include "deque.h"

void UpdateDrawFrame(Player *player, Fruit* fruit){
    UpdateGame(player, fruit);
    DrawGame(player, fruit);
}

void UpdateGame(Player *player, Fruit* fruit){
    PlayerMove(player, fruit);
    PlaceFruit(fruit);
}

void DrawGame(Player *player, Fruit* fruit){
    BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw player by iterating through the deque
        Node* temp = player->deque.front;
        
        while(temp != NULL){
            DrawRectangle(temp->position.x, temp->position.y, player->size.x, player->size.y, BLUE);
            temp = temp->next;
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