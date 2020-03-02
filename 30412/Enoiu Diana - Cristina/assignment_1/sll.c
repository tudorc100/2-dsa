//
// Created by Diana on 2/29/2020.
//
#include "sll.h"

void initializeSll() {
    first = NULL;
    last = NULL;
}
void AF(int data) {
    if (first == NULL) {
        first = (NodeT *)malloc(sizeof(NodeT));
        first->data = data;
        first->next = NULL;
        last = first;
    }
    else {
        NodeT * newElement = (NodeT *)malloc(sizeof(NodeT));
        newElement->data = data;
        newElement->next = first;
        first = newElement;
    }
}
void AL(int data) {
    if (first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->data = data;
        first->next = NULL;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->data = data;
        newElement->next = NULL;
        last = newElement;
    }
}
void DF() {
    if(first != NULL) {
        NodeT *firstElement = first;
        first = first->next;
        free(firstElement);
    }
}
void DL() {
    if(first != NULL) {
        NodeT * currentElement = first;
        NodeT * previousElement= first;
        while (currentElement->next != NULL) {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }
        free (currentElement);
        previousElement->next = NULL;
    }
}
void PRINT_ALL() {
    if(first == NULL) {
        printf("List is empty!\n");
    }
    else {
        NodeT * currentElement;
        currentElement = first;
        while (currentElement != NULL) {
            printf("%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        printf("\n");
    }
}