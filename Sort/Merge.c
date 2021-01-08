//
// Created by Cristiano-Ronaldo on 2020/8/10.
//
#include <stdio.h>
#include <stdlib.h>
#include "../LineList.h"

void Merge(int A[],int low,int mid,int high){
    int j,k,h;
    SeqList B ;
    B.data = (int *)malloc((7+1)* sizeof(int));
    B.Length = 8;
    //将A中的数据转移到B中
    for (int i = low; i <= high; ++i) {
        B.data[i] = A[i];
    }
    //进行合并
    for (j = low , k = mid+1, h = j; j <= mid && k<= high; ++h) {
        if(B.data[j] < B.data[k])
            A[h] = B.data[j++];
        else
            A[h] = B.data[k++];
    }

    while(j<=mid){
        A[h++] = B.data[j++];
    }
    while(k<=high){
        A[h++] = B.data[k++];
    }

}

void MergeSort(int A[],int low,int high){
    if (low < high){
        int mid = (low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}