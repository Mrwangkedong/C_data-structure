#include<stdio.h>
#include<stdlib.h>
#include "../LineList.h"
#define bool int
#define false 0
#define true 1

//初始化一个队列（datatype-->int)
//extern void initSqQueue(SqQueue *Q);
//判断队列是否为空
//extern bool EmptySqQueue(SqQueue* Q);
//出队列
//extern int PopSqQueue(SqQueue* Q);
//入队列
//extern bool PushSqQueue(SqQueue* Q,int e);
//在图G中找顶点的第一个邻接点，找到返回顶点号，找不到返回-1
int FirstNeighbor(MGraph G,int x){

    for (int i = 0; i < 10; ++i) {
        if (G.Edge[x][i] != 0){
            return i;
        }
    }

    return -1;
}

//在图G中，y是x的一个邻接点，找除了y之外的另一个邻接点
int NextNeighbor(MGraph G,int x,int y){
    int e = y+1;
    for (int i = y+1; i < 10; ++i) {
        if (G.Edge[x][i] == 1){
            return i;
        }
    }

    return -1;
}
