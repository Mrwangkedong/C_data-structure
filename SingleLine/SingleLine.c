#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include "../LineList.h"
typedef int bool;


//把struct Node *定义为新类型LinkList，是一个结构体的指针。  
LinkedList SingleListInit()   //初始化
{
	Node* L;  //定义一个头结点
	L = (Node*)malloc(sizeof(Node));//头结点申请地址
	if (L == NULL)
		printf("申请空间失败");
	L->next = NULL;
    //
	return L;
}

//头插法  （链表的逆置）
LinkedList CreateSingleListHead(int a[])
{
	int i;
	int x;
	Node* L;
	L = SingleListInit();
	for (i = 0; i < sizeof(a)+1; i++)
	{
		Node* p; //要插入的结点
		p = (Node*)malloc(sizeof(Node));
		//scanf("%d", &x);
		p->data = a[i];
		p->next = L->next;
		L->next = p;
	}
	return L;
}

//尾插法
LinkedList CreateSingleListEnd(int a[]) {
	int x;
	Node* L = SingleListInit(); //初始化一个单链表
	Node* s, * r = L;  //r为表尾指针
	for (int i = 0; i < sizeof(a)+1; i++)
	{
		s = (Node*)malloc(sizeof(Node));
		s->data = a[i];
		r->next = s;
		r = s; //r指向新的表尾节点
	}
	r->next = NULL;//结尾
	return L;
}

//位序插入
void SLInsertByIndex(LinkedList L,int index,int e) {
	//1.判断L、index 是否合法
	if (L == NULL)
	{
		exit(0);
	}
	//2.当前位置 变量j,
	int j = 0;
	Node* p = L;  //指针p当前扫描的节点
	//3.循环到i-1的位置,j会到达index-1
	while (p!=NULL && j<index-1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)   //index-1之前p停下了，所以index值不合法
		exit(0);
	//新建一个节点
	Node* s = (Node*)malloc(sizeof(Node));
	//进行值的变换
	s->next = p->next;
	p->next = s;
	s->data = e;
}

//节点前插法（新申请s、s放在p之后、p原先的值置于s、p放置新的值）
void SJInsertByNodeF(Node *p,int e) {
	if (p == NULL)
		exit(0);
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL)
		exit(0);  //地址分配不成功
	s->next = p->next;
	s->data = p->data;
	p->data = e;
	p->next = s;
}

//节点后插法（新申请s、s放在p之后、s-next = p-next、p-next = s）
void SJInsertByNodeB(Node* p, int e) {
	if (p == NULL)
		exit(0);
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL)
		exit(0);  //地址分配不成功
	s->next = p->next;
	s->data = e;
	p->next = s;
}

//按位序删除，并带回值，释放节点  
void SJDeleteByIndex(LinkedList L, int index, int *e) {
	Node* p;  //定义当前节点
	p = L;
	int j = 0; //定义当前节点位序
	//循环找到index-1位
	while (p != NULL && j < index - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)   //index-1之前p停下了，所以index值不合法
		exit(0);
	//定义节点指向要删除的节点
	Node* q = (Node*)malloc(sizeof(Node));
	q = p->next;  //接收节点信息
	p->next = q->next;  //将index-1节点的下一节点指定为index+1
	free(q); //释放当前节点
}

//删除指定节点 （将下一个节点值赋予当前节点，并Next指向下下节点）
//假如是最后一个节点，就不能了
void SJDeleteByNodeB(Node* p, int e){
	//接收下一个节点
	Node* q = p->next;
	//p的data变成q的
	p->data = q->data;
	//p的next变成q的
	p->next = q->next;
	free(q);
	}

//遍历
void SingleListOutput(LinkedList L)
{
	Node* p;
	for (p = L->next; p != NULL; p = p->next)
	{
		printf("%d", p->data);
	}
}

//检测链表是否为空
void SingleListEmpty(LinkedList L) {
	if (L->next == NULL)
	{
		printf("不为空");
	}
	else {
		printf("空");
	}
}

//按位查找
Node* SJSearchByIndex(LinkedList L,int index) {
	if (L == NULL)
		exit(0);
	Node* p = L;
	int j = 0;
	//循环到达index
	while (p != NULL && j<index) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		exit(0);
	return p;
}

//按值查找
Node* SJSearchByValue(LinkedList L, int e) {
	if (L == NULL)
		exit(0);
	Node* p = L;
	//循环找到value
	while (p != NULL) {
		if (p->data == e)
			return p;
		p = p->next;
	}
	if (p == NULL)
		exit(0);
	return p;
}

/*
int main()
{
	int n;
	int i;
	int x;
	int a[5] = {0, 1, 2, 3, 4};
	LinkedList H;
	H = SingleListInit();
	SingleListEmpty(H);
	
	//头插法实验
	//printf("输入单链表的长度（头插法）:");
	//scanf("%d", &n);
	H = CreateSingleListHead(a);
	SingleListOutput(H);
	printf("\n");


	//尾插法
	//H = CreateSingleListEnd(a);
	//SingleListOutput(H);

	//查询节点
	//Node* s;
	//s = SJSearchByIndex(H, 2);
	//printf("%d",s->data);
	
	return 0;
}
*/