//
// Created by Bori on 2/25/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

list createList()
{
    list newList;
    newList.first = (node*) malloc(sizeof(node));
    newList.last = (node*) malloc(sizeof(node));
    return newList;
}

void addFirst(list myList, int value)
{
    node* newNode = createNodeWithNext(value, myList.first);
    myList.first = newNode;
}

void addLast(list myList, int value)
{
    node* newNode = createNode(value);
    myList.last->next = newNode;
    myList.last = newNode;
}

void deleteFirst(list myList)
{
    node* prevFirst = myList.first;
    myList.first = myList.first->next;
    free(prevFirst);
}

void deleteLast(list myList)
{
    node* lastButOne = myList.first;
    while(lastButOne->next->next!=NULL) lastButOne=lastButOne->next;
    free(myList.last);
    myList.last = lastButOne;
}

void deleteAll(list myList)
{
    node* curFirst;
    while(myList.first!=NULL)
    {
        curFirst = myList.first;
        myList.first = myList.first->next;
        free(curFirst);
    }
}

void deleteValue(list myList, int value)
{
    node* curNode = myList.first;
    node* prevNode = NULL;
    while(curNode!=NULL)
    {
        if(curNode->data==value) //remark that in all of the 3 cases prevNode is constant/it's value doesn't matter anymore
        {
            if(curNode==myList.first) //it remains null
            {
                deleteFirst(myList);
                curNode = myList.first;
            }
            else if(curNode==myList.last) //it doesn't matter anymore
            {
                deleteLast(myList);
                curNode = NULL;
            }
            else //it is constant
            {
                curNode = curNode->next;
                free(prevNode->next);
                prevNode->next = curNode;
            }
        }
        else
        {
            prevNode = curNode;
            curNode = curNode->next;
        }
    }
}

void printAll(list myList)
{
    printf("The list's current content is: ");
    node* curNode = myList.first;
    while(curNode!=NULL)
    {
        printf("%d ", curNode->data);
        curNode=curNode->next;
    }
    printf("\n");
}

void printFirstX(list myList, int x)
{
    printf("The list's first %d elements are: ", x);
    int countPrintedElem = 0;
    node* curNode = myList.first;
    while(countPrintedElem<x && curNode!=NULL)
    {
        printf("%d ", curNode->data);
        curNode=curNode->next;
        countPrintedElem++;
    }
    printf("\n");
}

static int printLastXNodesStartingFrom(node* start, int x) //returns the index of the current node numbered from the end of the list,
                                                            // and prints the current node if this index is <=x
{
    if(start==NULL) return 0;
    int curIndex = printLastXNodesStartingFrom(start->next, x);
    if(curIndex+1<x) printf("%d ", start->data);
    return curIndex+1;
}

void printLastX(list myList, int x)
{
    printf("The list's last %d elements are: ", x);
    printLastXNodesStartingFrom(myList.first, x);
    printf("\n");
}