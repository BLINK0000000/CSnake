// player.h
// Header declaring structures and functions for the player
#pragma once

#include "raylib.h"
#include "fruit.h"
#include "deque.h"

typedef struct Player{
    Deque deque;
    Vector2 size;
    Vector2 velocity;
    int score;
    bool active;
}Player;

void InitPlayer(Player* player);
void PlayerMove(Player* player, Fruit* fruit);
bool CollisionScreenPlayer(Player* player);
void GrowPlayer(Player* player, Vector2 pos);
void reset(Player *player);