#include "hashmap.h"
#include "linkedlist.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct hashMap
{
    linkedList **data;
    size_t size;
}hashMap;

typedef struct keyValue
{
    size_t key;
    void *value;
}keyValue;

unsigned int hashFunction(const char *input)
{
    size_t output = 0x555555;
    const int caracter = 13;
    const int mod = 31;

    size_t inputSize = strlen(input);

    for(size_t i = 0; i < inputSize; i++)
    {
        output += *input++;
        output = ((output << caracter) | (output >> (mod - caracter)));
    }

    
    return output % 100000000;
}

hashMap *ESTDLIB_newHashMap(size_t size)
{
    if(size < 1)
    {
        return NULL;
    }

    hashMap *hm = malloc(sizeof(hashMap));
    if(!hm)
    {
        return NULL;
    }

    hm->data = malloc(size * sizeof(linkedList));
    if(!hm->data)
    {
        free(hm);
        return NULL;
    }

    for(size_t i = 0; i < size; i++)
    {
        hm->data[i] = ESTDLIB_newLinkedList();
        if(!hm->data[i])
        {
            for(size_t j = 0; j < size; j++)
                ESTDLIB_dropLinkedList(hm->data[i]);

            free(hm->data);
            free(hm);
            return NULL;
        }
    }

    hm->size = size;

    return hm;
}

void ESTDLIB_dropHashMap(hashMap *hm, int flags)
{

}
