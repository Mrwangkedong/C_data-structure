//
// Created by Cristiano-Ronaldo on 2020/8/5.
//
#include <stdio.h>
#include <stdlib.h>
extern int Partition(int A[],int low,int high);

//冒泡排序
void bubbleSort(int A[],int n){
    int i,j,flag;

    for (i = 0; i < n; ++i) {
        flag = 0;
        for (j = n-1; j > i ; --j) {
            if(A[j-1] > A[j]){
                int temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }

    for (int p = 0; p < n; ++p) {
        printf("%d\t",A[p]);
    }

}


//快速排序
void quickSort(int A[],int low,int high){
    int partition;
    if(low < high){
        partition = Partition(A,low,high);
        quickSort(A,low,partition-1);
        quickSort(A,partition+1,high);
    }
}
//获得最中间元素的位置
int Partition(int A[],int low,int high){

    int pivot = A[low];  //将当前列表的第一个元素设为枢纽
    while(low < high){
        while(low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while(low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;

//    每一趟的结果
//    printf("\n");
//    for (int p = 0; p < 7; ++p) {
//        printf("%d\t",A[p]);
//    }

    return low;
}