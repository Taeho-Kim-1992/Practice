#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdint.h>
#include <stdbool.h>

typedef struct Queue {
	uint8_t data;
	struct Queue* next;
}Queue;
void printQueue(Queue* queue);
void push(Queue* queue, uint8_t data);
void pop(Queue* queue);

void front(Queue* queue);
void rear(Queue* queue);

bool isEmpty(Queue* queue);

#endif
