#pragma once

#include <stdio.h>

typedef struct Fruit{
    Vector2 position;
    int size;
    bool ate;
}Fruit;

void InitFruit(Fruit* fruit);
void PlaceFruit(Fruit* fruit);