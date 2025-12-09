// player.h
// Header declaring structures and functions for the player
#pragma once

#include "raylib.h"
#include "fruit.h"

typedef struct Player{
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
    int score;
    bool active;
}Player;

void InitPlayer(Player* player);
void PlayerMove(Player* player, Fruit* fruit);
bool CollisionScreenPlayer(Player* player);
void growPlayer(Player* player);
void reset(Player* player);