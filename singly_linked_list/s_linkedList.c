#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>

#include "s_linkedList.h"

uint16_t getSize(Node* list) {
    uint16_t size = 0;
    Node* tmp = list->next;
    while(tmp != NULL) {
        tmp = tmp->next;
        size++;
    }
    return size;
}

uint8_t getDataAt(Node* list, uint16_t index) {
    if((index > getSize(list)) || (index < 0)) {
        printf("Wrong index\n");
        return 0;
    }
    Node* tmp = list->next;
    for(uint8_t i = 0; i < index; i++) {
        tmp = tmp->next;
    }
    return tmp->data;
}

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
    free(tmp);
    return false;
}

bool isEmpty(Node* list) {
    return list->next == NULL;
}

void printList(Node* list) {
    printf("List=\t{\n");
    while(list->next != NULL) {
        printf("\t\tData: %4d at(%p) \n", list->data, list);
        list = list->next;
    }
    printf("\t}\n");
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

void addAt(Node* list, uint8_t index, uint8_t data) {
    if((index < 0) || (index > getSize(list))) {
        return;
    } else if (index == 0) {
        addFirst(list, data);
    } else if (index == getSize(list)) {
        addLast(list, data);
    } else {
        Node* newNode = (Node*)malloc(sizeof(Node*));
        for(uint8_t i = 0; i < index; i++) {
            list = list->next;
        }
        newNode->data = data;
        newNode->next = list->next;
        list->next = newNode;
    }
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

void delAt(Node* list, uint16_t index) {
	if((index < 0) || (index > getSize(list))) {
		return;
	} else if (index == 0) {
		delFirst(list);
	} else if (index == getSize(list)) {
		delLast(list);
	} else {
		for(uint8_t i = 0; i < index; i++) {
			list = list->next;
		}
        list -> next = list->next->next;
	}
}

void clear(Node* list) {
    while(!isEmpty(list)) {
        delLast(list);
    }
}
