#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

#include "node_stack.h"

int main(void) {
	Stack* head = (Stack*)malloc(sizeof(Stack));
	printf("Stack created\n");
	printf("Curr[%p] Next[%p]\n",head, head->next);
	head->next = NULL;
//	pop(head);
//	printStack(head);

	push(head, 10);
	printStack(head);

	push(head, 20);
	push(head, 30);
	printStack(head);

	for(uint8_t i = 0; i < 10; i++) push(head, i * 10);
	printStack(head);

	printf("peek data [%d]\n", peek(head));
	printf("searching node data = %d\n", 50);
	search(head, 50) ? printf("True\n") : printf("False\n");

	printf("searching node data = %d\n", 200);
	search(head, 200) ? printf("True\n") : printf("False\n");

	return 0;
}
