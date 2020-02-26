//
// Created by Bori on 2/26/2020.
//

#ifndef EXTRA_ASSIGNMENT_1_COUNTRY_H
#define EXTRA_ASSIGNMENT_1_COUNTRY_H

#include "list.h"

#define MAX_NAME_LENGTH 100

typedef struct
{
    char* name;
    list waves;
}Country;

Country createCountry();
void readDataOfCountry(Country* myCountry, FILE* inFile);
void attackWithNextWave();
int power(Country* thisCountry);
//int canDefeatAlone(Country* country, )


#endif //EXTRA_ASSIGNMENT_1_COUNTRY_H
