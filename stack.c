#include "stack.h"
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    void **data;
    int pointer;
    int capacity;
}stack;

stack *newStack(int ic)
{
    if(ic < 1)
    {
        return NULL;
    }

    stack *st = malloc(sizeof(stack));
    if(!st)
    {
        return NULL;
    }

    st->data = malloc(ic * sizeof(void *));
    if(!st->data)
    {
        free(st);
        return NULL;
    }

    st->pointer = 0;
    st ->capacity = ic;

    return st;
}

int dropStack(stack *st)
{
    if(!st)
    {
        return -1;
    }

    if(st->pointer > 0)
    {
        return st->pointer;
    }

    free(st->data);
    memset(st, 0, sizeof(stack));

    return 0;
}

int push(stack *st, void *data)
{
    if(!st || !data)
    {
        return 1;
    }

    if(!(st->pointer < st->capacity))
    {
        return 2;
    }

    st->data[st->pointer] = data;
    st->pointer++;

    return 0;
}

void *pop(stack *st)
{
    if(!st)
    {
        return NULL;
    }

    if(st->pointer < 1)
    {
        return NULL;
    }

    st->pointer--;
    return st->data[st->pointer];
}

int isEmpty(stack *st)
{
    if(!st)
    {
        return -1;
    }

    return st->pointer;
}

int isFull(stack *st)
{
    if(!st)
    {
        return -1;
    }

    if(st->pointer >= st->capacity)
    {
        return 1;
    }
    return 0;
}

void *top(stack *st)
{
    if(!st)
    {
        return NULL;
    }

    if(st->pointer < 1)
    {
        return NULL;
    }

    return st->data[st->pointer - 1];
}

int getCapacity(stack *ll)
{
    if(!ll)
    {
        return -1;
    }
    return ll->capacity;
}

int setCapacity(stack *st, int c)
{
    if(!st)
    {
        return -1;
    }

    if(c < st->pointer)
    {
        return -2;
    }

    if(c < st->pointer)
    {
        return 0;
    }

    void **tmpArray = malloc(c * sizeof(void*));
    if(!tmpArray)
    {
        return -3;
    }

    memcpy(tmpArray, st->data, st->capacity * sizeof(void*));

    free(st->data);
    st->data = tmpArray;
    st->capacity = c;

    return 0;
}
