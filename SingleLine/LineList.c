#include <stdio.h>
#include<stdlib.h>
#include "../LineList.h"
#define InitSize 10
#define MaxSize 10
#define bool int
#define true 1
#define false 0

/*
	顺序表:
	  优点：可随机存取，存储密度高
	  缺点：要求答辩连续空间，改变容量不方便
*/

//初始化列表
void initList(SeqList *L) {
	L->data = (int *)malloc(InitSize*sizeof(int));
	L->Length = 0;
	L->Maxsize = InitSize;
}

//增加动态数组长度
void IncreaseSize(SeqList *L,int len) {
	int* p = L->data;  //接收旧的数组
	L->data = (int*)malloc((L->Maxsize + len) * sizeof(int));
	//数据进行迁移
	for (int i = 0; i < L->Length; i++)
	{
		L->data[i] = p[i];
	}
	//重新规定数组最大长度 
	L->Maxsize = L->Maxsize + len; 
	//释放原来的内存空间
	free(p);
}

//插入
bool InsertCell(SeqList *L,int index ,int e) {
	//1.判断插入位置i是否超出
	if (index < 1 || index > L->Length + 1)
	{
		printf("index不符合规定\n");
		return false;  //退出
	}
	//2.判断L是否已满
	if (L->Length >= L->Maxsize)
	{
		printf("顺序表已经满了\n");
		return false;  //退出
	}
	//3.进行后移
	for (int i = L->Length; i >= index; i--)
	{
		L->data[i] = L->data[i-1];
	}
	//4.进行data[i]赋值
	L->data[index-1] = e;
	L->Length++;
	printf("插入成功\n");
	return true;
}

//删除
bool DeleteCell(SeqList* L, int index, int *e) {
	//1.判断合法性
	if (index < 1 || index > L->Length)
	{
		printf("输入index不合法");
		return false;
	}
	//2.取出被删除元素的值
	*e = L->data[index - 1];
	//3.for循环依次覆盖
	for (int i = index; i < L->Length; i++)
	{
		L->data[i - 1] = L->data[i];
	}
	//4.重新给Length赋值
	L->Length = L->Length - 1;
	//5.返回成功
	return true;

}

//按位查找
int SearchByIndex(SeqList L, int index) {
	return L.data[index - 1];
}
//按值查找
int SearchByCell(SeqList L, int e) {
	for (int i = 0; i < L.Length; i++)
	{
		if (L.data[i] == e)
		{
			return i + 1;
		}
	}
	return 0;  //返回0，查找失败
}

/***
int main() {
	SeqList L;   //声明链表
	initList(&L);
	IncreaseSize(&L,10);
	printf("%d",L.Maxsize);
	return 0;
}
**/