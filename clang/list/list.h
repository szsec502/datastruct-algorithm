#ifndef __LIST_H__
#define __LIST_H__

#define MAX_LEN 10

typedef int data_t;

typedef struct
{
	data_t value[MAX_LEN];
	int last;
}list, *ptrlink;

ptrlink new_link();

int list_free(ptrlink L);

int list_clear(ptrlink L);

int list_empty(ptrlink L);

int list_length(ptrlink L);

int list_localte(ptrlink L, data_t value);

int list_insert(ptrlink L, data_t value, int pos);

int list_delete(ptrlink L, int pos);

int list_show(ptrlink L);

int list_merge(ptrlink L1, ptrlink L2);

int list_purge(ptrlink L);


#endif
