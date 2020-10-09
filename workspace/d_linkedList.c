#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include "d_linkedList.h"

bool isEmpty(Node* list) {
    return list->next == NULL;
}

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
    if(isEmpty(list)) {
        newNode->next = NULL;
        newNode->prev = list;
        list->next = newNode;
    } else {
        newNode->prev = list;
        newNode->next = list->next;
        list->prev = newNode;
        list->next = newNode;
    }
}

void addLast(Node* list, uint8_t data) {
    if(isEmpty(list)) {
        addFirst(list, data);
    } else {
        Node* newNode = (Node*)malloc(sizeof(Node*));
        newNode->data = data;
        Node* lastNode = list->next;
        while(lastNode != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = NULL;
    }
}

void delFirst(Node* list) {
    if(isEmpty(list)) {
        printf("This is empty list\n");
    } else {
        Node* target = list->next;
        list->next = target->next;
        target->next->prev = list;
        free(target);
    }
}
