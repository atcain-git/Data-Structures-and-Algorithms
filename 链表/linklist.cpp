#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
typedef int ElementType;
typedef struct ListNode *PtrToNode;
typedef PtrToNode List;
struct ListNode{
	ElementType Data;
	PtrToNode next;
};

List createList(){
	List list = new ListNode;
	list->next = NULL;
	if(list == NULL){
		return NULL;
	}
	return list;
}
List insertNode(List list,int pos,ElementType value){
	if(list == NULL){
		return NULL;
	}
	List cur = list;
	PtrToNode node = (PtrToNode)malloc(sizeof(ListNode));
	node->next = NULL;
	node->Data = value;
	for(int i = 0;i <pos - 1 && cur->next;i++){
		cur = cur->next;
	}
	node->next = cur->next;
	cur->next = node;
	return list;
}


ElementType getNode(List list,int num){
	if(list == NULL){
		return NULL;
	}
	List cur = list;
	for(int i = 0;i<num;i++){
		cur = cur->next;
	}
	return cur->Data;
}
void delNode(List list,int num){
	if(list == NULL){
		return ;
	}
	List cur = list;
	PtrToNode left;
	for(int i = 0;i<num - 1&&cur->next != NULL;i++){
		cur = cur->next;
	}
	left = cur;
	cur = cur->next;
	left->next = cur->next;
}
void updateNode(List list,int num,ElementType value){
	if(list == NULL){
		return ;
	}
	List cur = list;
	for(int i=0;i<num && cur->next;i++){
		cur = cur->next;
	}
	cur->Data = value;
}
void printList(List list){
	if(list == NULL){
		return ;
	}
	list = list->next;
	while(list){
		cout<<list->Data<<endl;
		list = list->next;
	}
}
void main(int argc, char *argv[])
{	
	List list = createList();
	list = insertNode(list,1,1);
	list = insertNode(list,2,2);
	delNode(list,1);
	list = insertNode(list,2,2);
	list = insertNode(list,4,4);
	updateNode(list,3,4);
	printList(list);
	system("pause");
	return ;
}
