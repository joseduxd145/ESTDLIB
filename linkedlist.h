#ifndef ESTDLIB_LINKEDLIST
#define ESTDLIB_LINKEDLIST

typedef struct linkedList linkedList;
typedef struct node node;

linkedList *newLinkedList(void);
void dropLinkedList(linkedList *ll);
int insertElement(linkedList *ll, void *data);
int insertHead(linkedList *ll, void *data);
void *getNext(linkedList *ll);
void resetIterator(linkedList *ll);

#endif
