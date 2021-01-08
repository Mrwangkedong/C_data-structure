//
// Created by Cristiano-Ronaldo on 2020/7/24.
//线索二叉树(中序)
//未实现，需要实现1、创建基础线索二叉树；2、创建遍历（ltag/data/rtag）
#include "../LineList.h"
#include <stdlib.h>
#include <stdio.h>
#define bool int
#define false 0
#define true 1

//二叉树的线索化
void InThread(ThreadTree p,ThreadTree pre){
    if(p != NULL){
        InThread(p,pre);
        //前驱
        if(p->lchild == NULL){
            p->lchild = pre;
            p->ltag = 1;
        }else{
            p->ltag = 0;
        }
        //后继
        if(pre != NULL && pre->rchild == NULL){
            pre->rchild = p;
            pre->rtag = 1;
        } else if(pre != NULL && pre->rchild != NULL){
            pre->rtag = 0;
        }

        pre = p;
        InThread(p,pre);
    }
}

//通过中序遍历建立中序线索二叉树
void CreatInThread(ThreadTree root){
    ThreadTree pre = NULL;
    if(root != NULL){
        InThread(root,pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

//求中序线索二叉树中中序序列下的第一个结点
ThreadNode *FirstNode(ThreadNode *p){
    while(p->ltag == 0)
        p = p->lchild;
    return p;
}
//求中序线索二叉树中结点p在中序序列下的后继
ThreadNode *NextNode(ThreadNode *p){
    if(p->rtag == 0)
        return FirstNode(p);
    else
        return p->rchild;
}

//进行遍历
void ThreadTreeOutput(ThreadNode *T){
    for (ThreadNode *p = T; p!= NULL; p = NextNode(p)) {
        printf("%d\t",p->data);
    }
}