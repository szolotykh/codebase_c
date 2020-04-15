#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef struct {
  int x;
  double y;
} Foo; // Just some arbitrary struct


int main() {
  const int max_entries = 5; // size of stack
  Foo* new_foo1;
  Foo* new_foo2; 
  Foo* returned_foo;

  // First, create a stack
  Stack *new_stack = create_stack(max_entries);

  // Allocate a Foo and push it onto the stack.
  new_foo1 = (Foo *) malloc(sizeof(Foo));
  new_foo1->x = 6;
  new_foo1->y = 14.79;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo1->x, new_foo1->y);
  push(new_stack, (void *) new_foo1);

  // Allocate another Foo and push it onto the stack.
  new_foo2 = (Foo *) malloc(sizeof(Foo));
  new_foo2->x = 217;
  new_foo2->y = 3.14159;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo2->x, new_foo2->y);
  push(new_stack, (void *) new_foo2);

  // Peek at the top of the stack
  returned_foo = (Foo *) peek(new_stack);
  printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

  // Retrieve the Foos and print them.
  returned_foo = (Foo *) pop(new_stack);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) pop(new_stack);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);



  // Clean up
  delete_stack(new_stack);
  free(new_foo1);
  free(new_foo2);



  
  // Test 1
  printf("Test 1\n");

  Foo * foo10 = (Foo *) malloc(sizeof(Foo));
  foo10->x = 10;
  foo10->y = 10;

  Foo * foo20 = (Foo *) malloc(sizeof(Foo));
  foo20->x = 20;
  foo20->y = 20;

  Foo * foo30 = (Foo *) malloc(sizeof(Foo));
  foo30->x = 30;
  foo30->y = 30;

  Foo * foo40 = (Foo *) malloc(sizeof(Foo));
  foo40->x = 40;
  foo40->y = 40;

  Foo * foo50 = (Foo *) malloc(sizeof(Foo));
  foo50->x = 50;
  foo50->y = 50;

  Foo * foo60 = (Foo *) malloc(sizeof(Foo));
  foo60->x = 60;
  foo60->y = 60;


  Stack *test_stack = create_stack(max_entries);

  Foo * foo11 = (Foo *) malloc(sizeof(Foo));
  foo11->x = 10;
  foo11->y = 10;

  Foo * foo21 = (Foo *) malloc(sizeof(Foo));
  foo21->x = 20;
  foo21->y = 20;

  push(test_stack, (void *) foo11);
  printf("Pushing: x = %5d, y = %10.3f\n", foo11->x, foo11->y);

  returned_foo = (Foo *) pop(test_stack);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);


  push(test_stack, (void *) foo21);
  printf("Pushing: x = %5d, y = %10.3f\n", foo21->x, foo21->y);

  // Peek at the top of the stack
  returned_foo = (Foo *) peek(test_stack);
  printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);



  // Test 2
  printf("Test2\n");

 Stack *test_stack_2 = create_stack(max_entries);

  push(test_stack_2, (void *) foo10);
  printf("Pushing: x = %5d, y = %10.3f\n", foo10->x, foo10->y);

  push(test_stack_2, (void *) foo20);
  printf("Pushing: x = %5d, y = %10.3f\n", foo20->x, foo20->y);

  push(test_stack_2, (void *) foo30);
  printf("Pushing: x = %5d, y = %10.3f\n", foo30->x, foo30->y);

  push(test_stack_2, (void *) foo40);
  printf("Pushing: x = %5d, y = %10.3f\n", foo40->x, foo40->y);

  push(test_stack_2, (void *) foo50);
  printf("Pushing: x = %5d, y = %10.3f\n", foo50->x, foo50->y);

  int out =  push(test_stack_2, (void *) foo60);
  printf("Push returned: %d\n", out);


  printf("Test 3\n");

  returned_foo = (Foo *) pop(test_stack_2);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

  returned_foo = (Foo *) pop(test_stack_2);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

  returned_foo = (Foo *) pop(test_stack_2);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

  returned_foo = (Foo *) pop(test_stack_2);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

  returned_foo = (Foo *) pop(test_stack_2);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

  out  = pop(test_stack_2);
  printf("Pop return: %d\n", out);


  delete_stack(test_stack_2);
  delete_stack(test_stack);

  return 0;
}
