#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "linkedList.h"

int main(void) {
	Node* linkedList = malloc(sizeof(Node*));
	linkedList->next = NULL;

	addFirst(linkedList, 10);
	addFirst(linkedList, 20);
	addFirst(linkedList, 30);
	addFirst(linkedList, 40);
	addFirst(linkedList, 50);

	printList(linkedList);

    addLast(linkedList, 20);
    addLast(linkedList, 30);
    addLast(linkedList, 40);
    addLast(linkedList, 20);
	printList(linkedList);
	return 0;
}
