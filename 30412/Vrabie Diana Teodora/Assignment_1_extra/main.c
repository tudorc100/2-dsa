#include <stdio.h>
#include <stdlib.h>
#include "country.h"
#include "wave.h"
#include "sentinel.h"

#define INPUT_PATH "../input.dat"
#define OUTPUT_PATH "../output.dat"

FILE *inputFile;
FILE *outputFile;

int main() {
    inputFile = fopen(INPUT_PATH, "r");
    outputFile = fopen(OUTPUT_PATH, "w");

    int nrOfSentinels = 0, nrOfCountries = 0;

    char read[20], *p;

    fscanf(inputFile, "%s", read);
    nrOfSentinels = strtol(read, &p, 10);

    for (int i = 0; i < nrOfSentinels; ++i) {
        fscanf(inputFile, "%s", read);
        int data = 0;
        data = strtol(read, &p, 10);
        addSentinel(data);
    }

    Sentinel *cursor = firstSentinel;
    while (cursor != NULL) {
        printf("%d ", cursor->hitPoints);
        cursor = cursor->next;
    }

    return 0;
}