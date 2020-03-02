//
// Created by diana on 02/03/2020.
//

#include "parse-values.h"
#include <stdlib.h>

#define TYRANT_HP 1

int countTotalDamage();

int countTotalHitPoints();

int isTyrantDead() {
    int totalDamage = countTotalDamage();
    int totalHitPoints = countTotalHitPoints();
    if (totalDamage >= totalHitPoints) return 1;
    return 0;
}

int countTotalHitPoints() {
    int totalHP = 0;
    Sentinel *sentinel = firstSentinel;
    while (sentinel != NULL) {
        totalHP += sentinel->hitPoints;
        sentinel = sentinel->next;
    }
    return totalHP + TYRANT_HP;
}

char *lastHitCountry() {
    Country *country = firstCountry;
    int wavesToSkip = 0;
    int totalHitPoints = countTotalHitPoints();
    while (1) {
        Wave *wave = country->firstWave;
        for (int i = 0; i < wavesToSkip; ++i) {
            if (wave != NULL) {
                wave = wave->next;
            }
        }
        if (wave != NULL) {
            totalHitPoints -= wave->damage;
            if (totalHitPoints <= 0) {
                //isThisHitTheLast = 1;
                return country->name;
            }
        }
        if (country == lastCountry) {
            wavesToSkip++;
            country = firstCountry;
        } else {
            country = country->next;
        }
    }
}

Country *strongestCountry() {
    Country *country = firstCountry;
    Country *strongestCountry = firstCountry;
    int maxMight = 0;
    while (country != NULL) {
        Wave *wave = country->firstWave;
        int might = 0;
        while (wave != NULL) {
            might += wave->damage;
            wave = wave->next;
        }
        if (might >= maxMight) {
            maxMight = might;
            strongestCountry = country;
        }
        country = country->next;
    }
    return strongestCountry;
}

int countTotalDamage() {
    int totalDamage = 0;
    Country *country = firstCountry;
    while (country != NULL) {
        Wave *wave = country->firstWave;
        while (wave != NULL) {
            totalDamage += wave->damage;
            wave = wave->next;
        }
        country = country->next;
    }
    return totalDamage;
}

