#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "d_linkedList.h"

int main(void) {
    Node* list = (Node*)malloc(sizeof(Node*));
	list->prev = NULL;
	list->next = NULL;
	printf("created node prev(%p) curr(%p) next(%p)\n", list->prev, list, list->next);

	/*add first*/
	for(int i = 0; i < 20; i++)
		addFirst(list, i);
    printList(list);

	/*add last*/
	for(int i = 0; i < 20; i++)
		addLast(list, 100+i);
    printList(list);

	/*del first*/
	for(int i = 0; i < 10; i++)
		delFirst(list);
	printList(list);

	/*del last*/
	for(int i = 0; i < 10; i++)
		delLast(list);
	printList(list);

	/*search*/
	printf("Search data %d\n", 10);
	search(list, 10) ? printf("True\n"): printf("False\n");

	printf("Search data %d\n", 12);
	search(list, 12) ? printf("True\n"): printf("False\n");

	printf("Search data %d\n", 9);
	search(list, 9) ? printf("True\n"): printf("False\n");

	/*add At(index)*/
	for(uint8_t i = 0; i < 3; i ++) {
	printf("Add at(index == 3) data of %d\n", 150 + i);
		addAt(list, 3, 150 + i);
	}
	printList(list);

	/*del At(index)*/
	for(uint8_t i = 0; i < 3; i ++) {
		printf("Del at(index == 3) \n");
		delAt(list, 3);
	}
	printList(list);

    return 0;
}

