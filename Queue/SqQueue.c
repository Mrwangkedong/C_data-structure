#include<stdio.h>
#include<stdlib.h>
#include "../LineList.h"
#define bool int
#define false 0
#define true 1

/*
	循环队列
*/

//初始化
void initSqQueue(SqQueue *Q) {
	Q->front = Q->rear = 0;
}
//队列是否为空,少用一个单元用来判别循环队列的空还是满
bool EmptySqQueue(SqQueue* Q) {
	if ((Q->rear + 1) % MaxSize == Q->front)
		return false;        //满了
		
	if (Q->rear == Q->front)
		return true;
	else
		return false;
	
}
//判断满不满
bool FullSqQueue(SqQueue* Q) {
	if ((Q->rear + 1) % MaxSize == Q->front)
		return true;
	else
		return false;
}
//进队列
bool PushSqQueue(SqQueue* Q,int e) {
	if (!FullSqQueue(Q)) {
		Q->data[Q->rear] = e;
		Q->rear = (Q->rear + 1) % MaxSize;
		return true;
	}
	else
		return false;
}
//出队列
int PopSqQueue(SqQueue* Q) {
	if (Q->front != Q->rear) {
		int e = Q->data[Q->front];
		Q->front = (Q->front + 1) % MaxSize;
		return e;
	}
	else
		return -1;
}
