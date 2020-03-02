//
// Created by q on 3/2/2020.
//

#ifndef ASSIGNMENT_1_EXTRA_TASKS_H
#define ASSIGNMENT_1_EXTRA_TASKS_H

#endif //ASSIGNMENT_1_EXTRA_TASKS_H

#include "get_data.h"
#include "limits.h"
int findMaxNoOfWaves( int M, RebelT * countries);
void resultOfAttack(FILE *fp, int M, RebelT * countries, int resistance);
int findWeakest(int M, RebelT * countries);
int findStrongest(int M, RebelT * countries, int * maxPower);
void defeatAlone(FILE *fp, int N, int * sentinelsconst , int resistance, RebelT strongestCountry, int maxPower);
