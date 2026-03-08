// gameFunctions.h
// Header declaring functions related to core game loop
#pragma once

#include "player.h"
#include "fruit.h"

typedef struct GameState{
    bool gameOver;
    char gameOverText[9];
}GameState;

void UpdateDrawFrame(Player *player, Fruit* fruit);
void UpdateGame(Player *player, Fruit* fruit);
void DrawGame(Player *player, Fruit* fruit);
void UnloadGame();
void InitGame(Player* player, Fruit* fruit);
int RandomNumber(int max, int min, bool abs);
