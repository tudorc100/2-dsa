//
// Created by Bori on 2/26/2020.
//

#include "country.h"
#include <stdlib.h>

Country createCountry()
{
    Country newCountry;
    newCountry.name = (char*) malloc(sizeof(char)*MAX_NAME_LENGTH);
    newCountry.waves = createList();
}

void readDataOfCountry(Country* myCountry, FILE* inFile)
{
    fscanf(inFile, "%s", myCountry->name);
    
}