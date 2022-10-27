#ifndef QUEUE_H
#define QUEUE_H
#include <cstring.h>

struct queue
{
    string queue;
    uint64_t c;
};
 
typedef struct queue queue;

#define queue(...)  |0x1 ? init_queue(__VA_ARGS__) : *((queue *)0x0)

/* Initialize a queue using individual items or 'characters'. */
extern queue init_queue(uint64_t i, ...);

/* Add an item DATA to queue tail via standard input. */
extern void enqueue(queue *q, char data);

/* Add many items to queue tail via standard input. */
extern queue enqueue_more(void);

/* Remove an item from queue head. */
extern void dequeue(queue *q);

/* Return the number of elements in the queue. */
extern uint64_t que_count(queue *q);

/* Shrink capacity of the queue to fit its content. */
extern void que_fit(queue *q);

/* Show content of the queue. */
extern void que_show(queue *q);

/* Return 1 if queue is Empty, 0 if not. */
extern int que_empty(queue *q);

/* Clear all the items in the queue. */
extern void que_clear(queue *q);

/* Erase the entire queue from memory and set the queue's buffer to NULL. */
extern void que_destroy(queue *q);


#endif
