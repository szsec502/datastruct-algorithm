#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 1. 创建线性表
 * 2. 为线性表分配内存
 * 3. 初始化线性表成员
 * 对于线性表L我们应将L队友的内存置为空
 * 对于线性表L的长度应置为-1
 * 最后返回线性表
 * */
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

/*
 * 释放线性表的前提是线性表不能为NULL
 * 使用free(L)释放线性表内存
 * 最后将线性表L的值置为NULL，并返回零表示释放成功
 * */
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
 * 清空线性表的前提是，线性表L不能为NULL
 * 清空的操作就是将线性表L所占用的内存置空，并将线性表的长度置为负一,最后返回零表示清空成功
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

/*
 * 判断线性表是否为空只需判断线性表的长度last是否为-1
 * */
int list_empty(ptrlink L)
{
	if (L->last == -1)
	{
		return -1;
	}

	return 0;
}

/*
 * 获取线性表的长度的前提是线性表L不能为空，我们只需将线性表的长度last返回即可
 * */
int list_length(ptrlink L)
{
	if (L == NULL)
	{
		return -1;
	}
	return (L->last + 1); // 这里需要加一的原因是，线性表的下表是从零开始的所以得加一
}

/*
 * 判断某个元素释放存在与线性表当中，其实就是使用for循环对线性表每个值跟指定的值进行比较如果相等就返回线性表元素的位置
 * */
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

/*
 * 向线性表中插入指定位置的元素
 * 1. 判断线性表是否满了
 * 2. 校验位置参数是否合法pos必须大于0,或者pos大于线性表长度-1
 * 3. 移动线性表，循环条件是i>=pos, 移动使用L->last的位置开始移动L->value[i + 1] = L->value[i]
 * 4. 元素移动完成后，将带插入的值，放到指定的位置上(L-value[pos] = value), 线性表长度加加(L->last++)
 * */
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

/*
 * 合并线性表就是对线性表进行遍历，如L2中的某个元素存在与L1中则将L2中的元素加入到L1中
 * */
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

/*
 * 线性表的去重操作就是将线性表两两相邻的两个元素进行比较，如果他们相等则进行删除操作
 * 1. 判断线性表是否为空
 * 2. 外层循环控制线性表中前一个元素，内层循环控制线性表后一个元素
 * 3. 如果相邻的两个元素不相等，则j--, 如果j小于零了i++
 */
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
