#ifndef ESTDLIB_STACK
#define ESTDLIB_STACK

typedef struct stack stack;

stack *newStack(int ic);
int dropStack(stack *st);
int push(stack *st, void *data);
void *pop(stack *st);
int isEmpty(stack *st);
int isFull(stack *st);
void *top(stack *st);
int ensureCapacity(stack *st, int c);

#endif
