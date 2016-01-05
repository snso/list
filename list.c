#include "list.h"

//初始化顺序表
List* init_list()
{
	List *list = (List*)malloc(sizeof(List));
	list->phead = (Node*)malloc(sizeof(Node));
	list->phead->next = NULL;
	return list;
}
//销毁顺序表
void destroyList(List* list)
{
	clear_list(list);
	free(list->phead);
	list->phead = NULL;
	free(list);
	list = NULL;
}
//清空顺序表
void clear_list(List* list)
{
	Node *tmp = list->phead;
	Node *ptmp = NULL;
	while(tmp->next)
	{
		ptmp = tmp->next;
		tmp->next = ptmp->next;
		free(ptmp);
		ptmp = NULL;
		list->size--;
	}
}
//顺序表是否为空
Bool listEmpty(List* list)
{
	return list->size == 0;
}
//顺序表的长度
int listElemNum(List* list)
{
	return list->size;
}
//创建一个新的结点
Node* CreatNode(Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//插入到最后
void listPushBack(List* list, Data data)
{
	Node *newNode = CreatNode(data);
	Node *tmp = list->phead;
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = newNode;
	list->size++;
}
//插入到头
void listPushFront(List* list,Data data)
{
	Node *newNode = CreatNode(data);
	newNode->next = list->phead->next;
	list->phead->next = newNode;
	list->size++;

}
//插入到指定位置
void listInsert(List* list, int site, Data data)
{
	Node *newNode = CreatNode(data);
	Node *tmp = list->phead;
	site += 1;
	while(--site)
	{
		tmp = tmp->next;
	}
	newNode->next = tmp->next;
	tmp->next = newNode;
	list->size++;
}
//得到头元素
Data getlistBack(List* list)
{
	Node *tmp = list->phead;
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	return tmp->data;
	
}
//得到尾元素
Data getlistFront(List* list)
{
	return list->phead->next->data;
}
//得到指定位置的元素
Data getlistBySite(List* list ,int site)
{
	Node *tmp = list->phead;
	while(site--)
	{
		tmp = tmp->next;
	}
	return tmp->next->data;
}
//删除尾
void listDeleteBack(List* list)
{
	Node *tmp = list->phead;
	while(tmp->next->next)
	{
		tmp = tmp->next;
	}
	Node *ptmp = tmp->next;
	free(ptmp);
	ptmp = NULL;
	tmp->next = NULL;
	list->size--;
	
}
//删除头
void listDeleteFront(List* list)
{
	Node *ptmp = list->phead->next;
	list->phead->next = list->phead->next->next;
	free(ptmp);
	ptmp = NULL;
	list->size--;
}
//删除指定位置
void listDeleteBySite(List* list,int site)
{
	Node *tmp = list->phead;
	while(site--)
	{
		tmp = tmp->next;
	}
	Node *ptmp = tmp->next;
	tmp->next = ptmp->next;
	free(ptmp);
	ptmp = NULL;
	list->size--;
}
//删除指定元素
void listDeleteByElem(List* list, Data data)
{
	//进行遍历
	Node *tmp = list->phead;
	Node *ptmp = NULL;
	while(tmp->next)
	{
		ptmp = tmp->next;
		if(memcmp(&(ptmp->data),&data,sizeof(Data)) == 0)
		{
			tmp->next = ptmp->next;
			free(ptmp);
			ptmp = NULL;
			list->size--;
		}
		tmp = tmp->next;
		if(tmp == NULL)
		{
			break;
		}
	}
	
}