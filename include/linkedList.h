#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdint.h>
#include <stdbool.h>

typedef struct node {
	uint8_t data;
	struct node* next;
}Node;

bool search(Node* list, uint8_t target);
void printList(Node* list);

void addFirst(Node* list, uint8_t data);
void addLast(Node* list, uint8_t data);

void delFirst(Node* list);
void delLast(Node* list);

void clear(Node* list);
#endif /*linkedList.h*/
