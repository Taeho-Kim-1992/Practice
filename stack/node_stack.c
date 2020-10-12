#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "node_stack.h"

bool isEmpty(Stack* head) {
	return head->next == NULL;
}

void printStack(Stack* head) {
	uint8_t index = 0;
	head = head->next;
	while(head != NULL) {
		printf("(%d)Stack data [%d] curr[%p] next[%p]\n", index, head->data, head, head->next);
		head = head->next;
		index++;
	}
}

void push(Stack* head, uint8_t data) {
	Stack* newStack = (Stack*)malloc(sizeof(Stack));
	newStack->next = NULL;
	newStack->data = data;
	while(head->next != NULL) {
		head = head->next;
	}
	head->next = newStack;
}

void pop(Stack* head) {
	if(isEmpty(head)) {
		printf("Empty stack\n");
		return;
	}
	while(head->next->next != NULL)
		head = head->next;
	Stack* target = head->next;
	printf("pop target node(stack) data : %d at [%p]\n", target->data, target);
	head->next = target->next;
	free(target);
	return;
}

uint8_t peek(Stack* head) {
	if(isEmpty(head)) {
		printf("Empty stack\n");
		return 0;
	}
	while(head->next->next != NULL)
		head = head->next;
	Stack* target = head->next;
	return target->data;
}

bool search(Stack* head, uint8_t target) {
	if(isEmpty(head)) {
		printf("Empty stack\n");
		return false;
	}
	head = head->next;
	while(head->next != NULL) {
		head = head->next;
		if(head->data == target)
			return true;
	}
	return false;
}
