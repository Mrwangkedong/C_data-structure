//
// Created by Cristiano-Ronaldo on 2020/7/30.
//

#include <stdio.h>
#include<stdlib.h>
#include "../LineList.h"

//初始化一个数组
SeqList IntergeListInit(){
    SeqList seqList;
    seqList.data = (int*)malloc(sizeof(int)+20);
    seqList.Length = 0;
    seqList.Maxsize = 20;
    return seqList;
}

//折半查找
int binarySearch(SeqList L,int key){

    int low = 0, high = L.Length-1,mid;
    while (low <= high){
        mid = (high+low)/2;
        printf("%d\t",L.data[mid]);
        if (key > L.data[mid]){
            low = mid + 1;
        } else if(key < L.data[mid]){
            high = mid - 1;
        } else{
            return mid;
        }
    }

    return -1;
}