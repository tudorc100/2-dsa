//
// Created by Bori on 2/26/2020.
//

#include "bunker.h"

Bunker createBunker()
{
    Bunker newBunker;
    newBunker.sentinels = createList();
    newBunker.jimKongNuPower=1;
}

void readDataOfBunker(Bunker* myBunker, FILE* inFile)
{
    int noSentinels;
    fscanf(inFile, "%d", &noSentinels);
    int nextSentinelPower;
    for(int i=1; i<=noSentinels; i++)
    {
        fscanf(inFile, "%d", &nextSentinelPower);
        addLast(&myBunker->sentinels, nextSentinelPower);
    }
}