#include "dictionary.h"
#include <stdlib.h>
#include <string.h>

#define DICTIONARY_SIZE 8

typedef struct dictionary
{
    char **key;     //Array de strings para almacenar las claves
    void **data;    //Array de punteros que almacenan los datos
    size_t size;    //Cantidad maxima de elementos
    bool freeAll;   //Determina si al llamar drop se asumira que hay que liberar los contenidos con free
}dictionary;

dictionary *newDictionary(bool freeOnDrop)
{
    dictionary *dd = malloc(sizeof(dictionary));
    if(!dd)
    {
        return NULL;
    }

    dd->key = malloc(DICTIONARY_SIZE * sizeof(char *));
    if(!dd->key)
    {
        free(dd);
        return NULL;
    }

    dd->data = malloc(DICTIONARY_SIZE * sizeof(void *));
    if(!dd->data)
    {
        free(dd->key);
        free(dd);
        return NULL;
    }

    for(int i = 0; i < DICTIONARY_SIZE; i++)
    {
        dd->key[i] = NULL;
        dd->data[i] = NULL;
    }

    dd->size = DICTIONARY_SIZE;
    dd->freeAll = freeOnDrop;

    return dd;
}

void dropDictionary(dictionary *dd)
{
    if(!dd)
    {
        return;
    }

    if(!dd->key || !dd->data)
    {
        return;
    }

    if(dd->freeAll)
    {
        for(int i = 0; i < dd->size; i++)
        {
            if(dd->key && dd->data)
            {
                free(dd->key[i]);
                free(dd->data[i]);
                dd->key[i] = NULL;
                dd->data[i] = NULL;
            }
        }
    }

    free(dd->key);
    free(dd->data);

    memset(dd, 0, sizeof(dictionary));

    free(dd);
}
