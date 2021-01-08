#include <stdio.h>
#include <stdlib.h>
#include "LineList.h"
#define bool int
#define false 0
#define true 1
extern bool checkCell(char e);
extern bool checkOpera(char op1,char op2);
extern void millonToend();
extern void calculate();
extern int Index_KMP(char S[],char T[], const int next[]);
extern Bitree BitreeInit();
extern void TreeVisit(Bitree T);
extern void TreeInsert(Bitree T,int data);
extern LinkTreeQueue TreeQueueInit();
extern void EnTreeQueue(LinkTreeQueue TQ,BiTNode* T);
extern void DeTreeQueue(LinkTreeQueue TQ);
extern Bitree TopTreequeue(LinkTreeQueue TQ);
extern void LevelQrderTree(Bitree T);
extern int TreeHigh(Bitree T);
extern int TreeHigh2(Bitree T);
extern Bitree PreInCreat(const int A[],const int B[],int l1,int h1,int l2,int h2);
extern void PrintTree(Bitree T,int h);
extern void BehindOrderTree(Bitree T);
extern void TreeStackPrint(LinkTreeStack TS);
extern BiTNode *BST_SearchMax(Bitree T);
extern BiTNode *BST_SearchMin(Bitree T);
extern LinkTreeStack FindTreeNodeFarthers(Bitree T, int data);
extern int BST_DelNode(Bitree T,int data);
extern int BST_Insert2(Bitree T,int key);
extern int BST_Insert(Bitree T,int key);
extern int binarySearch(SeqList L,int key);//折半查找
extern SeqList IntergeListInit();
extern void directInsert(int A[],int n);
extern void binaryInsert(int A[],int n);
extern void shellSort(int A[],int n);
extern void shellSort2(int A[],int n);
extern void bubbleSort(int A[],int n);
extern void quickSort(int A[],int low,int high);//快速排序
extern void SimpleSort(int A[],int n);//简单排序
extern void HeapSort(int A[],int len);
extern void MergeSort(int A[],int low,int high);//二路递归排序




int main() {


//    for (int i = 1; i < 10; ++i) {
//        for (int j = 1; j <= i; ++j) {
//            printf("%d*%d=%d",i,j,i*j);
//            printf("\t");
//        }
//        printf("\n");

    int A[6]={6,4,2,1,3,8};

    int i = 0,j=1;
    int temp=0;


    while(i<6&&j<6){
        while(A[i]%2!=0 )
            i=i+2;
        while(A[j]%2==0 )
            j=j+2;

        if(j>=6 || i>=6)
            break;
        else{
            temp = A[i];
            A[i]=A[j];
            A[j]=temp;
        }




    }
//

    for(i=0;i<6;i++)
        printf("%d\t",A[i]);



}















//    MGraph G;
//    for (int i = 0; i < 5; ++i) {
//        G.Vex[i] = (char)i;
//        for (int j = 0; j < 5; ++j) {
//            G.Edge[i][j] = 0;
//        }
//    }
//    G.Edge[0][1]=1,G.Edge[1][0]=1;;
//    G.Edge[0][3]=1,G.Edge[3][0]=1;;
//    G.Edge[1][2]=1,G.Edge[2][1]=1;
//    G.Edge[1][4]=1,G.Edge[4][1]=1;
//    G.Edge[2][3]=1,G.Edge[3][2]=1;
//    G.Edge[2][4]=1,G.Edge[4][2]=1;

//    BFSTraverse(G);
//    DFSTraverse(G);
//    printf("%d",FirstNeighbor(G,3));
//    printf("\n%d",NextNeighbor(G,2,3));

//队列测试
//    SqQueue Q;
//    initSqQueue(&Q);
//    for (int k = 0; k < 3; ++k) {
//        printf("%d",PushSqQueue(&Q,k));
//    }
//    printf("\n%d\t",PopSqQueue(&Q));
//    printf("\n%d\t",PopSqQueue(&Q));
//    printf("\n%d\t",PopSqQueue(&Q));



//    int A[] = {49,38,65,97,76,3,13,27};
//    directInsert(A,7);
//    shellSort2(A,7);
//    SimpleSort(A,7);
//    quickSort(A,0,6);
//      MergeSort(A,0,6);

//    for (int p = 0; p < 8; ++p) {
//        printf("%d\t",A[p]);
//    }

    /******折半查找测试
    //初始化一个线性表
    SeqList L = IntergeListInit();
    //进行数据插入
    for (int i = 0,j=0; i < 10; i++,j=j+2) {
        L.data[i] = j;
        L.Length++;
    }
    printf("\n%d",binarySearch(L,6));
    exit(0);
     */

/********************
//    Bitree bt = BitreeInit();
//
//    TreeInsert(bt,88);
//    TreeInsert(bt,99);
//    TreeInsert(bt,77);
//    //循环创建一棵普通的二叉树
//    for (int i = 2; i < 13; ++i) {
//        TreeInsert(bt,i);
//    }
//    bt->lchile->lchile->rchile = NULL;
//    bt->rchile->lchile = NULL;

    //得到某个节点的祖先栈**然后遍历
//    TreeStackPrint(FindTreeNodeFarthers(bt,11));

//    printf("\n%d",BST_SearchMin(bt)->data);

    //非递归，后序遍历
//    BehindOrderTree(bt);

//    //层次遍历树
//    LevelQrderTree(bt);
//
//    //输出树的高度
//    printf("%d\n",TreeHigh(bt));
//    //形象输出树
//    PrintTree(bt,TreeHigh(bt));
*///////


/********************
//新建一颗排序树
//    int alist[] = {53,17,9,45,23,78,65,94,81,88};
//    Bitree bst = BitreeInit();
//    bst->data = 53;
//    for (int j = 1; j < sizeof(alist)/ sizeof(int); j++) {
//        int k = BST_Insert2(bst,alist[j]);
//    }
//    PrintTree(bst,TreeHigh(bst));

    //删除节点“1”
*/////


