#ifndef _SEQUENCE_H

#define LISTSIZE 100 
//ע�⣺Item��ʱֻ�ܶ���Ϊ�������ͣ���Ϊ��ʵ�ֵ�ʱ��û��molloc(sizeof(Item)�����������иı�item�Ĵ�С
#define LISTINCEREMENT 10
typedef int Item;

typedef struct  
{
	Item add[LISTSIZE];
	int length;
}SqList;


Status init_sqlist(SqList &L);
Status insert_list(SqList &L,int i,Item e);//����Ԫ��e��˳���б�ĵ�i��λ��
Status delete_list(SqList &L,int i,Item &e);//ɾ����i��Ԫ�ز����ظ�e��
Status display_list(SqList);
Status merge_list(SqList La,SqList Lb,SqList &Lc);//�ϲ�����˳���б�


#endif 
