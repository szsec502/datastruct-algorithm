#include "list.h"
#include <stdio.h>

int main()
{
	link_list head;
	int value;

	head = new_link_list();

	printf("input the value:");
	while(1)
	{
		scanf("%d", &value);
		if (value == -1)
			break;

		link_insert_tail(head, value);
		printf("input:");
	}

	print_linked_list(head);
	return 0;
}
