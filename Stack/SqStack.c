#include<stdio.h>
#include<stdlib.h>
#include "../LineList.h"
#define bool int
#define false 0
#define true 1

//˳��ջ�Ļ�������

//��ʼ��
void initSqStack(SqStack *S) {
	S->top = -1;   //��ʾջ��
}

//�鿴�Ƿ�Ϊ��
bool emptySqStack(SqStack *S) {
	if (S->top == -1)
		return true; 
	else
		return false;
}
//��ջ
bool PushSqStack(SqStack* S,int e) {
	if (S->top == MaxSize - 1)
		return false;
	S->data[++S->top] = e;
	return true;
}
//��ջ
bool PopSqStack(SqStack* S, const int* e) {
	if (S->top == -1)
		return false;
	e = (const int *) S->data[S->top];  //ȡ��Ԫ��
	S->top--;  //��������1
	return true;
}
//��ȡջ��Ԫ��
bool GetTopSqStack(SqStack* S, const int* e) {
	if (S->top == -1)
		return false;
	e = (const int *) S->data[S->top];
	return true;
}