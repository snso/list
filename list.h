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


//��ʼ��˳���
List* init_list();
//����˳���
void destroyList(List* list);
//���˳���
void clear_list(List* list);
//˳����Ƿ�Ϊ��
Bool listEmpty(List* list);
//˳����д洢Ԫ�صĸ���
int listElemNum(List* list);
//���뵽���
void listPushBack(List* list, Data data);
//���뵽ͷ
void listPushFront(List* list, Data data);
//���뵽ָ��λ��
void listInsert(List* list, int site, Data data);
//�õ�ͷԪ��
Data getlistBack(List* list);
//�õ�βԪ��
Data getlistFront(List* list);
//�õ�ָ��λ�õ�Ԫ��
Data getlistBySite(List* list, int site);
//ɾ��β��
void listDeleteBack(List* list);
//ɾ��ͷ
void listDeleteFront(List* list);
//ɾ��ָ��λ��
void listDeleteBySite(List* list,int site);
//ɾ��ָ��Ԫ��
void listDeleteByElem(List* list, Data data);





#endif