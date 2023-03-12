#ifndef __STACK_H__
#define __STACK_H__

typedef int data_t;

typedef struct {
	data_t *data;
	int    maxlen;
	int    top;
}sqstack;

sqstack * newStack(int len);

int push(sqstack * s, data_t value);

data_t pop(sqstack *s);

data_t get_top(sqstack *s);

int clear(sqstack *s);

int free_stack(sqstack *s);

int is_empty(sqstack *s);

int is_full(sqstack *s);

#endif
