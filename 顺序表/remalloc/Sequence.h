#ifndef _SEQUENCE_H

#define LISTSIZE 100 
//注意：Item暂时只能定义为基本类型，因为在实现的时候没有molloc(sizeof(Item)），可以自行改变item的大小
#define LISTINCEREMENT 10
typedef int Item;

typedef struct  
{
	Item add[LISTSIZE];
	int length;
}SqList;


Status init_sqlist(SqList &L);
Status insert_list(SqList &L,int i,Item e);//插入元素e到顺序列表的第i个位置
Status delete_list(SqList &L,int i,Item &e);//删除第i个元素并返回给e；
Status display_list(SqList);
Status merge_list(SqList La,SqList Lb,SqList &Lc);//合并两个顺序列表


#endif 
