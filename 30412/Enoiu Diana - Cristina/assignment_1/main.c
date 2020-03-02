#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
#include "sll.h"
void initialize() {
    command = (char *)malloc(100 * sizeof(char));
    fp = fopen("../input.txt","r");
}
int readElement() {
    fscanf(fp,"%d",&element);
    return element;
}
int main() {
    initialize();
    initializeSll();
    while(fscanf(fp,"%s",command)!=EOF) {
        if(strcmp(command,"AF")==0) {
            element = readElement();
            AF(element);
            PRINT_ALL();
        }
        if(strcmp(command,"AL")==0) {
            element = readElement();
            AL(element);
            PRINT_ALL();
        }
        if(strcmp(command,"DF")==0) {
            DF();
            PRINT_ALL();
        }
        if(strcmp(command,"DL")==0) {
            DL();
            PRINT_ALL();
        }
    }

    return 0;
}