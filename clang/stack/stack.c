#include "stack.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

sqstack * newStack(int len)
{
	sqstack *s;

	if ((s = (sqstack *)malloc(sizeof(sqstack))) == NULL)
	{
		printf("malloc() stack error\n");
		return NULL;
	}

	if ((s->data = (data_t *)malloc(len * sizeof(data_t))) == NULL)
	{
		printf("malloc() data error\n");
		free(s);
		return NULL;
	}

	memset(s->data, 0, len * sizeof(data_t));
	s->maxlen = len;
	s->top = -1;

	return s;
}

int push(sqstack * s, data_t value)
{
	if (s == NULL)
	{
		printf("stack is NULL\n");
		return -1;
	}

	if (s->top == s->maxlen)
	{
		printf("stack is full\n");
		return -1;
	}
	
	s->top++;
	s->data[s->top] = value;

	return 0;
}

data_t pop(sqstack *s)
{
	s->top--;
	return (s->data[s->top + 1]);
}

data_t get_top(sqstack *s)
{
	return (s->data[s->top]);
}

int clear(sqstack *s)
{
	if (s == NULL)
	{
		printf("stack is NULL\n");
		return -1;
	}

	s->top = -1;

	return 0;
}

int free_stack(sqstack *s)
{
	if (s == NULL)
	{
		printf("stack is NULL\n");
		return -1;
	}

	if (s->data != NULL)
		free(s->data);
	free(s);

	return 0;
}

int is_empty(sqstack *s)
{
	if (s == NULL)
	{
		printf("stack is NULL\n");
		return -1;
	}

	return (s->top == -1 ? -1 : 0);
}

int is_full(sqstack *s)
{
	if (s == NULL)
	{
		printf("stack is NULL\n");
		return -1;
	}

	return (s->top == s->maxlen - 1 ? -1 : 0);
}
