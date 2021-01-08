#include<stdio.h>
#include<stdlib.h>
#include "../LineList.h"
#define bool int
#define false 0
#define true 1

/*
	ѭ������
*/

//��ʼ��
void initSqQueue(SqQueue *Q) {
	Q->front = Q->rear = 0;
}
//�����Ƿ�Ϊ��,����һ����Ԫ�����б�ѭ�����еĿջ�����
bool EmptySqQueue(SqQueue* Q) {
	if ((Q->rear + 1) % MaxSize == Q->front)
		return false;        //����
		
	if (Q->rear == Q->front)
		return true;
	else
		return false;
	
}
//�ж�������
bool FullSqQueue(SqQueue* Q) {
	if ((Q->rear + 1) % MaxSize == Q->front)
		return true;
	else
		return false;
}
//������
bool PushSqQueue(SqQueue* Q,int e) {
	if (!FullSqQueue(Q)) {
		Q->data[Q->rear] = e;
		Q->rear = (Q->rear + 1) % MaxSize;
		return true;
	}
	else
		return false;
}
//������
int PopSqQueue(SqQueue* Q) {
	if (Q->front != Q->rear) {
		int e = Q->data[Q->front];
		Q->front = (Q->front + 1) % MaxSize;
		return e;
	}
	else
		return -1;
}
