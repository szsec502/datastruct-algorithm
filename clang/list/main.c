#include "list.h"
#include <stdio.h>

int main()
{
	ptrlink L1 = new_link();
	ptrlink L2 = new_link();

	list_insert(L1, 10, 0);
	list_insert(L1, 2, 0);
	list_insert(L1, 3, 0);
	list_insert(L1, 4, 0);
	list_insert(L1, 50, 0);

	list_show(L1);

	printf("the list length is : %d\n", list_length(L1));

	list_insert(L2, 10, 0);
	list_insert(L2, 20, 0);
	list_insert(L2, 30, 0);
	list_insert(L2, 40, 0);
	list_insert(L2, 50, 0);

	list_show(L2);

	printf("the list 2 length is : %d\n", list_length(L1));

	list_merge(L1, L2);

	list_show(L1);
	list_show(L2);

	return 0;
}
