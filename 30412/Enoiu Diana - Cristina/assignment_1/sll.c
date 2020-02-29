//
// Created by Diana on 2/29/2020.
//
#include "sll.h"

void initializeSll() {
    first = NULL;
    last = NULL;
}
void addFirst(int data) {
    if (first == NULL) {
        first = (NodeT *)malloc(sizeof(NodeT));
        first->data = data;
        first->next = last;
        last = NULL;
    }
    else {
        NodeT * newElement = (NodeT *)malloc(sizeof(NodeT));
        newElement->data = data;
        newElement->next = first;
        first = newElement;
    }
}
void printSll() {
    if(first == NULL) {
        printf("List is empty!\n");
    }
    else {
        last = first;
        while (last != NULL) {
            printf("%d ", last->data); //esier?
            last = last->next;
        }
        printf("\n");
    }
}