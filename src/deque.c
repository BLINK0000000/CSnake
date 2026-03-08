#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

Node* createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void initDeque(Deque* deque){
    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;

}

int isEmpty(Deque* deque){
    if (deque->size == 0){
        return 1;
    }
    else{return 0;}
}

void insertFront(Deque* deque, int data){
    Node* newNode = createNode(data);

    if (isEmpty(deque)){
        deque->front = newNode;
        deque->rear = newNode;
    }
    else{
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }

    deque->size++;
}

void insertRear(Deque* deque, int data){
    Node* newNode = createNode(data);

    if (isEmpty(deque)){
        deque->rear = newNode;
        deque->front = newNode;
    }
    else{
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    
    deque->size++;
}

void deleteFront(Deque* deque){
    if (isEmpty(deque)){
        printf("Underflow");
        return;
    }
    else{
        Node* temp = deque->front;
        deque->front = deque->front->next;
        if (deque->front != NULL){
            deque->front->prev = NULL;
        }
        else{
            deque->rear = NULL;
        }
        
        free(temp);
        deque->size--;
    }
}

void deleteRear(Deque* deque){
    if (isEmpty(deque)){
        printf("Underflow");
        return;
    }
    else {
        Node* temp = deque->rear;
        deque->rear = deque->rear->prev;
        if (deque->rear != NULL){
            deque->rear->next = NULL;
        }
        else {
            deque->front = NULL;
        }

        free(temp);
        deque->size--;
    }
}




