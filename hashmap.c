#include "hashmap.h"
#include "linkedlist.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct hashMap
{
    linkedList *data;
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
