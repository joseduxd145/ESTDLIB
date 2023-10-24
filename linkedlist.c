#include "linkedlist.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct linkedList
{
    node *head;
    node *iterator;
    size_t elements;
}linkedList;

typedef struct node
{
    void *data;
    node *next;
}node;

linkedList *newLinkedList(void)
{
    linkedList *ll = malloc(sizeof(linkedList));

    if(!ll)
    {
        return NULL;
    }

    ll->head = NULL;
    ll ->iterator = NULL;
    ll->elements = 0;

    return ll;
}

void dropLinkedList(linkedList *ll)
{
    ll->iterator = ll->head;

    node *tmp = NULL;

    while(ll->iterator)
    {
        tmp = ll->iterator->next;
        memset(ll->iterator, 0, sizeof(node));
        free(ll->iterator);
        ll->iterator = tmp;
    }

    memset(ll, 0, sizeof(linkedList));
    free(ll);
}

int insertElement(linkedList *ll, void *data)
{
    node *element = malloc(sizeof(node));
    if(!element)
    {
        return 1;
    }

    element->data = data;
    element->next = NULL;

    ll->iterator = ll->head;

    if(ll->iterator)
    {
        while(ll->iterator->next != NULL)
        {
            ll->iterator = ll->iterator->next;
        }

        ll->iterator->next = element;
    }
    else
    {
        ll->head = element;
    }
    
    ll->iterator = ll->head;
    ll->elements++;

    return 0;
}

int insertHead(linkedList *ll, void *data)
{
    node *element = malloc(sizeof(node));
    if(!element)
    {
        return 1;
    }

    element->data = data;
    element->next = ll->head;

    ll->head = element;
    ll->elements++;
    ll->iterator = ll->head;

    return 0;
}

void *getNext(linkedList *ll)
{
    if(!ll->iterator)
    {
        return NULL;
    }

    void *data = ll->iterator->data;
    ll->iterator = ll->iterator->next;

    return data;
}

void resetIterator(linkedList *ll)
{
    ll->iterator = ll->head;
}
