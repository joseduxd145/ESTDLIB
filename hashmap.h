#ifndef ESTDLIB_HASHMAP
#define ESTDLIB_HASHMAP

#include <stdint.h>
#include <stdlib.h>

//Flags
#define ESTDLIB_HASHMAP_FREEVALUES (0x1)


typedef struct hashMap hashMap;
typedef struct keyValue keyValue;

unsigned int hashFunction(const char *data);
hashMap *ESTDLIB_newHashMap(size_t size);
void ESTDLIB_dropHashMap(hashMap *hm, int flags);

#endif
