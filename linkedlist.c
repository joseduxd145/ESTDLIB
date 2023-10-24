#include "linkedlist.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct linkedList
{
    node *head;         //Nodo que representa la cabeza de la lista
    node *iterator;     //Nodo que permite iterar la lista
    size_t elements;    //Numero de elementos contenidos por la lista
}linkedList;

typedef struct node
{
    void *data;     //Puntero a los datos
    node *next;     //Puntero al siguiente nodo
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
    if(!ll)
    {
        return;
    }

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
    if(!ll || !data)
    {
        return 1;
    }

    node *element = malloc(sizeof(node));
    if(!element)
    {
        return 2;
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
    if(!ll || !data)
    {
        return 1;
    }

    node *element = malloc(sizeof(node));
    if(!element)
    {
        return 2;
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
    if(!ll)
    {
        return NULL;
    }

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
    if(!ll)
    {
        return;
    }

    ll->iterator = ll->head;
}

void *removeElement(linkedList *ll, void *data)
{
    if(!ll || !data)
    {
        return NULL;
    }

    ll->iterator = ll->head;
    node *tmp = ll->iterator;
    void *salida = NULL;

    while(ll->iterator->data != data && ll->iterator->next != NULL)
    {
        tmp = ll->iterator;
        ll->iterator = ll->iterator->next;
    }

    if(ll->iterator->data == data)
    {
        salida = ll->iterator->data;

        tmp->next = ll->iterator->next;

        free(ll->iterator);

        ll->elements--;
    }

    ll->iterator = ll->head;

    return salida;
}

unsigned long getElements(linkedList *ll)
{
    if(!ll)
    {
        return 0;
    }

    return ll->elements;
}