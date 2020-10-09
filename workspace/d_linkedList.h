#ifndef _D_LINKEDLIST_H__
#define _D_LINKEDLIST_H__
#include <inttypes.h>
#include <stdbool.h>

typedef struct node {
    uint8_t data;
    struct node* next;
    struct node* prev;
}Node;
bool isEmpty(Node* list);
void printList(Node* list);
void addFirst(Node* list, uint8_t data);
void addLast(Node* list, uint8_t data);
void delFirst(Node* list);
void delLast(Node* list);
#endif /*d_linkedList.h*/
