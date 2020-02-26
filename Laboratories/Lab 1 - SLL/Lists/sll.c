#include "head.h"

void initializeSll()
{
    first = NULL;
    last = NULL;
}

void addElement(int data)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->next = NULL;
        newElement->data = data;
        last = newElement;
    }
}

void removeElement(int data)
{
    NodeT * currentElement = first;
    NodeT * previousElement= first;
    while(currentElement != NULL)
    {
        if(currentElement->data == data)
        {
            if(currentElement == first)
            {
                first = first->next;
            }
            else if(currentElement == last)
            {
                last = previousElement;
                last->next = NULL;
            }
            else
            {
                previousElement->next = currentElement->next;
            }
            previousElement = currentElement;
            currentElement = currentElement->next;
            free(previousElement);
            previousElement = currentElement;
        }
        else
        {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }

    }
}

void printSllData()
{
    if(first == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        NodeT * currentElement = first;
        while(currentElement != NULL)
        {
            printf("%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        printf("\n");
    }

}

void removeAll()
{
    NodeT * currentElement = first;
    while(currentElement != NULL)
    {
        first = first->next;
        free(currentElement);
        currentElement = first;
    }
}

