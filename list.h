#ifndef __VERTOR__H__
#define __VERTOR__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef enum{FALSE,TRUE}Bool;

typedef struct
{
	int num;
}Data;

typedef struct NODE
{
	Data data;
	struct NODE *next;
}Node;

typedef struct
{
	Node *phead;
	int size;
}List;


//初始化顺序表
List* init_list();
//销毁顺序表
void destroyList(List* list);
//清空顺序表
void clear_list(List* list);
//顺序表是否为空
Bool listEmpty(List* list);
//顺序表中存储元素的个数
int listElemNum(List* list);
//插入到最后
void listPushBack(List* list, Data data);
//插入到头
void listPushFront(List* list, Data data);
//插入到指定位置
void listInsert(List* list, int site, Data data);
//得到头元素
Data getlistBack(List* list);
//得到尾元素
Data getlistFront(List* list);
//得到指定位置的元素
Data getlistBySite(List* list, int site);
//删除尾巴
void listDeleteBack(List* list);
//删除头
void listDeleteFront(List* list);
//删除指定位置
void listDeleteBySite(List* list,int site);
//删除指定元素
void listDeleteByElem(List* list, Data data);





#endif