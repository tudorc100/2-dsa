//
// Created by q on 3/2/2020.
//

#ifndef ASSIGNMENT_1_EXTRA_GET_DATA_H
#define ASSIGNMENT_1_EXTRA_GET_DATA_H

#endif //ASSIGNMENT_1_EXTRA_GET_DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define FILE_ERROR_MESS "File was not found."

typedef struct _wave {
    int damage;
    struct _wave * nextWave;
}WaveT;

typedef struct _rebels {
    char * name;
    WaveT * first, * last;
}RebelT;

FILE * openFile(char * name, char * mode);
void initializeCountry(RebelT * c);
void addWave(RebelT *country, int x);
int * getEnemyData(FILE *fp, int *N, int *resistance);
RebelT * getRebelsData(FILE *fp, int *M);

