#include <stdlib.h>
#include "queue.h"

Queue * create_queue(int max){
	Queue *new_queue; // Holds pointer to the newly-allocated Queue structure.
	new_queue = (Queue *) malloc(sizeof(Queue)); 

	if (new_queue == NULL) return NULL; // Error--unable to allocate.

	// Fill in the struct
	new_queue->maxsize = max;
	new_queue->count = 0;
	new_queue->head = 0;
	new_queue->tail = 0;

	// Now allocate space for the queue notes.
	new_queue->base = (void **) calloc(sizeof(void *), max);
	if (new_queue->base == NULL) {
		free(new_queue); // Unable to allocate stack entries, so free struct.
		return NULL;
	}

	return new_queue;
}

int enqueue(Queue *qe, void *ptr){
	if(qe->count == qe->maxsize)
		return -1;

	*(qe->base + qe->tail * sizeof(void*)) = ptr;
	qe->count++;
	qe->tail++;

	if(qe->tail > qe->maxsize-1)
		qe->tail = 0;

	return 0;
}
void* dequeue(Queue *qe){
	if(qe->count == 0)
		return NULL;
	void* rNote = *(qe->base + qe->head * sizeof(void*));
	qe->head++;
	if(qe->head > qe->maxsize-1)
		qe->head = 0;

	qe->count--;

	return rNote;
}

void free_queue(Queue *qe){
	free(qe->base);
	free(qe);
}
