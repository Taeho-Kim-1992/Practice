#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "s_linkedList.h"

int main(void) {
	Node* linkedList = malloc(sizeof(Node*));

	printf("addFirst 10\n");
	addFirst(linkedList, 10);

	printf("addFirst 20\n");
	addFirst(linkedList, 20);

	printf("addFirst 30\n");
	addFirst(linkedList, 30);

	printf("addFirst 40\n");
	addFirst(linkedList, 40);

	printf("addFirst 50\n");
	addFirst(linkedList, 50);

	printf("addAt 2, 100\n");
    addAt(linkedList, 2, 100);
	printList(linkedList);

	printf("Data at 2 is %d\n",getDataAt(linkedList, 2));
	printf("Data at 1 is %d\n",getDataAt(linkedList, 1));
	printf("Data at -1 is %d\n",getDataAt(linkedList, -1));
	printf("List size is %d\n", getSize(linkedList));

	printf("search 20 : ");
	search(linkedList, 20);

	printf("addLast 20\n");
	addLast(linkedList, 20);

	printf("addLast 30\n");
	addLast(linkedList, 30);

	printf("addLast 40\n");
	addLast(linkedList, 40);

	printf("addLast 20\n");
	addLast(linkedList, 20);

	printList(linkedList);

	printf("delAt(2)\n");
    delAt(linkedList,2);

	printList(linkedList);

	printf("delFirst\n");
	delFirst(linkedList);

	printf("delFirst\n");
	delFirst(linkedList);

	printf("delFirst\n");
	delFirst(linkedList);

	printf("delFirst\n");
	delFirst(linkedList);

	printList(linkedList);

	printf("delLast\n");
	delLast(linkedList);

	printf("delLast\n");
	delLast(linkedList);

	printf("delLast\n");
	delLast(linkedList);

	printList(linkedList);

	printf("clear\n");
	clear(linkedList);
	printList(linkedList);

	printf("Trying delete data in the emptylist\n");
	delLast(linkedList);
	printList(linkedList);
    free(linkedList);
	return 0;
}
