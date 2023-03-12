#include <stdio.h>
#include "stack.h"

int main()
{
	sqstack *s;
	s = newStack(10);
	if (s == NULL)
		return -1;

	push(s, 10);
	push(s, 20);
	push(s, 30);
	push(s, 40);
	push(s, 50);
	push(s, 60);
	push(s, 70);
	push(s, 80);
	push(s, 90);

	while(!is_empty(s))
	{
		printf("%d\n", pop(s));
	}

	free_stack(s);

	return 0;
}
