#pragma once

#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct Deque{
    Node *front;
    Node *rear;
    int size;
}Deque;

Node* createNode(int data);
Deque* initDeque();
void insertFront(Deque* deque, int data);
void insertRear(Deque* head, int data);
void deleteFront(Deque* head);
void deleteRear(Deque* head);
int isEmpty(Deque* deque);
