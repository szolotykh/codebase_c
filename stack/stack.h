/** Struct to define a stack; each entry can hold a pointer to anything.
 */
struct stack {
  void **stack_base; // Pointer to base of stack
  void **next;  // Pointer to next free cell;
  int max_cells; // Maximum number of entries in the stack
  int cells_used; // Currently used number of cells
};

typedef struct stack Stack;

// Function prototypes

/** Create a stack by allocating a Stack structure, initializing it,
 *  and allocating memory to hold the stack entries.
 * @param max_cells Maximum entries in the stack
 * @return Pointer to newly-allocated Stack structure, NULL if error.
 */
Stack *create_stack(int max_cells);

/** Deletes a stack, including the structure and the memory
 * for holding the stack entries, but not the entries themselves.
 * @param which_stack Pointer to Stack structure.
 */
void delete_stack(Stack *which_stack);

/** Pushes a pointer onto a Stack.
 * @param which_stack Pointer to stack you want to push onto.
 * @param ptr Pointer to be pushed.
 * @return 0 if successful, -1 if not.
 */
int push(Stack *which_stack, void *ptr);

/** Pops top of stack, and returns it.
 * @param which_stack Pointer to Stack you want to pop from.
 * @return Top entry of the stack, NULL if stack is empty.
 */
void* pop(Stack *which_stack);

/** Peek at top of stack, without popping
 * @param which_stack Pointer to Stack you want to peek into
 * @return Top entry of the stack, NULL if stack is empty.
 */
void* peek(Stack *which_stack);
