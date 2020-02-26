#include "head.h"


int main()
{
    initializeSll();


    for(int i=1; i<11; i++)
    {
        addElement(i);
    }

    for(int i=1; i<11; i++)
    {
        addElement(i);
    }


    for(int i=1; i<11; i++)
    {
        addElement(i);
    }

    printSllData();

    removeElement(1);
    removeElement(10);

    printSllData();

    removeAll();

    printSllData();

    return 0;
}
