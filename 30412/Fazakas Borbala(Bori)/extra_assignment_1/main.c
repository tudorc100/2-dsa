#include <stdio.h>
#include <stdlib.h>
#include "bunker.h"
#include "country.h"
#include "countries.h"

#define FILE_ERR_CODE 1
#define FILE_ERR_MESS "Error opening file"

FILE* openFile(char* name, char* mode)
{
    FILE* newFile = fopen(name, mode);
    if(newFile==NULL)
    {
        perror(FILE_ERR_MESS);
        exit(FILE_ERR_CODE);
    }
    return newFile;
}

int main() {
    FILE* inFile = openFile("input.dat", "r");
    FILE* outFile = openFile("output.dat", "w");

    Bunker myBunker = createBunker();
    readDataOfBunker(&myBunker, inFile);
    allCountries myCountries = createAllCountries();
    readDataOfAllCountries(&myCountries, inFile);

    attackWhileNeeded(&myCountries, &myBunker);
    if(isDefeated(&myBunker))
    {
        printf("The bunker was defeated\n");
        printf("the last hit was done by %s\n", myCountries.countryWithHBlow.name);
    }
    else printf("The bunker won\n");

    return 0;
}