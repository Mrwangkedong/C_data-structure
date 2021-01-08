#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include "../LineList.h"
typedef int bool;


//��struct Node *����Ϊ������LinkList����һ���ṹ���ָ�롣  
LinkedList SingleListInit()   //��ʼ��
{
	Node* L;  //����һ��ͷ���
	L = (Node*)malloc(sizeof(Node));//ͷ��������ַ
	if (L == NULL)
		printf("����ռ�ʧ��");
	L->next = NULL;
    //
	return L;
}

//ͷ�巨  ����������ã�
LinkedList CreateSingleListHead(int a[])
{
	int i;
	int x;
	Node* L;
	L = SingleListInit();
	for (i = 0; i < sizeof(a)+1; i++)
	{
		Node* p; //Ҫ����Ľ��
		p = (Node*)malloc(sizeof(Node));
		//scanf("%d", &x);
		p->data = a[i];
		p->next = L->next;
		L->next = p;
	}
	return L;
}

//β�巨
LinkedList CreateSingleListEnd(int a[]) {
	int x;
	Node* L = SingleListInit(); //��ʼ��һ��������
	Node* s, * r = L;  //rΪ��βָ��
	for (int i = 0; i < sizeof(a)+1; i++)
	{
		s = (Node*)malloc(sizeof(Node));
		s->data = a[i];
		r->next = s;
		r = s; //rָ���µı�β�ڵ�
	}
	r->next = NULL;//��β
	return L;
}

//λ�����
void SLInsertByIndex(LinkedList L,int index,int e) {
	//1.�ж�L��index �Ƿ�Ϸ�
	if (L == NULL)
	{
		exit(0);
	}
	//2.��ǰλ�� ����j,
	int j = 0;
	Node* p = L;  //ָ��p��ǰɨ��Ľڵ�
	//3.ѭ����i-1��λ��,j�ᵽ��index-1
	while (p!=NULL && j<index-1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)   //index-1֮ǰpͣ���ˣ�����indexֵ���Ϸ�
		exit(0);
	//�½�һ���ڵ�
	Node* s = (Node*)malloc(sizeof(Node));
	//����ֵ�ı任
	s->next = p->next;
	p->next = s;
	s->data = e;
}

//�ڵ�ǰ�巨��������s��s����p֮��pԭ�ȵ�ֵ����s��p�����µ�ֵ��
void SJInsertByNodeF(Node *p,int e) {
	if (p == NULL)
		exit(0);
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL)
		exit(0);  //��ַ���䲻�ɹ�
	s->next = p->next;
	s->data = p->data;
	p->data = e;
	p->next = s;
}

//�ڵ��巨��������s��s����p֮��s-next = p-next��p-next = s��
void SJInsertByNodeB(Node* p, int e) {
	if (p == NULL)
		exit(0);
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL)
		exit(0);  //��ַ���䲻�ɹ�
	s->next = p->next;
	s->data = e;
	p->next = s;
}

//��λ��ɾ����������ֵ���ͷŽڵ�  
void SJDeleteByIndex(LinkedList L, int index, int *e) {
	Node* p;  //���嵱ǰ�ڵ�
	p = L;
	int j = 0; //���嵱ǰ�ڵ�λ��
	//ѭ���ҵ�index-1λ
	while (p != NULL && j < index - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)   //index-1֮ǰpͣ���ˣ�����indexֵ���Ϸ�
		exit(0);
	//����ڵ�ָ��Ҫɾ���Ľڵ�
	Node* q = (Node*)malloc(sizeof(Node));
	q = p->next;  //���սڵ���Ϣ
	p->next = q->next;  //��index-1�ڵ����һ�ڵ�ָ��Ϊindex+1
	free(q); //�ͷŵ�ǰ�ڵ�
}

//ɾ��ָ���ڵ� ������һ���ڵ�ֵ���赱ǰ�ڵ㣬��Nextָ�����½ڵ㣩
//���������һ���ڵ㣬�Ͳ�����
void SJDeleteByNodeB(Node* p, int e){
	//������һ���ڵ�
	Node* q = p->next;
	//p��data���q��
	p->data = q->data;
	//p��next���q��
	p->next = q->next;
	free(q);
	}

//����
void SingleListOutput(LinkedList L)
{
	Node* p;
	for (p = L->next; p != NULL; p = p->next)
	{
		printf("%d", p->data);
	}
}

//��������Ƿ�Ϊ��
void SingleListEmpty(LinkedList L) {
	if (L->next == NULL)
	{
		printf("��Ϊ��");
	}
	else {
		printf("��");
	}
}

//��λ����
Node* SJSearchByIndex(LinkedList L,int index) {
	if (L == NULL)
		exit(0);
	Node* p = L;
	int j = 0;
	//ѭ������index
	while (p != NULL && j<index) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		exit(0);
	return p;
}

//��ֵ����
Node* SJSearchByValue(LinkedList L, int e) {
	if (L == NULL)
		exit(0);
	Node* p = L;
	//ѭ���ҵ�value
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
	
	//ͷ�巨ʵ��
	//printf("���뵥����ĳ��ȣ�ͷ�巨��:");
	//scanf("%d", &n);
	H = CreateSingleListHead(a);
	SingleListOutput(H);
	printf("\n");


	//β�巨
	//H = CreateSingleListEnd(a);
	//SingleListOutput(H);

	//��ѯ�ڵ�
	//Node* s;
	//s = SJSearchByIndex(H, 2);
	//printf("%d",s->data);
	
	return 0;
}
*/