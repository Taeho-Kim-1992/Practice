#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void printList(Node* list) {
	Node *tmp = list->next;
	printf("List : [");
	while(tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("]\n");
}

void addFirst(Node* list, uint8_t data) {
	Node* newNode = (Node*)malloc(sizeof(Node*));
	newNode->next = list->next;
	newNode->data = data;
	list->next = newNode;
}

void addLast(Node* list, uint8_t data) {
    Node* newNode = (Node*)malloc(sizeof(Node*));
    while(list->next != NULL)
        list = list->next;
    newNode->data = data;
    newNode->next = NULL;
    list->next = newNode;
}
