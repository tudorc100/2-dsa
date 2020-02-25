#include <stdio.h>
#include "list.h"

int main() {
    list myList = createList();
    for(int i=1; i<=10; i++)
    {
        if(i%3==0)
        {
            addFirst(&myList, i);
        }
        else
        {
            addLast(&myList, i);
        }
        printAll(&myList);
    }
    printAll(&myList);

    for(int i=2; i<=14; i+=4)
    {
        deleteValue(&myList, i);
        printAll(&myList);
    }

    deleteLast(&myList);
    printAll(&myList);
    deleteFirst(&myList);
    printAll(&myList);

    printFirstX(&myList, 3);
    printFirstX(&myList, 10);

    printLastX(&myList, 3);
    printLastX(&myList, 10);

    deleteAll(&myList);
    printAll(&myList);
    addLast(&myList, 10);
    printAll(&myList);
    return 0;
}