#include <stdio.h>
#include <stdlib.h>
#include "bunker.h"
#include "country.h"

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
    FILE* outFile = openFile("outPut.dat", "w");

    Bunker myBunker = createBunker();



    return 0;
}