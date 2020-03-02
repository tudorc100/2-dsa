//
// Created by diana on 01/03/2020.
//

#include "country.h"
#include <stdlib.h>
#include <string.h>

void initializeCountryList() {
    firstCountry = NULL;
    lastCountry = NULL;
}

void addCountry(char name[20]) {
    if (firstCountry == NULL) {
        firstCountry = (Country*) malloc(sizeof(Country));
        strcpy(firstCountry->name, name);

    }

}
