// gameFunctions.h
// Header declaring functions related to core game loop
#pragma once

#include "player.h"

typedef struct GameState{
    bool gameOver;
    char gameOverText[9];
}GameState;

void UpdateDrawFrame(Player* player);
void UpdateGame(Player* player);
void DrawGame(Player* player);
void UnloadGame();
void InitGame(Player* player);
