#include "list.h"

//��ʼ��˳���
List* init_list()
{
	List *list = (List*)malloc(sizeof(List));
	list->phead = (Node*)malloc(sizeof(Node));
	list->phead->next = NULL;
	return list;
}
//����˳���
void destroyList(List* list)
{
	clear_list(list);
	free(list->phead);
	list->phead = NULL;
	free(list);
	list = NULL;
}
//���˳���
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
//˳����Ƿ�Ϊ��
Bool listEmpty(List* list)
{
	return list->size == 0;
}
//˳���ĳ���
int listElemNum(List* list)
{
	return list->size;
}
//����һ���µĽ��
Node* CreatNode(Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//���뵽���
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
//���뵽ͷ
void listPushFront(List* list,Data data)
{
	Node *newNode = CreatNode(data);
	newNode->next = list->phead->next;
	list->phead->next = newNode;
	list->size++;

}
//���뵽ָ��λ��
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
//�õ�ͷԪ��
Data getlistBack(List* list)
{
	Node *tmp = list->phead;
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	return tmp->data;
	
}
//�õ�βԪ��
Data getlistFront(List* list)
{
	return list->phead->next->data;
}
//�õ�ָ��λ�õ�Ԫ��
Data getlistBySite(List* list ,int site)
{
	Node *tmp = list->phead;
	while(site--)
	{
		tmp = tmp->next;
	}
	return tmp->next->data;
}
//ɾ��β
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
//ɾ��ͷ
void listDeleteFront(List* list)
{
	Node *ptmp = list->phead->next;
	list->phead->next = list->phead->next->next;
	free(ptmp);
	ptmp = NULL;
	list->size--;
}
//ɾ��ָ��λ��
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
//ɾ��ָ��Ԫ��
void listDeleteByElem(List* list, Data data)
{
	//���б���
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