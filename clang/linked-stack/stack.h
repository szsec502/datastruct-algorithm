#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

typedef int data_t;

typedef struct node
{
	data_t data;
	struct node *next;
}stack_node, *link_stack;

link_stack newStack();

int push(link_stack s, data_t value);

data_t pop(link_stack s);

int is_empty(link_stack s);

data_t get_top(link_stack s);

link_stack free_stack(link_stack s);

#endif
