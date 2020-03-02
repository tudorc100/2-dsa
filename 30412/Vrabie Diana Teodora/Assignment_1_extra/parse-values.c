//
// Created by diana on 02/03/2020.
//

#include "parse-values.h"
#include <stdlib.h>

int isTyrantDead() {
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
    int totalHitPoints = 0;
    Sentinel *sentinel = firstSentinel;
    while (sentinel != NULL) {
        totalHitPoints += sentinel->hitPoints;
        sentinel = sentinel->next;
    }

    if (totalDamage>=totalHitPoints) return 1;
    return 0;
}
