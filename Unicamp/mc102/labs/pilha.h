#include <stdbool.h>

typedef struct Stack Stack;

Stack * stackCreate(int maxHeight);
void stackPush(Stack *stack, void *item);
void * stackPop(Stack *stack);
bool stackIsEmpty(Stack *stack);
void freeStackItems(Stack *stack);