#pragma once

#include <stdio.h>
#include "raylib.h"

typedef struct Node{
    Vector2 position;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct Deque{
    Node* front;
    Node* rear;
    int size;
}Deque;

Node* createNode(Vector2 data);
void initDeque(Deque* deque);
void insertFront(Deque* deque, Vector2 data);
void insertRear(Deque* deque, Vector2 data);
void deleteFront(Deque* deque);
void deleteRear(Deque* deque);
int isEmpty(Deque* deque);
