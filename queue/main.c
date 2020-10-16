#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "queue.h"

int main(void) {

	printf("Queue Start\n");
	Queue* queue = (Queue*)malloc(sizeof(Queue));

	isEmpty(queue);

	push(queue, 10);
	push(queue, 20);
	push(queue, 30);
	push(queue, 40);

	front(queue);
	rear(queue);
	printQueue(queue);
	pop(queue);
	pop(queue);
	pop(queue);
	pop(queue);
	pop(queue);

	return 0;
}
