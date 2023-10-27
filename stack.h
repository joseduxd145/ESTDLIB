#ifndef ESTDLIB_STACK
#define ESTDLIB_STACK

typedef struct stack stack;

stack *ESTDLIB_newStack(int ic);
int ESTDLIB_dropStack(stack *st);
int ESTDLIB_push(stack *st, void *data);
void *ESTDLIB_pop(stack *st);
int ESTDLIB_isEmpty(stack *st);
int ESTDLIB_isFull(stack *st);
void *ESTDLIB_top(stack *st);
int ESTDLIB_getCapacity(stack *ll);
int ESTDLIB_setCapacity(stack *st, int c);

#endif
