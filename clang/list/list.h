#ifndef __LIST_H__
#define __LIST_H__

#define MAX_LEN 10

/*
 * 线性表的线性存储
 * 定义存储数据类型数据
 * */
typedef int data_t; // data_t为int的别名


/*
 * 线性表的结构
 * 类型为data_t的value数组用于存储线性表数据元素
 * last用于存放线性表长度
 * */
typedef struct
{
	data_t value[MAX_LEN];
	int last;
}list, *ptrlink;

/*
 * 用于初始化线性表
 * 返回值为指针类型的ptrlink
 * */
ptrlink new_link();

/*
 * 释放线性表内存,删除线性表
 * */
int list_free(ptrlink L);

/*
 * 清空线性表内容，不删除线性表
 * */
int list_clear(ptrlink L);

/*
 * 判断线性表是否为空
 * */
int list_empty(ptrlink L);

/*
 * 获取线性表长度
 * */
int list_length(ptrlink L);

/*
 * 判断某个给定的值是否存在于线性表中
 * */
int list_localte(ptrlink L, data_t value);

/*
 * 给定指定位置往线性表插入元素
 * */
int list_insert(ptrlink L, data_t value, int pos);

/*
 * 删除指定位置的线性表元素
 * */
int list_delete(ptrlink L, int pos);

/*
 * 打印输出线性表
 * */
int list_show(ptrlink L);

/*
 * 合并线性表
 * */
int list_merge(ptrlink L1, ptrlink L2);

/*
 * 线性表去重
 * */
int list_purge(ptrlink L);


#endif
