#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include "d_linkedList.h"

void printList(Node* list) {
    Node* tmp = list->next;
    printf("List: [");
    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("]\n");
}

void addFirst(Node* list, uint8_t data) {
    Node* newNode = (Node*)malloc(sizeof(Node*));
    newNode->data = data;

    if(list->next == NULL) {
        newNode->next = NULL;
        newNode->prev = list;
        list->next = newNode;
    } else {
        newNode->prev = list;
        newNode->next = list->next;
        list->prev = NULL;
        list->next = newNode;
    }
}

