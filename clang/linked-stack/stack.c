#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

link_stack newStack()
{
	link_stack s;
	s = (link_stack)malloc(sizeof(stack_node));
	if (s == NULL)
	{
		printf("malloc() link stack error\n");
		return NULL;
	}

	s->data = 0;
	s->next = NULL;

	return s;
}

int push(link_stack s, data_t value)
{
	link_stack phead;

	if (s == NULL)
	{
		printf("link stack is NULL\n");
		return -1;
	}

	phead = (link_stack)malloc(sizeof(stack_node));
	if (phead == NULL)
	{
		printf("malloc() phead error\n");
		return -1;
	}

	phead->data = value;
	phead->next = s->next;
	s->next = phead;

	return 0;
}

data_t pop(link_stack s)
{
	link_stack phead;
	data_t t_value;

	phead = s->next;
	s->next = phead->next;

	t_value = phead->data;

	free(phead);
	phead = NULL;

	return t_value;
}

int is_empty(link_stack s)
{
	if (s == NULL)
	{
		printf("link_stack is NULL\n");
		return -1;
	}
	return (s->next == NULL ? 1 : 0);
}

data_t get_top(link_stack s)
{
	return (s->next->data);
}

link_stack free_stack(link_stack s)
{
	link_stack phead;

	if (s == NULL)
	{
		printf("stack is NULL\n");
		return NULL;
	}

	while(s != NULL)
	{
		phead = s;
		s = s->next;
		free(phead);
	}

	return NULL;
}
