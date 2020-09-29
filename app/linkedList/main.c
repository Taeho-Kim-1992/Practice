#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "linkedList.h"

int main(void) {
	Node* linkedList = malloc(sizeof(Node*));

    printf("addFirst\n");
	addFirst(linkedList, 10);
	addFirst(linkedList, 20);
	addFirst(linkedList, 30);
	addFirst(linkedList, 40);
	addFirst(linkedList, 50);

	printList(linkedList);

    search(linkedList, 20);

    printf("addLast\n");
    addLast(linkedList, 20);
    addLast(linkedList, 30);
    addLast(linkedList, 40);
    addLast(linkedList, 20);

	printList(linkedList);
    
    printf("delFirst\n");
	delFirst(linkedList);
	delFirst(linkedList);
	delFirst(linkedList);
	delFirst(linkedList);

	printList(linkedList);

    printf("delLast\n");
	delLast(linkedList);
	delLast(linkedList);
	delLast(linkedList);

	printList(linkedList);
    
    printf("clear\n");
    clear(linkedList);
	printList(linkedList);

	delLast(linkedList);
	printList(linkedList);
	return 0;
}
