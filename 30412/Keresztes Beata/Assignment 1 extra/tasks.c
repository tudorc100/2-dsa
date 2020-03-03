//
// Created by q on 3/2/2020.
//

#include "tasks.h"

int findMaxNoOfWaves(int M, RebelT * countries) {

    int Max=0;
    for(int i=0;i<M;i++) {
        int max=0;
        WaveT * temp=countries[i].first;
        while(temp) {
            max++;
            temp=temp->nextWave;
        }
        if(max>Max) {
            Max=max;
        }
    }
    return Max;
}
void resultOfAttack(FILE *fp, int M, RebelT * countries, int resistance) {

    WaveT ** attacks = (WaveT **) malloc(M * sizeof(WaveT *));
    for (int i = 0; i < M; i++) {
        attacks[i] = (WaveT *)malloc(sizeof(WaveT));
        attacks[i] = countries[i].first;
    }

    int maxNoOfWaves = findMaxNoOfWaves(M, countries);

    int amountOfDamage = 0, finalBlowIndex = -1;
    bool victory = false;

    for (int k = 0; k < maxNoOfWaves && !victory; k++) {

        for (int i = 0; i < M && !victory; i++) {
            if (attacks[i] != NULL) {
                amountOfDamage += attacks[i]->damage;
                attacks[i] = attacks[i]->nextWave;
            }
            if (amountOfDamage >= resistance) {
                finalBlowIndex = i;
                victory = true;
            }
        }
    }

    if (victory == true) {
        fprintf(fp,"The tyrant was killed!\n");
    } else {
        fprintf(fp,"The tyrant could not be killed!\n");
    }
    if (finalBlowIndex != -1) {
        fprintf(fp,"The last hit was done by: %s\n", countries[finalBlowIndex].name);
    } else {
        fprintf(fp,"No country had the hitting blow.\n");
    }

    for (int i = 0; i < M; i++) {
        free(attacks[i]);
    }
    free(attacks);
}
int findWeakest(int M, RebelT * countries) {

    int weakestIndex = -1, minPower = INT_MAX;
    for (int i = 0; i < M; i++) {
        int power = 0;
        WaveT *temp = countries[i].first;
        while (temp != NULL) {
            power += temp->damage;
            temp = temp->nextWave;
        }
        if (power < minPower) {
            minPower = power;
            weakestIndex = i;
        }
    }
    return weakestIndex;
}
int findStrongest(int M, RebelT * countries, int * maxPower) {

    int strongestIndex = -1; * maxPower = 0;
    for (int i = 0; i < M; i++) {
        int power = 0;
        WaveT * temp = countries[i].first;
        while (temp != NULL) {
            power += temp->damage;
            temp = temp->nextWave;
        }
        if (power > (* maxPower)) {
            * maxPower = power;
            strongestIndex = i;
        }
    }
    return strongestIndex;
}

void defeatAlone(FILE *fp, int N, int * sentinels, int resistance, RebelT strongestCountry, int maxPower) {

    if(maxPower >= resistance) {
        fprintf(fp,"%s could have won alone\n",strongestCountry.name);
    }
    else {
        fprintf(fp,"No countries could have defeated all the sentinels.\n");
        int remainingPower = maxPower, lastDefeated = -1;
        bool endOfAttack = false;
        for(int i=0; i<N && !endOfAttack; i++) {
            if(remainingPower >= sentinels[i]) {
                remainingPower -= sentinels[i];
            }
            else {
                lastDefeated = i;
                endOfAttack = true;
            }
        }
        fprintf(fp,"%s could have brought down the first %d sentinels and would"
                   " have had chipped off %d life points from sentinels %d.\n",
                strongestCountry.name, lastDefeated, remainingPower, lastDefeated+1);
    }

}