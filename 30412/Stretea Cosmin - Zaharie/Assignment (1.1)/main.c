//
// Created by Cosmin on 26-Feb-20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LINE 100

typedef struct node {
    int data;
    struct node *next;
} Node;
Node *first = NULL, *last = NULL;

void AF(int x);
void AL(int x);
void DF();
void DL();
void DOOM_THE_LIST();
void DE(int x);
void PRINT_ALL();
void PRINT_F(int x);
void PRINT_L(int x);

FILE *input, *output;

int main() {
    input = fopen("input.dat", "r");
    output = fopen("output.dat", "a");

    char *commandLine = (char *) malloc(MAX_CMD_LINE * sizeof(char));
    int x;

    if (input == NULL) {
        exit(1);
    } else {
        while (!feof(input)) {
            fscanf(input, "%s", commandLine);
            getc(input);
            if (strcmp(commandLine, "AF") == 0) {
                fscanf(input, "%d", &x);
                getc(input);
                AF(x);
            }
            if (strcmp(commandLine, "AL") == 0) {
                fscanf(input, "%d", &x);
                getc(input);
                AL(x);
            }
            if (strcmp(commandLine, "DF") == 0) {
                DF();
            }
            if (strcmp(commandLine, "DL") == 0) {
                DL();
            }
            if (strcmp(commandLine, "DOOM_THE_LIST") == 0) {
                DOOM_THE_LIST();
            }
            if (strcmp(commandLine, "DE") == 0) {
                fscanf(input, "%d", &x);
                getc(input);
                DE(x);
            }
            if (strcmp(commandLine, "PRINT_F") == 0) {
                fscanf(input, "%d", &x);
                getc(input);
                PRINT_F(x);
            }
            if (strcmp(commandLine, "PRINT_L") == 0) {
                fscanf(input, "%d", &x);
                getc(input);
                PRINT_L(x);
            }
            if (strcmp(commandLine, "PRINT_ALL") == 0) {
                PRINT_ALL();
            }
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}

void AF(int x){
    if(first == NULL){
        first = (Node *)malloc(sizeof(Node));
        first->data = x;
        first->next = NULL;
        last = first;
    }
    else{
        Node * newNode = (Node *)malloc(sizeof(Node));
        newNode->data = x;
        newNode->next = first;
        first = newNode;
    }

}
void AL(int x){
    if(last == NULL){
        last = (Node *)malloc(sizeof(Node));
        last->data = x;
        last->next = NULL;
        first = last;
    }
    else{
        Node * newNode = (Node *)malloc(sizeof(Node));
        newNode->data = x;
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
    }

}
void DF(){
    Node * currentNode = first;
    if(currentNode == NULL)
        return;
    first = first->next;
    free(currentNode);
}
void DL(){
    Node * currentNode = first;
    if(currentNode == NULL)
        return;
    if(first == last){
        free(first);
        first = NULL;
        last = NULL;
        return;
    }
    while(currentNode->next != NULL){
        last = currentNode;
        currentNode = currentNode->next;
    }
    free(last->next);
    last->next = NULL;
}
void DOOM_THE_LIST(){
    Node * currentNode;
    while(first != NULL){
        currentNode = first;
        first = first->next;
        free(currentNode);
    }
    last = NULL;
}
void DE(int x){
    Node * currentNode = first;
    Node * previousNode = first;
    while(currentNode != NULL){
        if(currentNode->data == x){
            if(currentNode == first){
                first = first->next;
            }
            else if(currentNode == last){
                last = previousNode;
                last->next = NULL;
            }
            else{
                previousNode->next = currentNode->next;
            }
            previousNode = currentNode;
            currentNode = currentNode->next;
            free(previousNode);
            previousNode = currentNode;
        }
        else{
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}
void PRINT_ALL(){
    Node * currentNode = first;
    while(currentNode){
        fprintf(output,"%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    fprintf(output,"\n");
}
void PRINT_F(int x){
    Node * currentNode = first;
    while(currentNode && x){
        fprintf(output,"%d ", currentNode->data);
        currentNode = currentNode->next;
        x--;
    }
    fprintf(output,"\n");
}
void PRINT_L(int x){
    int noOfNodes = 0;
    Node * currentNode = first;
    while(currentNode){
        noOfNodes++;
        currentNode = currentNode->next;
    }
    if(x >= noOfNodes){
        PRINT_ALL();
    }
    else{
        int noOfDiscardedNodes = noOfNodes - x;
        currentNode = first;
        while(noOfDiscardedNodes){
            currentNode = currentNode->next;
            noOfDiscardedNodes--;
        }
        while(currentNode){
            fprintf(output,"%d ",currentNode->data);
            currentNode = currentNode->next;
        }
        fprintf(output,"\n");
    }
}