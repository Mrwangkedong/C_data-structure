#include <stdio.h>
#include<stdlib.h>
#include "../LineList.h"
#define InitSize 10
#define MaxSize 10
#define bool int
#define true 1
#define false 0

/*
	˳���:
	  �ŵ㣺�������ȡ���洢�ܶȸ�
	  ȱ�㣺Ҫ���������ռ䣬�ı�����������
*/

//��ʼ���б�
void initList(SeqList *L) {
	L->data = (int *)malloc(InitSize*sizeof(int));
	L->Length = 0;
	L->Maxsize = InitSize;
}

//���Ӷ�̬���鳤��
void IncreaseSize(SeqList *L,int len) {
	int* p = L->data;  //���վɵ�����
	L->data = (int*)malloc((L->Maxsize + len) * sizeof(int));
	//���ݽ���Ǩ��
	for (int i = 0; i < L->Length; i++)
	{
		L->data[i] = p[i];
	}
	//���¹涨������󳤶� 
	L->Maxsize = L->Maxsize + len; 
	//�ͷ�ԭ�����ڴ�ռ�
	free(p);
}

//����
bool InsertCell(SeqList *L,int index ,int e) {
	//1.�жϲ���λ��i�Ƿ񳬳�
	if (index < 1 || index > L->Length + 1)
	{
		printf("index�����Ϲ涨\n");
		return false;  //�˳�
	}
	//2.�ж�L�Ƿ�����
	if (L->Length >= L->Maxsize)
	{
		printf("˳����Ѿ�����\n");
		return false;  //�˳�
	}
	//3.���к���
	for (int i = L->Length; i >= index; i--)
	{
		L->data[i] = L->data[i-1];
	}
	//4.����data[i]��ֵ
	L->data[index-1] = e;
	L->Length++;
	printf("����ɹ�\n");
	return true;
}

//ɾ��
bool DeleteCell(SeqList* L, int index, int *e) {
	//1.�жϺϷ���
	if (index < 1 || index > L->Length)
	{
		printf("����index���Ϸ�");
		return false;
	}
	//2.ȡ����ɾ��Ԫ�ص�ֵ
	*e = L->data[index - 1];
	//3.forѭ�����θ���
	for (int i = index; i < L->Length; i++)
	{
		L->data[i - 1] = L->data[i];
	}
	//4.���¸�Length��ֵ
	L->Length = L->Length - 1;
	//5.���سɹ�
	return true;

}

//��λ����
int SearchByIndex(SeqList L, int index) {
	return L.data[index - 1];
}
//��ֵ����
int SearchByCell(SeqList L, int e) {
	for (int i = 0; i < L.Length; i++)
	{
		if (L.data[i] == e)
		{
			return i + 1;
		}
	}
	return 0;  //����0������ʧ��
}

/***
int main() {
	SeqList L;   //��������
	initList(&L);
	IncreaseSize(&L,10);
	printf("%d",L.Maxsize);
	return 0;
}
**/