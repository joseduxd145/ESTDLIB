#include "dictionary.h"
#include <stdlib.h>

typedef struct dictionary
{
    char **key;
    void **data;
    size_t size;
}dictionary;
