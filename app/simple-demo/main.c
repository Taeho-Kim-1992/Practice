#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node {
	uint8_t data;
	struct node* next;
}Node;

Node *head = NULL;

void printList() {
	Node *tmp = head;
	printf("List : [");
	while (tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("]\n");
}

int main(void) {
	head = (Node*)malloc(sizeof(Node*));
	head->data = 0;

	Node* node0 = (Node*)malloc(sizeof(Node));
	head->next = node0;
	node0->data = 10;

	Node* node1 = (Node*)malloc(sizeof(Node));
	node0->next = node1;
	node1->data = 20;

	Node* node2 = (Node*)malloc(sizeof(Node));
	node1->next = node2;
	node2->data = 30;

	Node* node3 = (Node*)malloc(sizeof(Node));
	node2->next = node3;
	node3->data = 40;

	node3->next = NULL;
	printList();
	return 0;
}
