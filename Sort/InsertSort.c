//
// Created by Cristiano-Ronaldo on 2020/8/4.
//

#include <stdio.h>
#include <stdlib.h>

//直接插入排序
void directInsert(int A[],int n){
    int i,j;
    for ( i = 1; i < n ; i++) {
        if(A[i] < A[i-1]){
            int temp = A[i];
            for(j=i-1;j>=0 && A[j]>temp;j--){
                A[j+1] = A[j];
            }
            A[j+1] = temp;  //因为j--，所以需要右移一位赋值
        }
    }

    printf("\n");
    for (int k = 0; k < n; ++k) {
        printf("%d\t",A[k]);
    }
}

//折半插入排序
void binaryInsert(int A[],int n){
    int i,j,low,high;
    for (i = 0; i < n; ++i) {
        int temp = A[i];
        low = 0;
        high = i-1;
        while (low<=high){
            int mid = (low+high)/2;
            if(temp > A[mid])
                low = mid+1;
            else
                high = mid-1;
        }
        for(j=i-1;j>=high+1;j--)
            A[j+1] = A[j];
        A[high+1] = temp;
    }

    for (int k = 0; k < n; ++k) {
        printf("%d\t",A[k]);
    }
}

//希尔排序
void shellSort(int A[],int n){
    int i,j,k;
    //step循环
    for (k = n/2; k >= 1 ; k = k/2) {
        for (int l = 0; l < k; ++l) {
            for(i=k+l;i<n;i=i+k){
                if(A[i] < A[i-k]){
                    int temp = A[i];
                    for ( j = i-k; j >=0 && A[j]>temp ; j=j-k) {
                        A[j+k] = A[j];
                    }
                    A[j+k] = temp;
                }
            }
        }

    }

    for (int p = 0; p < n; ++p) {
        printf("%d\t",A[p]);
    }
}
void shellSort2(int A[],int n){
    int i,j,k;
    //step循环
    for (k = n/2; k >= 1 ; k = k/2) {
            for(i=k;i<n;i++){
                if(A[i] < A[i-k]){
                    int temp = A[i];
                    for ( j = i-k; j >=0 && A[j]>temp ; j=j-k) {
                        A[j+k] = A[j];
                    }
                    A[j+k] = temp;
                }
            }

    }

    for (int p = 0; p < n; ++p) {
        printf("%d\t",A[p]);
    }
}