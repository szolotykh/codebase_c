/** 
* Struct to define a queue; each entry can hold a pointer to anything.
*/
struct queue {
  void **base; // Pointer to base of queue

  int maxsize; // Head of cueue
  int head; // Head of queue
  int tail; // Tail of queue
  int count; // Number of notes in queue
};

typedef struct queue Queue;

// Function prototypes

/** Create queue by allocating a Queue structure, initializing it,
 * and allocating memory to hold the queueentries
 * @param maximum notes in queue
 * @return Pointer to newly-allocated Queue structure, Null if errore.
*
*/
Queue * create_queue(int max);

/**  Add new note to queue
 * @param qe Pointer to queue you want to add note.
 * @param ptr Pointer to be added.
 * @return 0 if successful, -1 if not.
*/
int enqueue(Queue *qe, void *ptr);

/**  Take note from queue
 * @param qe Pointer to queue.
 * @return Pointer on note, or NULL if queue is empty.
*/
void* dequeue(Queue *qe);

/** Free queue memory
 * @param qe Pointer to queue.
*/
void free_queue(Queue *qe);
