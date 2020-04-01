#include "init.h"
#include "Sequence.h"
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

Status init_sqlist(SqList &L)//构造空表L
{
	L.length=0;
	return OK;
}

Status insert_list(SqList &L,int i,Item e)//插入e元素到第i位
{
	if (i<1||i>L.length+1)
	{
		return ERROR;//i值不合法
	}

    Item *q,*p;
	q=&L.add[i-1];//q为插入位置
	for (p=&L.add[L.length-1];p>=q;--p)
	{
		*(p+1)=*p;
	}//插入位置及之后元素的位置右移
	*q=e;//插入e
	++L.length;//表长增加1
	return OK;
}

Status delete_list(SqList &L,int i,Item &e)//在顺序表中删除第i个元素，返回e值
{
	if (i<1||i>L.length)
	{
		return ERROR;
	}
	Item *p,*q;
	p=&L.add[i-1];//p为被删除的元素的位置
	e=*p;//被删除的元素赋值给e
	q=L.add+L.length-1;//表尾元素的位置
	for (++p;p<=q;++p)
	{
		*(p-1)=*p;
	}//删元素后元素左移
	--L.length;//表长减一
	return OK;
}

Status display_list(SqList L)
{
	printf("顺序表中的元素：\n");
	for (int i=0;i<L.length;i++)
	{
		cout<<L.add[i]<<endl;
	}
	printf("\n");
	return OK;
}
Status compare(Item *a,Item *b)
{
	int i;
	if(*a<*b)
		i=1;//升序-1
	else if(*a == *b)
		i=0;
	else 
		i=-1;
	return i;
}
Status merge_list(SqList La,SqList Lb,SqList &Lc)//合并两个列表
{
	Item *pa,*pb,*pc;
	pa=La.add;
	pb=Lb.add;
	Lc.length=La.length+Lb.length;

	pc=Lc.add;
	if (!Lc.add)exit(OVERFLOW);//存储分配失败
	while (pa<La.add+La.length && pb<Lb.add+Lb.length)//归并
	{
		switch (compare( pa , pb))
		{
		case  0: 
			*pc++=*pa++;
			break;
		case  1:
			*pc++=*pa++;
			break;
		case  -1:
			*pc++=*pb++;
			break;
		}
	}

	while (pa<La.add+La.length) {
		*(pc++)=*(pa++);//插入la剩余的元素
	}
	while (pb<Lb.add+Lb.length) {
		*(pc++)=*(pb++);//插入lb剩余的元素

	}
 	return OK;
}