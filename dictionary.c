#include "dictionary.h"
#include <stdlib.h>
#include <string.h>

#define DICTIONARY_SIZE 8

typedef struct dictionary
{
    char **key;     //Array de strings para almacenar las claves
    void **data;    //Array de punteros que almacenan los datos
    size_t pairs;   //Cantidad de pares
    size_t size;    //Cantidad maxima de elementos
    bool freeAll;   //Determina si al llamar drop se asumira que hay que liberar los contenidos con free
}dictionary;

//Funcion interna para expandir la memoria de un diccionario, duplica el size cada vez
int expandDictionary(dictionary *dd);

dictionary *newDictionary(bool freeOnDrop)
{
    dictionary *dd = malloc(sizeof(dictionary));
    if(!dd)
    {
        return NULL;
    }

    dd->key = malloc(DICTIONARY_SIZE * sizeof(char **));
    if(!dd->key)
    {
        free(dd);
        return NULL;
    }

    dd->data = malloc(DICTIONARY_SIZE * sizeof(void **));
    if(!dd->data)
    {
        free(dd->key);
        free(dd);
        return NULL;
    }

    for(size_t i = 0; i < DICTIONARY_SIZE; i++)
    {
        dd->key[i] = NULL;
        dd->data[i] = NULL;
    }

    dd->pairs = 0;
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
        for(size_t i = 0; i < dd->size; i++)
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

int insertKeyPair(dictionary *dd, char *key, void *data)
{
    if(!dd || !key || !data)
    {
        return 1;
    }

    if(!dd->key || !dd->data)
    {
        return 2;
    }

    if(dd->pairs >= dd->size)
    {
        if(expandDictionary(dd))
        {
            return 3;
        }
    }

    dd->key[dd->pairs] = key;
    dd->data[dd->pairs] = data;

    dd->pairs++;

    return 0;;
}

void *getData(dictionary *dd, char *key)
{
    if(!dd || !key)
    {
        return NULL;
    }

    if(!dd->key || !dd->data)
    {
        return NULL;
    }

    for(size_t i = 0; i < dd->size; i++)
    {
        if(dd->key[i] == key)
        {
            return dd->data;
        }
    }

    return NULL;
}

int expandDictionary(dictionary *dd)
{
    if(!dd)
    {
        return 1;
    }

    if(!dd->key || !dd->data)
    {
        return 2;
    }

    char **tmpKey;
    void **tmpData;
    size_t newSize = dd->size * 2;

    tmpKey = malloc(newSize * sizeof(char **));
    if(!tmpKey)
    {
        return 3;
    }

    tmpData = malloc(newSize * sizeof(void **));
    if(!tmpData)
    {
        free(tmpKey);
        return 4;
    }

    for(size_t i = 0; i < newSize; i++)
    {
        tmpKey[i] = NULL;
        tmpData[i] = NULL;
    }

    memcpy(tmpKey, dd->key, dd->size);
    memcpy(tmpData, dd->data, dd->size);

    dd->size = newSize;

    free(dd->key);
    free(dd->data);

    dd->key = tmpKey;
    dd->data = tmpData;

    tmpKey = NULL;
    tmpData = NULL;

    return 0;
}
