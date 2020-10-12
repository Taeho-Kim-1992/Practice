#ifndef __NODE_STACK_H__
#define __NODE_STACK_H__

#include <stdint.h>
#include <stdbool.h>

typedef struct Stack {
	uint8_t data;
	struct Stack* next;
}Stack;

void printStack(Stack* head);
void push(Stack* head, uint8_t data);
void pop(Stack* head);
uint8_t peek(Stack* head);
bool search(Stack* head, uint8_t target);

#endif /* Stack.h */
