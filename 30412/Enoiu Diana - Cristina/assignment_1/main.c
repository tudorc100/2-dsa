#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
#include "sll.h"
void initialize() {
    command = (char *)malloc(100 * sizeof(char));
    fp = fopen("../input.txt","r");
}
int main() {
    initialize();
    initializeSll();
    while(fscanf(fp,"%s",command)!=EOF) {
        if(strcmp(command,"AF")==0) {
            int element;
            fscanf(fp,"%d",&element);
            addFirst(element);
        }
    }
    printSll();
    return 0;
}