#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include "LineList.h"
extern void initList(SeqList* L);
extern int InsertCell(SeqList* L, int index, int e);
typedef int bool;


//ת��,fromIndex��ʼλ�ã�toIndex����λ��
void Reverse(SeqList *L,int fromIndex,int toIndex) {
	int temp;

	if (fromIndex < 1 || toIndex >L->Length)
		exit(0);
	int length = toIndex - fromIndex + 1;
	for (int i = 0; i < length/2; i++)
	{
		temp = L->data[i+fromIndex-1];
		L->data[i + fromIndex - 1] = L->data[toIndex-i-1];
		L->data[toIndex - i - 1] = temp;
	}

}

//����
void OutputList(SeqList L) {
	for (int i = 0; i < L.Length; i++)
	{
		printf("%d\n",L.data[i]);
	}
}

/*
void main() {
	SeqList L;
	initList(&L);  //��ʼ��
	for (int i = 0; i < 5; i++)  //��������
	{
		InsertCell(&L,i+1,i);
	}
	OutputList(L);
	Reverse(&L,3,L.Length);
	printf("**************\n");
	OutputList(L);

}
*/