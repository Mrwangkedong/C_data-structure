//
// Created by Cristiano-Ronaldo on 2020/7/26.
//
#include<stdio.h>
#include<stdlib.h>
#include "../LineList.h"
#define bool int
#define false 0
#define true 1
//二叉树栈的初始化
LinkTreeStack TreeStackInit(){
    LinkTreeStack TS;
    TS = (TreeStackNode*)malloc(sizeof(TreeStackNode));
    if(TS == NULL)
        printf("申请空间失败");
    TS->next = NULL;

    return TS;
}

//获得栈顶元素
Bitree TreeStackTop(LinkTreeStack TS){
    if(TS == NULL || TS->next == NULL)
        return NULL;
    return TS->next->T;
}

//入栈操作
void TreeStackPush(LinkTreeStack TS,Bitree T){
    if(TS == NULL)
        exit(0);
    LinkTreeStack ts = (TreeStackNode*)malloc(sizeof(TreeStackNode));
    if(ts == NULL)
        exit(0);
    ts->next = TS->next;
    ts->T = T;
    TS->next = ts;
}

//出栈操作
void TreeStackPop(LinkTreeStack TS){
    if(TS == NULL || TS->next == NULL)
        exit(0);
    TreeStackNode* ts = TS->next;

    TS->next = ts->next;
    free(ts->T);
    free(ts);
}
//判断栈空
bool TreeStackEmpty(LinkTreeStack TS){
    if(TS == NULL || TS->next == NULL)
        return true;
    else
        return false;

}
//遍历栈
void TreeStackPrint(LinkTreeStack TS){
    while(!TreeStackEmpty(TS)){
        Bitree p = TreeStackTop(TS);
        printf("%d->",p->data);
        TreeStackPop(TS);
    }
}

