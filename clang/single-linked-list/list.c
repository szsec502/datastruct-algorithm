#include "list.h"
#include <stdlib.h>
#include <stdio.h>

link_list new_link_list()
{
	link_list L;

	L = (link_list)malloc(sizeof(list_node));
	if (L == NULL)
	{
		printf("malloc() error\n");
		return L;
	}

	L->value = 0;
	L->next = NULL;

	return L;
}

int link_insert_tail(link_list head, data_t value)
{
	link_list new_node;
	link_list last_node;

	if (head == NULL)
	{
		printf("link list is NULL\n");
		return -1;
	}

	if ((new_node = (link_list)malloc(sizeof(list_node))) == NULL)
	{
		printf("malloc() error\n");
		return -1;
	}

	new_node->value = value;
	new_node->next = NULL;

	last_node = head;
	while(last_node->next != NULL)
	{
		last_node = last_node->next;
	}

	last_node->next = new_node;
	return 0;
}

int print_linked_list(link_list head)
{
	link_list last_node;

	if (head == NULL)
	{
		printf("linked list is NULL\n");
		return -1;
	}

	last_node = head;

	while(last_node->next != NULL)
	{
		printf("%d ", last_node->next->value);
		last_node = last_node->next;
	}

	printf("\n");

	return 0;
}

link_list list_get(link_list head, int pos)
{
	link_list last_node;
	int i;

	if (head == NULL)
	{
		return NULL;
	}

	if (pos == -1)
	{
		return head;
	}

	last_node = head;
	i = -1;

	while(i < pos)
	{
		last_node = last_node->next;
		if (last_node == NULL)
		{
			printf("position is invalid.\n");
			return NULL;
		}

		i++;
	}

	return last_node;
}

int link_insert(link_list head, data_t value, int pos)
{
	link_list pre_node;
	link_list new_node;

	if (head == NULL)
	{
		printf("head is NULL\n");
		return -1;
	}

	pre_node = list_get(head, pos - 1);
	if (pre_node == NULL)
	{
		return -1;
	}

	if ((new_node = (link_list)malloc(sizeof(list_node))) == NULL)
	{
		printf("malloc() error\n");
		return -1;
	}

	new_node->value = value;
	new_node->next = NULL;

	new_node->next = pre_node->next;
	pre_node->next = new_node;

	return 0;
}

int link_delete(link_list head, int pos)
{
	link_list pre_node;
	link_list tmp_node;

	if (head == NULL)
	{
		printf("head is NULL\n");
		return -1;
	}

	pre_node = link_get(head, pos - 1);
	if (pre_node == NULL)
	{
		return -1;
	}

	if (pre_node->next == NULL)
	{
		printf("delete position is invalid.\n");
		return -1;
	}

	tmp_node = pre_node->next;
	pre_node->next = tmp_node->next; // pre_node->next = pre_node->next->next;
	
	free(tmp_node);

	return 0;
}
