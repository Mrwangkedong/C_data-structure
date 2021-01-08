//
// Created by Cristiano-Ronaldo on 2020/7/18.
//

#ifndef UNTITLED_LINELIST_H
#define UNTITLED_LINELIST_H
#include <stdio.h>
#define bool int
#define false 0
#define true 1


//邻接矩阵储存结构
typedef struct {
    char Vex[10];  //顶点表
    int Edge[10][10];  //邻接矩阵，边表
    int intvexnum,arcnum; //图的当前顶点数和弧数
}MGraph;


//邻接表结构
//x.1:边表节点
typedef struct ArcNode{
    int  adjvex;  //该弧所指向的顶点的位置
    struct ArcBode *next; //指向下一条弧的指针
//    int info    //网的边权值
}ArcNode;
//x.2：定点表节点
typedef struct VNode{
    char data;   //顶点信息
    ArcNode *first; //指向第一条依附于该顶点的弧的指针
}VNode,AdjList[10];
//x.3图
typedef struct {
    AdjList vertices;  //领接表
    int vexnum,arcnum;  //图的顶点数和弧数
} ALGraph;             //ALGraph是以邻接表储存的图类型

//串
typedef struct {
    char data[15];
    int length;
}SString;

//顺序表的链式
typedef struct
{
    int* data;
    int Maxsize;
    int Length;
}SeqList;

//单链表
typedef struct SNode  //用结构体定义结点
{
    int data;
    struct SNode* next;
}SNode, * LinkedList;

//双链表
typedef struct  {
    int data;
    struct DNode* pred;
    struct DNode* next;
}DNode;

//栈的顺序存储
#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int top;
}SqStack;

//栈的链式存储
typedef struct StackNode {
    int data;
    struct StackNode* next;
}StackNode,*LiStack;

//栈的链式存储(字符)
typedef struct StackCharNode {
    char data;
    struct StackCharNode* next;
}StackCharNode,*LiCharStack;


//队列的顺序存储
typedef struct
{
    int data[MaxSize];
    int front, rear;  //队头指针、队尾指针
}SqQueue;

//二叉树
typedef struct BiTNode{
    int data;
    struct BiTNode *lchile;
    struct BiTNode *rchile;
}BiTNode,*Bitree;

//树的线性
typedef struct TNode  //用结构体定义结点
{
    Bitree T;
    struct TNode* next;
}TNode, * LinkTree;
//树的队列
typedef struct TreeQueueNode{
    TNode *front; //对头
    TNode *rear;
}TreeQueueNode,*LinkTreeQueue;

//树的栈
typedef struct TreeStackNode{
    Bitree T;
    struct TreeStackNode* next;
}TreeStackNode,*LinkTreeStack;

//线索二叉树
typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild,*rchild; //左右树
    int ltag,rtag;  //左右线索标志
}ThreadNode,*ThreadTree;



//初始化一个队列（datatype-->int)
extern void initSqQueue(SqQueue *Q);
//判断队列是否为空
extern bool EmptySqQueue(SqQueue* Q);
//出队列
extern int PopSqQueue(SqQueue* Q);
//入队列
extern bool PushSqQueue(SqQueue* Q,int e);
//在图G中找顶点的第一个邻接点，找到返回顶点号，找不到返回-1
extern int FirstNeighbor(MGraph G,int x);
//在图G中，y是x的一个邻接点，找除了y之外的另一个邻接点
extern int NextNeighbor(MGraph G,int x,int y);
//对图G进行广度优先遍历
extern void BFSTraverse(MGraph G);
///对图G进行深度优先遍历
extern void DFSTraverse(MGraph G);
//从点v出发，对图G进行深度优先遍历
extern void DFS(MGraph G,int v);

#endif //UNTITLED_LINELIST_H
