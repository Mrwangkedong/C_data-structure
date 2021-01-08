//
// Created by Cristiano-Ronaldo on 2020/7/22.
//

#include<stdio.h>
#include<stdlib.h>
#include "../LineList.h"
#define bool int
#define false 0
#define true 1

//初始化
LinkTreeQueue TreeQueueInit(){
   LinkTreeQueue TQ = (LinkTreeQueue)malloc(sizeof(TreeQueueNode));
   TQ->front = TQ->rear = (TNode*)malloc(sizeof(TNode));
   TQ->front->next = NULL;
    return TQ;
}

//入队
void EnTreeQueue(LinkTreeQueue TQ,BiTNode* T){
    TNode* TN = (TNode*)malloc(sizeof(TNode));
    TN->T = T; TN->next = NULL;
    TQ->rear->next = TN;
    TQ->rear = TN;
}
//出队
void DeTreeQueue(LinkTreeQueue TQ){
    TNode* TN = TQ->front->next;
    TQ->front->next = TN->next;
    if(TQ->rear == TN)
        TQ->rear = TQ->front;
    free(TN);
}
//获得队顶元素
Bitree TopTreequeue(LinkTreeQueue TQ){
    return TQ->front->next->T;
}