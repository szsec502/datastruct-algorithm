#include <stdio.h>
#include "queue.h"

int main()
{
	queue *q;
	if ((q = newQueue()) == NULL)
	{
		return -1;
	}

	put_queue(q, 12);
	put_queue(q, 13);
	put_queue(q, 14);
	put_queue(q, 15);
	put_queue(q, 16);

	while(!is_empty(q))
	{
		printf("%d\n", pull_queue(q));
	}

	free_queue(q);
	return 0;
}
