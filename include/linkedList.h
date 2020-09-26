#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdint.h>

typedef struct node {
	uint8_t data;
	struct node* next;
}Node;

void printList(Node* list);

void addFirst(Node* list, uint8_t data);
void addLast(Node* list, uint8_t data);

void delFirst(Node* list);
void delLast(Node* list);

void search(Node* list);
void isEmpty(Node* list);


#endif /*linkedList.h*/
