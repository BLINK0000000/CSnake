// gameFunctions.h
// Header declaring functions related to core game loop
#pragma once

#include "player.h"

void UpdateDrawFrame(Player* player);
void UpdateGame(Player* player);
void DrawGame(Player* player);
void UnloadGame();
void InitGame(Player* player);
