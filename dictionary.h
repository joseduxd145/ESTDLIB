#ifndef ESTDLIB_DICTIONARY
#define ESTDLIB_DICTIONARY

#include <stdbool.h>

typedef struct dictionary dictionary;

dictionary *newDictionary(bool freeOnDrop);
void dropDictionary(dictionary *dd);
int insertKeyPair(dictionary *dd, char *key, void *data);
void *getData(dictionary *dd, char *key);

#endif
