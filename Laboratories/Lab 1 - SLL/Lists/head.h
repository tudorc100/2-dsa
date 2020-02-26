#include <stdio.h>
#include <stdlib.h>
void initializeSll();
void addElement(int key);
void printSllData();
void removeElement(int key);
void removeAll();

typedef struct node {
    int data;
    struct node * next;
} NodeT;

NodeT * first, * last;
