#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include "d_linkedList.h"

bool isEmpty(Node* list) {
	return list->next == NULL;
}

bool search(Node* list, uint8_t target) {
	list = list->next;
	while(list != NULL) {
		if(list->data == target) {
			return true;
		}
		list = list->next;
	}
	return false;
}

uint16_t getSize(Node* list) {
	uint16_t listSize = 0;
	list = list->next;
	while(list != NULL) {
		list = list->next;
		listSize++;
	}
	return listSize;
}

uint8_t getDataAt(Node* list, uint16_t index) {
	list = list->next;
	for(uint8_t i = 0; i < index; i++) {
		list = list->next;
	}
	return list->data;
}

void printList(Node* list) {
	uint16_t index = 0;
	printf("List=\t{\n");
	list = list->next;
	while(list != NULL) {
		printf("\t\tindex (%2d) data:%4d [prev(%p) curr(%p) next(%p)]\n", index, list->data, list->prev, list, list->next);
		list = list->next;
		index++;
	}
	printf("\t}\n");
}

void addFirst(Node* list, uint8_t data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->data = data;

	if(isEmpty(list)) {
		list->next = newNode;
		newNode->prev = list;
	} else {
		newNode->next = list->next;
		newNode->prev = list;
		list->next->prev = newNode;
		list->next = newNode;
	}
}

void addLast(Node* list, uint8_t data) {
	if(isEmpty(list)) {
		addFirst(list, data);
	} else {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;

		Node* lastNode = list->next;
		while(lastNode->next != NULL) {
			lastNode = lastNode->next;
		}
		lastNode->next = newNode;
		newNode->prev = lastNode;
	}
}

void addAt(Node* list, uint16_t index, uint8_t data) {
	if((index < 0) || index > getSize(list)) {
		return;
	}
	else if(index == 0) {
		addFirst(list, data);
	}
	else if(isEmpty(list) || (index == getSize(list))) {
		addLast(list, data);
	}
	else {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->next = NULL;
		newNode->prev = NULL;
		newNode->data = data;

		list = list->next;
		for(uint16_t i = 0; i < index; i++) {
			list = list->next;
		}
		newNode->prev = list;
		newNode->next = list->next;
		list->next->prev = newNode;
		list->next = newNode;
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

void delLast(Node* list) {
	if(isEmpty(list)) {
		printf("This is empty list\n");
	} else {
		Node* lastNode = list->next;
		while(lastNode->next != NULL) {
			lastNode = lastNode->next;
		}
		lastNode->prev->next = NULL;
		free(lastNode);
	}
}

void delAt(Node* list, uint16_t index) {
	if(isEmpty(list)) {
		return;
	}
	else if((index < 0) || (index > getSize(list))) {
		return ;
	}
	else if(index == 0) {
		delFirst(list);
	}
	else if(index == getSize(list)) {
		delLast(list);
	}
	else {
		list = list->next;
		for(uint16_t i = 0; i < index; i++) {
			list = list->next;
		}
		Node* target = list->next;
		target->prev->next = target->next;
		target->next->prev = target->prev;
		target->next = NULL;
		target->prev = NULL;
		free(target);
	}

}
