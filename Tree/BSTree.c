//
// Created by Cristiano-Ronaldo on 2020/7/27.
//
#include "../LineList.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define bool int
#define false 0
#define true 1
extern Bitree BitreeInit();

//二叉排序树的查找
BiTNode *BST_Search(Bitree T,int key){
    while(T != NULL && key != T->data){
        if(key < T->data)
            T = T->lchile;
        else
            T = T->rchile;
    }

    return T;
}
//二叉排序树的插入(递归)
int BST_Insert(Bitree T,int key){

    if(T == NULL){
        T = (Bitree)malloc(sizeof(BiTNode));
        T->data = key;
        T->lchile = T->rchile = NULL;
        return 1;
    } else if (key == T->data){
        return 0;
    } else if (key < T->data)
        return BST_Insert(T->lchile,key);
    else
        return BST_Insert(T->rchile,key);

}
//二叉排序树的插入(非递归)
int BST_Insert2(Bitree T,int key){

    while(T){
        if(T->data == key)
            return 0;
        else if (T->data > key){
            Bitree p ;
            p = T;
            T = T->lchile;
            if(T == NULL){
                T = (Bitree)malloc(sizeof(BiTNode));
                T->data = key;
                T->lchile = T->rchile = NULL;
                p->lchile = T;
                return 1;
            }
        }
        else if (T->data < key){
            Bitree p ;
            p = T;
            T = T->rchile;
            if(T == NULL){
                T = (Bitree)malloc(sizeof(BiTNode));
                T->data = key;
                T->lchile = T->rchile = NULL;
                p->rchile = T;
                return 1;
            }
        }

    }

    return 0;
}

//查看节点的子节点个数
int NodeSonNumb(BiTNode *T){
    int count = 0;
    if(T->lchile != NULL)
        count++;
    if(T->rchile != NULL)
        count++;
    return count;
}
//查找先序遍历中的第一个（排序二叉树右边最小值）
BiTNode *BST_SearchMax(Bitree T){
    while(T != NULL) {
        if (T->rchile == NULL)
            return T;
        else {
            T = T->rchile;
            printf("%d\t",T->data);
        }
    }
    return T;
}
//查找先序遍历的最后一个（排序二叉树左边最大值）
BiTNode *BST_SearchMin(Bitree T){
    while(true) {
        if (T->lchile == NULL) {
            return T;
        } else {
            T = T->lchile;
            printf("%d\t",T->data);
        }
    }
    return T;
}
//二叉排序树的删除
int BST_DelNode(Bitree T,int data){
    //找到值所对应的节点
    BiTNode * node = BST_Search(T,data);
    if(node == NULL){
        return 0;
    }
    int NodeNum = NodeSonNumb(node);
    //判断值的子节点个数
    if(NodeNum == 0){       //0个节点
        node = NULL;
        return 1;
    } else if (NodeNum == 1){   //一个节点
        if(node->lchile != NULL) {
            BiTNode *p = node->lchile;
            node->lchile = p->lchile;
            node->rchile = p->rchile;
            p = NULL;
        } else if (node->rchile != NULL){
            BiTNode *p = node->rchile;
            node->lchile = p->lchile;
            node->rchile = p->rchile;
            p = NULL;
        }
        return 1;
    } else{         //两个节点
        BiTNode *p = BST_SearchMax(node);  //找到左子树中最大的值进行顶替
        node->data = p->data;
        p = NULL;
    }

    return 0;
}

