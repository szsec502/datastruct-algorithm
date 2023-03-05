#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ptrlink new_link()
{
	ptrlink L; // 创建线性表

	L = (ptrlink)malloc(sizeof(list)); // 分配内存，sizeof应该为list而不是ptrlink
	if (L == NULL)
	{
		printf("malloc() error\n");
		return L;
	}

	memset(L, 0, sizeof(list)); // 将L的内存置零
	L->last = -1; // 将L->last置为-1

	return L;
}

int list_free(ptrlink L)
{
	if (L == NULL) // 如果L为NULL直接返回
	{
		return -1;
	}

	free(L);
	L = NULL;

	return 0;
}

/*
 * list_clear是将线性表里的内容清空，而不是删除线性表本身
 * */
int list_clear(ptrlink L)
{
	if (L == NULL)
	{
		return -1;
	}

	memset(L, 0, sizeof(list));
	L->last = -1;

	return 0;
}

int list_empty(ptrlink L)
{
	if (L->last == -1)
	{
		return -1;
	}

	return 0;
}

int list_length(ptrlink L)
{
	if (L == NULL)
	{
		return -1;
	}
	return (L->last + 1);
}

int list_localte(ptrlink L, data_t value)
{
	int i;
	for (i = 0; i < L->last; i++)
	{
		if (L->value[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int list_insert(ptrlink L, data_t value, int pos)
{
	int i;

	if (L->last == MAX_LEN - 1) // 判断list是否满了
	{
		printf("list is full\n");
		return -1;
	}

	if (pos < 0 || pos > L->last + 1) // 校验pos位置是否合法
	{
		printf("parameter is invalid.\n");
		return -1;
	}

	for (i = L->last; i >= pos; i--) // 从L->last的位置开始移动元素
	{
		L->value[i + 1] = L->value[i];
	}

	L->value[pos] = value; // 将value插入到指定的pos位置里
	L->last++; // 更新list长度

	return 0;
}

int list_delete(ptrlink L, int pos)
{
	int i;

	if (L->last == -1) // 判断list是否为空
	{
		printf("the list is empty.\n");
		return -1;
	}

	if (pos < 0 || pos > L->last) // 校验参数是否合法
	{
		printf("the pos is invalid.\n");
		return -1;
	}

	for (i = pos + 1; i < L->last; i++) // 移动前面的元素
	{
		L->value[i - 1] = L->value[i];
	}

	L->last--; // 更新list长度

	return 0;
}

int list_show(ptrlink L)
{
	int i;

	if (L == NULL)
	{
		printf("the list is empty.\n");
		return -1;
	}

	if (L->last == -1)
	{
		printf("the list length is zero.\n");
		return -1;
	}

	for (i = 0; i <= L->last; i++)
	{
		printf("%d ", L->value[i]);
	}
	printf("\n");
	return 0;
}

int list_merge(ptrlink L1, ptrlink L2)
{
	int i = 0;
	int iret;

	while(i <= L2->last)
	{
		iret = list_localte(L1, L2->value[i]);
		if (iret == -1)
		{
			return -1;
		}
		i++;
	}

	return 0;
}

int list_purge(ptrlink L)
{
	int i, j;

	if (L->last == 0)
	{
		return -1;
	}

	i = 0;

	while(i <= L->last)
	{
		j = i + 1;
		while(j >= 0)
		{
			if (L->value[i] == L->value[j])
			{
				list_delete(L, i);
				break;
			}
			else
			{
				j--;
			}
		}

		if (j < 0)
		{
			i++;
		}
	}
	return 0;
}
