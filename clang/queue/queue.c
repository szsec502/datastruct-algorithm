#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

queue * newQueue()
{
	queue *q;

	if ((q = (queue *)malloc(sizeof(queue))) == NULL)
	{
		printf("malloc() queue error\n");
		return NULL;
	}

	memset(q->data, 0, sizeof(q->data));
	q->front = q->rear = 0;

	return q;
}

int put_queue(queue *q, data_t value)
{
	if (q == NULL)
	{
		printf("queue is NULL\n");
		return -1;
	}

	if ((q->rear + 1) % N == q->front)
	{
		printf("queue is full\n");
		return -1;
	}

	q->data[q->rear] = value;
	q->rear = (q->rear + 1) % N;

	return 0;
}

data_t pull_queue(queue *q)
{
	if (q == NULL)
	{
		printf("queue is NULL\n");
		return -1;
	}

	data_t value;

	value = q->data[q->front];

	q->front = (q->front + 1) % N;

	return value;
}

int is_empty(queue *q)
{
	return (q->front == q->rear ? 1 : 0);
}

int is_full(queue *q)
{
	if (q == NULL)
	{
		printf("queue is NULL\n");
		return -1;
	}

	if ((q->rear + 1) % N == q->front)
	{
		return 1;
	}

	return 0;
}

queue * free_queue(queue *q)
{
	if (q == NULL)
	{
		printf("queue is NULL\n");
		return NULL;
	}

	free(q);
	q = NULL;

	return NULL;
}

int clear_queue(queue *q)
{
	if (q == NULL)
	{
		printf("queue is NULL\n");
		return -1;
	}

	q->front = q->rear = 0;

	return 0;
}
