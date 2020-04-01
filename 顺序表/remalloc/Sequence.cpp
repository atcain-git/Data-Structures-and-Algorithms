#include "init.h"
#include "Sequence.h"
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

Status init_sqlist(SqList &L)//����ձ�L
{
	L.length=0;
	return OK;
}

Status insert_list(SqList &L,int i,Item e)//����eԪ�ص���iλ
{
	if (i<1||i>L.length+1)
	{
		return ERROR;//iֵ���Ϸ�
	}

    Item *q,*p;
	q=&L.add[i-1];//qΪ����λ��
	for (p=&L.add[L.length-1];p>=q;--p)
	{
		*(p+1)=*p;
	}//����λ�ü�֮��Ԫ�ص�λ������
	*q=e;//����e
	++L.length;//������1
	return OK;
}

Status delete_list(SqList &L,int i,Item &e)//��˳�����ɾ����i��Ԫ�أ�����eֵ
{
	if (i<1||i>L.length)
	{
		return ERROR;
	}
	Item *p,*q;
	p=&L.add[i-1];//pΪ��ɾ����Ԫ�ص�λ��
	e=*p;//��ɾ����Ԫ�ظ�ֵ��e
	q=L.add+L.length-1;//��βԪ�ص�λ��
	for (++p;p<=q;++p)
	{
		*(p-1)=*p;
	}//ɾԪ�غ�Ԫ������
	--L.length;//����һ
	return OK;
}

Status display_list(SqList L)
{
	printf("˳����е�Ԫ�أ�\n");
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
		i=1;//����-1
	else if(*a == *b)
		i=0;
	else 
		i=-1;
	return i;
}
Status merge_list(SqList La,SqList Lb,SqList &Lc)//�ϲ������б�
{
	Item *pa,*pb,*pc;
	pa=La.add;
	pb=Lb.add;
	Lc.length=La.length+Lb.length;

	pc=Lc.add;
	if (!Lc.add)exit(OVERFLOW);//�洢����ʧ��
	while (pa<La.add+La.length && pb<Lb.add+Lb.length)//�鲢
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
		*(pc++)=*(pa++);//����laʣ���Ԫ��
	}
	while (pb<Lb.add+Lb.length) {
		*(pc++)=*(pb++);//����lbʣ���Ԫ��

	}
 	return OK;
}