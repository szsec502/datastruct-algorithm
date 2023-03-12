#ifndef __QUEUE_H__
#define __QUEUE_H__

#define N 64

typedef int data_t;

typedef struct
{
	data_t data[N];
	int front, rear;
} queue;

queue * newQueue();

int put_queue(queue *q, data_t value);

data_t pull_queue(queue *q);

int is_empty(queue *q);

int is_full(queue *q);

queue * free_queue(queue *q);

int clear_queue(queue *q);


#endif
