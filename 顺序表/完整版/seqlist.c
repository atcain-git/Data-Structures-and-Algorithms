#include "seqlist.h"
 #include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int *node;   //int* node[]
}TSeqList;

SeqList* SeqList_Create(int capacity)
{
	int ret = 0;
	TSeqList *tmp = NULL; 
	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if(tmp == NULL)
	{
		ret = -1;
		printf("func err SeqList_Create():%d",ret);
		return NULL;
	}
	memset(tmp,0,sizeof(TSeqList));

	//根据capacity分配内存空间
	tmp->node = (unsigned int *)malloc(sizeof(unsigned int*)*capacity);
	if(tmp->node == NULL)
	{
		ret = -2;
		printf("func err malloc_SeqList_Create : %d",ret);
		return NULL;
	}
	tmp->capacity = capacity;
	tmp->length = 0;
	return tmp;
}

void SeqList_Destroy(SeqList* list)
{
	TSeqList *tlist = NULL;
	if(list == NULL)
	{
		return ;
	}
	tlist =(TSeqList *) list;
	if(tlist->node !=NULL)
	{
		free(tlist->node);
	}
	free(tlist);

	return ;
}

void SeqList_Clear(SeqList* list)
{
	TSeqList *tlist = NULL;
	if(list == NULL)
	{
		return ;
	}
	tlist =(TSeqList *) list;
	tlist->capacity = 0;
	tlist->length = 0;
	return ;
}

int SeqList_Length(SeqList* list)
{
	TSeqList *tlist = NULL;
	if(list == NULL)
	{
		return -1;
	}
	tlist =(TSeqList *) list;
	return tlist->length;
}

int SeqList_Capacity(SeqList* list)
{
	TSeqList *tlist = NULL;
	if(list == NULL)
	{
		return -1;
	}
	tlist =(TSeqList *) list;
	return tlist->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	int i =0, ret = 0;
	TSeqList *tlist = NULL;

	if (list == NULL || node==NULL ||  pos<0)
	{
		ret = -1;
		printf("fun SeqList_Insert() err:%d \n", ret);
		return ret;
	}
	tlist = (TSeqList*)list;
	if(tlist->length >= tlist->capacity)
	{
		ret = -2;
		printf("func err SeqList_Insert():tlist->length >= tlist->capacity():%d",ret );
		return ret;
	}
	//位置错误判断
	if (pos<0 || pos>=tlist->capacity)
	{
		return -3;
	}
	if(pos >= tlist->length)
	{
		pos = tlist->length;
	}
	for(i = tlist->length;i>pos;i--)
	{
		tlist->node[i] = tlist->node[i-1];
	}
	tlist->node[pos] = (unsigned int )node;
	tlist->length++;

	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	int i = 0;
	SeqListNode *ret = 0;
	TSeqList *tlist = NULL;
	if(list == NULL || pos <0)
	{
		printf("func SeqList_Get()err()\n");
		return NULL;
	}
	tlist = (TSeqList *)list;
	ret = (void *)tlist->node[pos];
	return ret;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	int					i;
	TSeqList				*tList = NULL;
	SeqListNode			*ret = NULL; 
	tList = (TSeqList *)list;

	if (list==NULL || pos<0 || pos>=tList->length)
	{
		return NULL;
	}

	//赋给a3之前，要把a3元素缓存下来
	ret = (SeqListNode *)tList->node[pos];
	//删除算法
	for (i=pos+1; i<tList->length; i++)
	{
		tList->node[i-1] = tList->node[i];
	}
	tList->length --;

	return ret;
}
 