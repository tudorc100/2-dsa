//
// Created by Diana on 2/29/2020.
//

#ifndef ASSIGNMENT_1_SLL_H
#define ASSIGNMENT_1_SLL_H
#include <stdio.h>
#include <stdlib.h>
void initializeSll();
void AF(int data);
void AL(int data);
void DF();
void DL();
void PRINT_ALL();
typedef struct _node {
    int data;
    struct _node * next;
} NodeT;
NodeT * first, * last;
#endif //ASSIGNMENT_1_SLL_H
