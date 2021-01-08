//
// Created by Cristiano-Ronaldo on 2020/7/22.
//
#include "../LineList.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define bool int
#define false 0
#define true 1
extern LinkTreeQueue TreeQueueInit();
extern void EnTreeQueue(LinkTreeQueue TQ,BiTNode* T);
extern void DeTreeQueue(LinkTreeQueue TQ);
extern Bitree TopTreequeue(LinkTreeQueue TQ);
extern LinkTreeStack TreeStackInit();
extern Bitree TreeStackTop(LinkTreeStack TS);
extern void TreeStackPush(LinkTreeStack TS,Bitree T);
extern void TreeStackPop(LinkTreeStack TS);
extern bool TreeStackEmpty(LinkTreeStack TS);

//初始化
Bitree BitreeInit(){
    Bitree root = (Bitree)malloc(sizeof(BiTNode));
    root->data = 1;
    root->lchile = NULL;
    root->rchile = NULL;

    return root;
}
//访问树的节点值
void TreeVisit(Bitree T){
    printf("aa%d\t",T->data);
}

//依照完全二叉树，对树进行插入
void TreeInsert(Bitree T,int data){
    BiTNode *p = NULL;
    LinkTreeQueue TQ = TreeQueueInit(); //初始化队列
    //根节点入队
    EnTreeQueue(TQ,T);
    //队列不为空则循环
    while(TQ->front != TQ->rear){
        p = TopTreequeue(TQ);
        DeTreeQueue(TQ);
//        TreeVisit(p);  //输出p点的data
        //检查左节点
        if(p->lchile != NULL)
            EnTreeQueue(TQ,p->lchile);
        else{
            BiTNode* bt = BitreeInit();
            bt->data = data;
            p->lchile = bt;
            break;
        }
        //检查右节点
        if(p->rchile != NULL)
            EnTreeQueue(TQ,p->rchile);
        else{
            BiTNode* bt = BitreeInit();
            bt->data = data;
            p->rchile = bt;
            break;
        }

    }

}

//层次遍历二叉树
void LevelQrderTree(Bitree T){
    BiTNode *p = NULL;
    LinkTreeQueue TQ = TreeQueueInit(); //初始化队列
    //根节点入队
    EnTreeQueue(TQ,T);
    //队列不为空则循环
    while(TQ->front != TQ->rear){
        p = TopTreequeue(TQ);
        DeTreeQueue(TQ);
        TreeVisit(p);  //输出p点的data
        if(p->lchile != NULL)
            EnTreeQueue(TQ,p->lchile);
        if(p->rchile != NULL)
            EnTreeQueue(TQ,p->rchile);
    }
}

//层次遍历，求树的层数
int TreeHigh(Bitree T){

    if(!T)
        return 0;   //树空，高度为零
    int last = 0,level=0; //last指向当前层的最右节点
    int front = -1,rear = -1;  //树队列的头、尾
    Bitree Q[20];  //定义一个队列

    Q[++rear] = T;  //根节点入队
    Bitree p;
    //队列不空，循环
    while(front < rear){
        p = Q[++front];  //队列元素出队，即正在访问的加点
        if(p->lchile)
            Q[++rear] = p->lchile;  //左孩子入队
        if(p->rchile)
            Q[++rear] = p->rchile;  //右孩子入队
        if(front == last){         //处理该层最右节点
            level++ ;           //层+1
            last = rear;        //last指向下层,节点出队的时候，正好他的子节点入队
        }
    }
    return level;
}

//递归遍历、求树的层数
int TreeHigh2(Bitree T){

    if(T ==NULL)
        return 0;      //空的树，高度为0
    int ldep = TreeHigh2(T->lchile);    //左子树高度
    int rdep = TreeHigh2(T->rchile);    //右子树高度
    if(ldep>rdep)
        return ldep+1;      //树的高度为字数的最大高度加根节点
    else
        return rdep+1;

}

//先序 AND 中序 确定二叉树
Bitree PreInCreat(const int A[],const int B[],int l1,int h1,int l2,int h2){
    int rootIndex ; //当前根节点在B中的位置
    //定义当前节点
    BiTNode *root = (BiTNode *)malloc(sizeof(BiTNode));
    root->data = A[l1]; //当前节点的值
    //循环找到root，在B中的位置
    for (rootIndex = l2; B[rootIndex] != root->data ; rootIndex++);

    int llen = rootIndex - l2;   //左子树的长度
    int rlen = h2 - rootIndex;   //右子树的长度

    if (llen)     //递归建立左子树
        root->lchile = PreInCreat(A,B,l1+1,l1+llen,l2,l2+llen+1);
    else
        root->lchile = NULL;

    if(rlen)
        root->rchile = PreInCreat(A,B,h1-llen+1,h1,h2-rlen+1,h2);
    else
        root->rchile = NULL;

    return root;
}

