#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

typedef struct {
  int x;
} Foo; // Just some arbitrary struct


int main() {
	const int max_entries = 5; // size of stack

	Foo* new_foo;
	Foo* returned_foo;
	int count;
	int ind;

	// First, create a queue
	Queue *nqueue = create_queue(max_entries);
	
	// TEST 1
	printf("TEST 1\n");
	// Tring to enqueue 10 elements
	ind = 10;
	while(ind < 20){
		new_foo = (Foo *) malloc(sizeof(Foo));
		new_foo->x = ind;
		
		int result = enqueue(nqueue, (void *) new_foo);
		if(result == 0)
			printf("enqueue: x = %d\n", new_foo->x);
		else{
			// Queue is full
			printf("Size of queue reched\n");
		}
		ind++;
	}

	// dequeue all notes
	count = 1;
	while((returned_foo = dequeue(nqueue))!=NULL){
		printf("%d.\tdequeue: x = %d\n", count, returned_foo->x);
		free(returned_foo);
		count++;
	}
	printf("----------------------------------\n");

	// TEST 2
	printf("TEST 2\n");
	// enqueue 3 and dequeue 3
	ind = 100;
	while(ind < 103){
		new_foo = (Foo *) malloc(sizeof(Foo));
		new_foo->x = ind;
		
		int result = enqueue(nqueue, (void *) new_foo);
		if(result == 0)
			printf("enqueue: x = %d\n", new_foo->x);
		else{
			// Queue is full
			printf("Size of queue reched\n");
		}
		ind++;
	}
	// dequeue all notes
	count = 1;
	while((returned_foo = dequeue(nqueue))!=NULL){
		printf("%d.\tdequeue: x = %d\n", count, returned_foo->x);
		free(returned_foo);
		count++;
	}
	// And again enqueue 4 and dequeue 4	
	ind = 200;
	while(ind < 204){
		new_foo = (Foo *) malloc(sizeof(Foo));
		new_foo->x = ind;
		
		int result = enqueue(nqueue, (void *) new_foo);
		if(result == 0)
			printf("enqueue: x = %d\n", new_foo->x);
		else{
			// Queue is full
			printf("Size of queue reched\n");
		}
		ind++;
	}
	// dequeue all notes
	count = 1;
	while((returned_foo = dequeue(nqueue))!=NULL){
		printf("%d.\tdequeue: x = %d\n", count, returned_foo->x);
		free(returned_foo);
		count++;
	}
	printf("----------------------------------\n");
	// Free memory
	free_queue(nqueue);
	return 1;
}
