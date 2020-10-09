#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "d_linkedList.h"

int main(void) {
    Node* list = (Node*)malloc(sizeof(Node*));
    printList(list);


    for(int i = 0; i < 20; i++) addFirst(list, i);
    printList(list);

	addLast(list, 200);
	delFirst(list);
    printList(list);
	delFirst(list);
    printList(list);
	delFirst(list);
    printList(list);
    return 0;
}

