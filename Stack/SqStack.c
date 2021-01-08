#include<stdio.h>
#include<stdlib.h>
#include "../LineList.h"
#define bool int
#define false 0
#define true 1

//顺序栈的基本方法

//初始化
void initSqStack(SqStack *S) {
	S->top = -1;   //表示栈空
}

//查看是否为空
bool emptySqStack(SqStack *S) {
	if (S->top == -1)
		return true; 
	else
		return false;
}
//进栈
bool PushSqStack(SqStack* S,int e) {
	if (S->top == MaxSize - 1)
		return false;
	S->data[++S->top] = e;
	return true;
}
//出栈
bool PopSqStack(SqStack* S, const int* e) {
	if (S->top == -1)
		return false;
	e = (const int *) S->data[S->top];  //取出元素
	S->top--;  //数量减少1
	return true;
}
//读取栈定元素
bool GetTopSqStack(SqStack* S, const int* e) {
	if (S->top == -1)
		return false;
	e = (const int *) S->data[S->top];
	return true;
}