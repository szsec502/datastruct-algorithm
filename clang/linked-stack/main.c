#include "stack.h"
#include <stdio.h>

int main()
{
	link_stack s;

	s = newStack();

	if (s == NULL)
		return -1;

	push(s, 10);
	push(s, 20);
	push(s, 30);
	push(s, 40);
	push(s, 50);

	while(!is_empty(s))
	{
		printf("%d\n", pop(s));
	}

	s = free_stack(s);

	return 0;
}
