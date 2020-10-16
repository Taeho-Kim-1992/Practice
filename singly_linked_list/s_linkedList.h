#ifndef __S_LINKEDLIST_H__
#define __S_LINKEDLIST_H__

#include <stdint.h>
#include <stdbool.h>

typedef struct node {
	uint8_t data;
	struct node* next;
}Node;

uint8_t getDataAt(Node* list, uint16_t index);
void printList(Node* list);
void addFirst(Node* list, uint8_t data);
void addLast(Node* list, uint8_t data);
void addAt(Node* list, uint16_t index, uint8_t data);
void delFirst(Node* list);
void delLast(Node* list);
void delAt(Node* list, uint16_t index);
void clear(Node* list);
#endif /*s_linkedList.h*/
