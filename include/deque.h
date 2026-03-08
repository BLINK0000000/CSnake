#pragma once

#include <stdio.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct Deque{
    Node* front;
    Node* rear;
    int size;
}Deque;

Node* createNode(int data);
void initDeque(Deque* deque);
void insertFront(Deque* deque, int data);
void insertRear(Deque* deque, int data);
void deleteFront(Deque* deque);
void deleteRear(Deque* deque);
int isEmpty(Deque* deque);
