#include <stdio.h>
#include "head.h"
#include <string.h>

int main() {
    FILE *f = fopen("../input.dat", "r");
    FILE *g = fopen("../output.dat", "w");
    List sentinels = createList();

    int noOfSentinels;
    fscanf(f, "%d", &noOfSentinels);

    for (int i = 0; i < noOfSentinels; i++) {
        int sentinelLife;
        fscanf(f, "%d", &sentinelLife);
        addElementLast(sentinelLife, &sentinels);
    }

    int noOfCountries;
    char aux[MAX_LINE];
    fgetc(f);

    fgets(aux, MAX_LINE, f);
    sscanf(aux, "%d", &noOfCountries);
    Country *countries = (Country *) malloc(noOfCountries * sizeof(Country));

    for (int i = 0; i < noOfCountries; i++) {
        countries[i].totalDamage = 0;
        fgets(aux, MAX_LINE, f);
        char *pch = strtok(aux, " ");
        sscanf(pch, "%s", countries[i].name);
        pch = strtok(NULL, " ");
        countries[i].waves = createList();
        while (pch != NULL) {
            int wave;
            sscanf(pch, "%d", &wave);
            addElementLast(wave, &countries[i].waves);
            pch = strtok(NULL, " ");
        }
    }
    Node *currentNode;
    for (int i = 0; i < noOfCountries; i++) {
        countries[i].totalPower = countries[i].totalDamage;
        currentNode = countries[i].waves.first;
        while (currentNode != NULL) {
            countries[i].totalPower = countries[i].totalPower + currentNode->data;
            currentNode = currentNode->next;
        }
    }
    int totalSentinelPower = 0;
    currentNode = sentinels.first;
    while (currentNode != NULL) {
        totalSentinelPower = totalSentinelPower + currentNode->data;
        currentNode = currentNode->next;
    }
    int successfulCountries = 0;
    for (int i = 0; i < noOfCountries; i++) {
        if (countries[i].totalPower > totalSentinelPower) {
            fprintf(g, "%s could have defeated all the sentinels\n", countries[i].name);
            successfulCountries++;
        }
    }
    if (successfulCountries == 0) {
        fprintf(g, "No country could have defeated all the sentinels.\n");

        for (int i = 0; i < noOfCountries; i++) {
            countries[i].totalPower = countries[i].totalDamage;
            currentNode = countries[i].waves.first;
            while (currentNode != NULL) {
                countries[i].totalPower = countries[i].totalPower + currentNode->data;
                currentNode = currentNode->next;
            }
        }
        int mostPowerfulCountryIndex = 0;
        for (int i = 1; i < noOfCountries; i++) {
            if (countries[i].totalPower > countries[mostPowerfulCountryIndex].totalPower)
                mostPowerfulCountryIndex = i;
        }
        int noOfDestroyedSentinels = 0;
        currentNode = sentinels.first;
        int totalDamage = countries[mostPowerfulCountryIndex].totalPower;

        while (currentNode->data <= totalDamage) {
            totalDamage = totalDamage - currentNode->data;
            currentNode = currentNode->next;
            noOfDestroyedSentinels++;
        }
        fprintf(g,
                "%s could have brought down the first %d sentinels and would have had chipped off %d life points from sentinel %d.\n",
                countries[mostPowerfulCountryIndex].name, noOfDestroyedSentinels, totalDamage,
                noOfDestroyedSentinels + 1);
    }
    currentNode = countries[0].waves.first;
    int currentCountry = 0;
    Node *currentSentinel = sentinels.first;
    while (currentSentinel != NULL && currentNode != NULL) {
        currentSentinel->data = currentSentinel->data - currentNode->data;
        if (currentSentinel->data < 0) {
            countries[currentCountry].totalDamage =
                    countries[currentCountry].totalDamage + currentSentinel->data + currentNode->data;
            currentNode->data = abs(currentSentinel->data);
            currentSentinel = currentSentinel->next;
        } else if (currentSentinel->data == 0) {
            countries[currentCountry].totalDamage = countries[currentCountry].totalDamage + currentNode->data;
            deleteFirst(&countries[currentCountry].waves);
            int noOfIterations = 0;
            do {
                if (currentCountry < noOfCountries - 1)
                    currentCountry++;
                else if (currentCountry == noOfCountries - 1)
                    currentCountry = 0;
                currentNode = countries[currentCountry].waves.first;
                noOfIterations++;
            } while (countries[currentCountry].waves.first == NULL && noOfIterations <= noOfCountries);
            currentSentinel = currentSentinel->next;
        } else if (currentSentinel->data > 0) {
            countries[currentCountry].totalDamage = countries[currentCountry].totalDamage + currentNode->data;
            deleteFirst(&countries[currentCountry].waves);
            int noOfIterations = 0;
            do {
                if (currentCountry < noOfCountries - 1)
                    currentCountry++;
                else if (currentCountry == noOfCountries - 1)
                    currentCountry = 0;
                currentNode = countries[currentCountry].waves.first;
                noOfIterations++;
            } while (countries[currentCountry].waves.first == NULL && noOfIterations < noOfCountries);
        }
    }
    if (currentSentinel == NULL && currentNode != NULL && currentNode->data >= 1)
        fprintf(g, "The tyrant was killed!\nThe last hit was done by %s!\n", countries[currentCountry].name);
    else fprintf(g,"The tyrant was not killed\n");
    int strongestIndex = 0;
    for (int i = 1; i < noOfCountries; i++)
        if (countries[i].totalDamage > countries[strongestIndex].totalDamage)
            strongestIndex = i;
    int weakestIndex = 0;
    for (int i = 1; i < noOfCountries; i++)
        if (countries[i].totalDamage < countries[weakestIndex].totalDamage)
            weakestIndex = i;
    fprintf(g, "The strongest country was: %s\n", countries[strongestIndex].name);
    fprintf(g, "The weakest country was: %s\n", countries[weakestIndex].name);

    return 0;
}
