#include <stdio.h>
#include "raylib.h"
#include "fruit.h"
#include "gameFunctions.h"

void InitFruit(Fruit* fruit){
    fruit->position = (Vector2){0, 0};
    fruit->size = 5;
    fruit->ate = true;
}
void PlaceFruit(Fruit* fruit){
    if (fruit->ate){
        fruit->position = (Vector2){(RandomNumber(GetScreenWidth(), 0, true)), (RandomNumber(GetScreenHeight(), 0, true))};
        fruit->ate = false;
    }
}