#include<stdio.h>
#include<stdlib.h>
#include "../LineList.h"
#define bool int
#define false 0
#define true 1

//��struct Node *����Ϊ������LinkList����һ���ṹ���ָ�롣  
LiCharStack StackCharListInit()   //��ʼ��
{
	StackCharNode* L;  //����һ��ͷ���
	L = (StackCharNode*)malloc(sizeof(StackCharNode));//ͷ��������ַ
	if (L == NULL)
		printf("����ռ�ʧ��");
	L->next = NULL;

	return L;
}

//ջ��Ԫ��
char GetStackTopChar(LiCharStack S){
    if (S == NULL || S->next == NULL)
        return 'x';  //��ʾ��ʱջ��
    return S->next->data;
}

//��ջ����
void PushStackChar(LiCharStack S, char e) {
	if (S == NULL)
		exit(0);
	StackCharNode* s = (StackCharNode*)malloc(sizeof(StackCharNode));
	if (s == NULL)
		exit(0);  //��ַ���䲻�ɹ�
	s->next = S->next;
	s->data = e;
	S->next = s;
	printf("%c��ջ�ɹ�\n", e);
}


//��ջ����
void  PopStackChar(LiCharStack S) {
	if (S == NULL || S->next==NULL)
		exit(0);

	StackCharNode* p = S->next;

	S->next = p->next;
    printf("%c��ջ�ɹ�\n",p->data);
	free(p);
}

//�ж��Ƿ�Ϊ��
bool EmptyStackChar(LiCharStack S){
    if(S==NULL || S->next==NULL)
        return true;
    else
        return false;
}

//
//void main() {
//	LiCharStack S = StackCharListInit();
//	char e; //ջ��Ԫ��
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