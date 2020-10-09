#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "s_linkedList.h"

int main(void) {
    printf("Create a new singly linked list\n");
	Node* list = malloc(sizeof(Node));
	printf("list head at %p", list);

	/*add first*/
	printf(">>Add first\n");
	for(uint8_t i = 0; i < 20; i++) {
		addFirst(list, i);
	}
	printList(list);

	/*add last*/
	printf(">>Add last\n");
	for(uint8_t i = 0; i < 20; i++) {
		addLast(list, i);
	}
	printList(list);

	/*addAt(index)*/
	for(uint8_t i = 0; i < 20; i++) {
	printf(">>Add at (index = 10)\n");
		addAt(list, 10, 100);
	}
	printList(list);

	/*del first*/
	printf(">>Del first\n");
	for(uint8_t i = 0; i < 10; i++) {
		delFirst(list);
	}
	printList(list);

	/*del last*/
	printf(">>Del last\n");
	for(uint8_t i = 0; i < 10; i++) {
		delLast(list);
	}
	printList(list);

	/*delAt(index)*/
	for(uint8_t i = 0; i < 20; i++) {
	printf(">>Del at (index = 10)\n");
		delAt(list, 10);
	}
	printList(list);

	clear(list);
	printList(list);
    free(list);
	return 0;
}
