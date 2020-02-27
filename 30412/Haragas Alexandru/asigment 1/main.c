#include <stdio.h>
#include <string.h>
#include "node.h"


int main() {
    InitializeList();
    FILE *f = fopen("D:\\DSA\\2-dsa\\30412\\Haragas Alexandru\\asigment 1\\input.dat", "r");
    char *s = (char *) malloc(100 * sizeof(char));
    while (!feof(f)) {
        fscanf(f,"%s",s);
        int x;
        if (strncmp(s, "AF", 2) == 0) {
            fscanf(f,"%d",&x);
            AddFirst(x);
            continue;
        }
        if (strncmp(s, "AL", 2) == 0) {
            fscanf(f,"%d",&x);
            AddLast(x);
            continue;
        }
        if (strncmp(s, "DE", 2) == 0) {
            fscanf(f,"%d",&x);
            DeleteElem(x);
            continue;
        }
        if (strncmp(s, "PRINT_F", 7) == 0) {
            fscanf(f,"%d",&x);
            PrintFirst(x);
            continue;
        }
        if (strncmp(s, "PRINT_L", 7) == 0) {
            fscanf(f,"%d",&x);
            PrintLast(x);
            continue;
        }

        if (strncmp(s, "DF", 2) == 0) {
            DeleteFirst();
            continue;
        }
        if (strncmp(s, "DL", 2) == 0) {
            DeleteLast();
            continue;
        }
        if (strncmp(s, "DOOM_THE_LIST", 13) == 0) {
            DeleteList();
            continue;
        }
        if (strncmp(s, "PRINT_ALL", 9) == 0) {
            PrintList();
            continue;
        }

    }
    free(s);
    fclose(f);
    return 0;
}