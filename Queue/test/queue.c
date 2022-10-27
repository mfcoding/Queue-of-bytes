#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "queue.h"

queue init_queue(uint64_t i, ...)
{
    queue q;
    q.queue.buffer = NULL;
    q.c = q.queue.i = q.queue.max = 0;
    if(i == 0)
    {
        return q;
    }
    va_list args;        
    va_start (args, i);           
    for(uint64_t c = 0; c < i; c++)        
    {
        push_back(&q.queue, va_arg (args, int)); 
    }
    va_end (args); 
    shrinkTofit(&q.queue);
    return q;  
}

void enqueue(queue *q, char data)
{
    _push_back_(q->queue, data);
}

queue enqueue_more(void)
{
    queue new_queue;
    new_queue.c = new_queue.queue.i = new_queue.queue.max = 0;
    new_queue.queue = input_str(NULL);
    return new_queue;
}

void dequeue(queue *q)
{
    if (_len_(q->queue))
    {
        _begin_(q->queue)++;
        _len_(q->queue)--;
        q->c++;
    }
    else
    {
        _begin_(q->queue) -= q->c;
        q->c = 0; 
        clear(&q->queue);
    }
}

uint64_t que_count(queue *q)
{
    return length(&q->queue);
}

void que_fit(queue *q)
{ 
    if(q->c)
    {
        memcpy(_begin_(q->queue) - q->c, _begin_(q->queue), _len_(q->queue));
        _begin_(q->queue) -= q->c;
        q->c = 0;
    }
    if(capacity(&q->queue))
    {
        shrinkTofit(&q->queue);
    }
}

void que_show(queue *q)
{
    display(&q->queue);
}

int que_empty(queue *q)
{
    return empty(&q->queue);
}

void que_clear(queue *q)
{

    if(q->c)
    {
        _begin_(q->queue) -= q->c;
        q->c = 0;
    }
    clear(&q->queue);
}

void que_destroy(queue *q)
{
    if(q->c)
    {
        _begin_(q->queue) -= q->c;
        q->c = 0;
    }
    erase(&q->queue);
}