//打印每个元素
void PrintTreeNode(int c,int h,int index){
    //基础空格
    int blank = 3;

    //用于标记是否为每行第一个元素
    bool flag = false;
    //确定元素所在行
    int line = 1;
    for(;line<=h;line++){
        if(index<=pow(2,line-1)){
            if(index == pow(2, line-1)){
                flag = true;
            }else{
                line--;
            }
            break;
        }
    }

    //每个字母的空格倍数
    int itemblank = blank;
    for(int i=1;i<h-line+1;i++){
        itemblank = itemblank*2+1;
    }

    //每行开头字母的空格倍数
    int headblank = (itemblank-1)/2-1;
    if(flag){
        //新的一行的回车数
        int changelinenum = (itemblank-1)/4;
        if(changelinenum < 1){
            changelinenum = 1;
        }
        if(line == 1){
            changelinenum = 1;
        }

        //先回车换行
        for(int j=0;j<changelinenum;j++){
            printf("\n");
        }
        //在打印空格到正确的位置
        for(int i=0;i<headblank;i++){
            printf(" ");
        }

        //最后打印每行的第一个元素
        if(c == 0)
            printf(" ");
        else
            printf("%d",c);
    }else{
        //先打印空格到正确的位置
        for(int i=0;i<itemblank;i++){
            printf(" ");
        }
        //打印元素
        if(c == 0)
            printf(" ");
        else
            printf("%d",c);
    }
}

//形象打印二叉树----  h为二叉树的高度
void PrintTree(Bitree T,int h){
    printf("\n");

    //二叉树元素序号
    int index = 0;

    //初始化一个队列
    LinkTreeQueue Q = TreeQueueInit();

    //第一个元素先入队
    EnTreeQueue(Q, T);

    //总数大于满二叉树最大值则退出循环
    while(index < pow(2,h)-1){
        BiTNode *node = TopTreequeue(Q); //入队
        DeTreeQueue(Q);     //出队=
        index++;
        //将空的子树也入队，这样方便计算
        if(node == NULL){
            EnTreeQueue(Q, NULL);
            EnTreeQueue(Q, NULL);
            //打印第index个元素
            PrintTreeNode(0,h,index);
        }else{
            EnTreeQueue(Q, node->lchile);
            EnTreeQueue(Q, node->rchile);
            //打印第index个元素
            PrintTreeNode(node->data,h,index);
        }
    }

    printf("\n");
}

//利用栈、非递归进行“后续遍历”
void BehindOrderTree(Bitree T){
    //初始化一个栈
    LinkTreeStack TS = TreeStackInit();
    //新建一个Node指向Root
    Bitree p = T;
    //设定辅助指针r，指向最近访问过的节点，避免访问过之后再访问
    Bitree r = NULL;
    //设置循环进行遍历
    while(p || !TreeStackEmpty(TS)){
        if(p){
            TreeStackPush(TS,p);   //当前root进栈
            p = p->lchile;    //p指向p.left
        }
        else{          //向右
            p = TreeStackTop(TS);
            //p是否存在右节点  &&  p的右节点是否被访问过
            if(p->rchile && p->rchile != r){
                p = p->rchile; //转向右节点
                TreeStackPush(TS,p); //压入栈
                p = p->lchile;  //继续进行左为尊
            }
            else{       //否则，弹出当前root进行访问
                p = TreeStackTop(TS);  //取出栈顶元素
                printf("%d  ",p->data);  //输出Top节点
                TreeStackPop(TS);   //去除Top节点
                r = p;      //激励最近访问过的节点 *****
                p = NULL;  //节点访问过后，重置p指针
            }
        }//else
    }//while

}

//利用非递归后序遍历 ***找某个节点（data）的祖先***
//返回一个栈
LinkTreeStack FindTreeNodeFarthers(Bitree T, int data){
    //初始化一个栈
    LinkTreeStack TS = TreeStackInit();
    //新建一个Node指向Root
    Bitree p = T;
    //设定辅助指针r，指向最近访问过的节点，避免访问过之后再访问
    Bitree r = NULL;
    //设置循环进行遍历
    while(p || !TreeStackEmpty(TS)){
        if(p){
            TreeStackPush(TS,p);   //当前root进栈
            p = p->lchile;    //p指向p.left
        }
        else{          //向右
            p = TreeStackTop(TS);
            //p是否存在右节点  &&  p的右节点是否被访问过
            if(p->rchile && p->rchile != r){
                p = p->rchile; //转向右节点
                TreeStackPush(TS,p); //压入栈
                p = p->lchile;  //继续进行左为尊
            }
            else{       //否则，弹出当前root进行访问
                p = TreeStackTop(TS);  //取出栈顶元素
                TreeStackPop(TS);   //去除Top节点
                if(p->data == data)
                    return TS;
                r = p;      //激励最近访问过的节点 *****
                p = NULL;  //节点访问过后，重置p指针
            }
        }//else
    }//while

    return NULL;
}
