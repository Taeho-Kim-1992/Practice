#ifndef _D_LINKEDLIST_H__
#define _D_LINKEDLIST_H__
#include <inttypes.h>
#include <stdbool.h>

typedef struct node {
    uint8_t data;
    struct node* next;
    struct node* prev;
}Node;

void printList(Node* list);
void addFirst(Node* list, uint8_t data);
#endif /*d_linkedList.h*/
