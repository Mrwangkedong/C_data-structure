//
// Created by Cristiano-Ronaldo on 2020/8/5.
//
#include <stdio.h>
#include <stdlib.h>

extern void BuildMaxHeap(int A[],int len);
extern void HeadAdjust(int A[],int k, int len);

//简单排序
void SimpleSort(int A[],int n){
    int min;
    for (int i = 0; i < n; ++i) {
        min = i;
        for (int j = i+1; j < n; ++j) {
            if(A[j] < A[min])
                min = j;
        }
        if(min != i){
            int temp = A[min];
            A[min] = A[i];
            A[i] = temp;
        }
    }

    for (int p = 0; p < 7; ++p) {
        printf("%d\t",A[p]);
    }
}

//堆排序
//总
void HeapSort(int A[],int len){
    BuildMaxHeap(A,len);   //建立大根堆
    //进行排序
    for (int i = len-1; i >= 0; --i) {
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        HeadAdjust(A,0,i-1);
    }

    for (int p = 0; p < 7; ++p) {
        printf("%d\t",A[p]);
    }
}
//构造大根堆
void BuildMaxHeap(int A[],int len){
    for (int i = (len-1)/2; i >= 0 ; --i) {
        HeadAdjust(A,i,len);
    }
}
//调整堆节点大小关系，是节点大于左右子节点（数组、调整节点的节点数、长度）
void HeadAdjust(int A[],int k, int len){
    int temp = A[k];
    for (int i = 2*k; i < len-1; i=i*2) {
        if(A[i] < A[i+1] && i<len-1)
            i++;
        if(temp >= A[i])  //如果当前节点大于他的两个子节点。直接跳出
            break;
        else{
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = temp;
}

