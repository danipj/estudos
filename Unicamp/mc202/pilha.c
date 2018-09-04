#include <stdlib.h>

#include "pilha.h"

struct Stack {
	int height;
	int maxHeight;
	void **buffer;
};

Stack * stackCreate(int maxHeight) {
	Stack *stack = malloc(sizeof(Stack));

	stack->height = 0;
	stack->maxHeight = maxHeight;
	stack->buffer = malloc(stack->maxHeight * sizeof(void *));

	return stack;
}

void stackPush(Stack *stack, void *item) {
	if (stack->height == stack->maxHeight - 1) {
		stack->maxHeight *= 2;
		stack->buffer = realloc(stack->buffer, stack->maxHeight * sizeof(void *));
	}

	stack->buffer[stack->height++] = item;
}

void * stackPop(Stack *stack) {
	if (stack->height == 0) {
		return NULL;
	}

	return stack->buffer[--stack->height];
}

bool stackIsEmpty(Stack * stack) {
	return stack->height == 0;
}

void freeStackItems(Stack * stack) {
	while (stack->height > 0) {
		free(stackPop(stack));
	}
}
