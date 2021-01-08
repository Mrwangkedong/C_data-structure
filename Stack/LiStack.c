#include<stdio.h>
#include<stdlib.h>
#include "../LineList.h"
#define bool int
#define false 0
#define true 1

//把struct Node *定义为新类型LinkList，是一个结构体的指针。  
LiCharStack StackCharListInit()   //初始化
{
	StackCharNode* L;  //定义一个头结点
	L = (StackCharNode*)malloc(sizeof(StackCharNode));//头结点申请地址
	if (L == NULL)
		printf("申请空间失败");
	L->next = NULL;

	return L;
}

//栈顶元素
char GetStackTopChar(LiCharStack S){
    if (S == NULL || S->next == NULL)
        return 'x';  //表示此时栈空
    return S->next->data;
}

//入栈操作
void PushStackChar(LiCharStack S, char e) {
	if (S == NULL)
		exit(0);
	StackCharNode* s = (StackCharNode*)malloc(sizeof(StackCharNode));
	if (s == NULL)
		exit(0);  //地址分配不成功
	s->next = S->next;
	s->data = e;
	S->next = s;
	printf("%c入栈成功\n", e);
}


//出栈操作
void  PopStackChar(LiCharStack S) {
	if (S == NULL || S->next==NULL)
		exit(0);

	StackCharNode* p = S->next;

	S->next = p->next;
    printf("%c出栈成功\n",p->data);
	free(p);
}

//判断是否为空
bool EmptyStackChar(LiCharStack S){
    if(S==NULL || S->next==NULL)
        return true;
    else
        return false;
}

//
//void main() {
//	LiCharStack S = StackCharListInit();
//	char e; //栈顶元素
//	char a = 'a';
//
//	PushStackChar(S,a);
//	PushStackChar(S, a);
//	PushStackChar(S, a);
//
//	PopStackChar(S, &e);
//
//
//	printf("\n%c",a);
//
//
//
//}