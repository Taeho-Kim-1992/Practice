#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "queue.h"

void printQueue(Queue* queue) {
	printf("queue=\t{\n");
	queue = queue->next;
	while(queue != NULL) {
		printf("\t\tdata: %3d [curr(%p) next(%p)] \n", queue->data, queue, queue->next);
		queue = queue->next;
	}
	printf("\t}\n");
}

bool isEmpty(Queue* queue) {
	return queue->next == NULL;
}

void push(Queue* queue, uint8_t data) {
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));
	newQueue->data = data;
	newQueue->next = NULL;
	if(isEmpty(queue)) {
		queue->next = newQueue;
	} else {
		newQueue->next = queue->next;
		queue->next = newQueue;
	}
}

void pop(Queue* queue) {
	if(isEmpty(queue)) {
		printf("Queue is empty\n");
		return;
	}
	Queue* target = queue->next;
	queue->next = target->next;
	printf("pop data [%d] \n", target->data);
	free(target);
}

void front(Queue* queue) {
	if(isEmpty(queue)) {
		printf("Queue is empty\n");
		return;
	}
	printf("front [%d]\n", queue->next->data);
}
void rear(Queue* queue) {
	if(isEmpty(queue)) {
		printf("Queue is empty\n");
		return;
	}
	queue = queue->next;
	while(queue->next != NULL) {
		queue = queue->next;
	}
	printf("rear [%d]\n", queue->data);
}
