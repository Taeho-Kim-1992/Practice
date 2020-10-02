#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "d_linkedList.h"

int main(void) {
    Node* list = (Node*)malloc(sizeof(Node*));

    addFirst(list, 5);
    addFirst(list, 4);
    addFirst(list, 3);
    addFirst(list, 2);
	addFirst(list, 1);
    printList(list);
    return 0;
}

