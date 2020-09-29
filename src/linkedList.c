#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linkedList.h"

bool search(Node* list, uint8_t target) {
    Node* tmp = list->next;
    while(tmp != NULL) {
        if(tmp->data == target) {
            printf("%d exists in this list.\n", target);
            return true;
        }
        tmp = tmp->next;
    }
    printf("%d does not exist in this list.\n", target);
    return false;
}

bool isEmpty(Node* list) {
    if(list->next == NULL) {
        printf("This is empty list\n");
        return true;
    } else {
        return false;
    }
}

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

void delFirst(Node* list) {
    if(isEmpty(list)) {
        return;
    }
    Node* target = list->next;
    list->next = target->next;
    free(target);
}

void delLast(Node* list) {
    if(isEmpty(list)) {
        return;
    }
    while(list->next->next != NULL)
        list = list->next;
    Node* target = list->next;
    list->next = target->next;
    free(target);
}

void clear(Node* list) {
    while(!isEmpty(list)) {
        delLast(list);
    }
}
