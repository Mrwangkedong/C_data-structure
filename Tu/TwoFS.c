#include<stdio.h>
#include<stdlib.h>
#include "../LineList.h"
#define bool int
#define false 0
#define true 1

extern void DFS(MGraph G,int v);
extern void BFS(MGraph G,int v);

//标记数组，记录当前节点是否被访问过
bool visited[10];
//队列
SqQueue Q;

//对图G进行广度优先遍历
void BFSTraverse(MGraph G){
    for (int i = 0; i < 5; ++i) {
        visited[i] = false;
    }
    initSqQueue(&Q);
    for (int j = 0; j < 5; ++j) {
        if(!visited[j])
            BFS(G,j);
    }

}

//从点v出发，对图G进行广度优先遍历
void BFS(MGraph G,int v){
    printf("%d\t",v); //对节点V进行访问
    visited[v] = true;  //进行已访问标记
    PushSqQueue(&Q,v);  //进行入队操作

    while (!EmptySqQueue(&Q)){
        v = PopSqQueue(&Q);  //出队
        for (int w = FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)) {
                                //检测v的所有邻接点
                if(!visited[w]){
                    printf("%d\t",w);
                    visited[w] = true;
                    PushSqQueue(&Q,w);
                }
        }
    }


}

///对图G进行深度优先遍历
void DFSTraverse(MGraph G){
    for (int i = 0; i < 5; ++i) {
        visited[i] =false;
    }
    for (int j = 0; j < 5; ++j) {
        if(!visited[j])
            DFS(G,j);
    }
}

//从点v出发，对图G进行深度优先遍历
void DFS(MGraph G,int v){
    printf("%d\t",v);
    visited[v] = true;
    for (int w = FirstNeighbor(G,v); w>=0 ; w=NextNeighbor(G,v,w)) {
        if(!visited[w]){
            DFS(G,w);
        }
    }
}


