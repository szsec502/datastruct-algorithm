#ifndef __SINGLE_LINKED_LIST_H__
#define __SINGLE_LINKED_LIST_H__

typedef int data_t;

typedef struct node
{
	data_t value;
	struct node *next;
}list_node, *link_list;

link_list new_link_list();

int link_insert_tail(link_list head, data_t value);

link_list link_get(link_list head, int pos);

int link_insert(link_list head, data_t value, int pos);

int link_delete(link_list head, int pos);

int print_linked_list(link_list head);

#endif
