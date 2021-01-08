//
// Created by Cristiano-Ronaldo on 2020/7/20.
//
#include<stdio.h>
#include<stdlib.h>
#define bool int
#define false 0
#define true 1

/**
 * Test代码
    int a[6] = {0,1,1,1,2,1};
    char S[] = "googligoogoogleko";
    char T[] = "gligo";
    int index = Index_KMP(S,T,a);
    printf("%d",index);
    return 0;
 */

/**
 * 匹配子串
 * @param S 主字符串
 * @param T  子字符串
 * @param next  匹配值
 * @return
 */
int Index_KMP(char S[],char T[], const int next[]){
    int i=0,j=0;
    int S_length = _mbstrlen(S);
    int T_length = _mbstrlen(T);
    while(i<S_length && j<T_length){
        if (S[i] == T[j]){
            ++i;
            ++j;
        } else if (S[i] != T[j] && j!=0){
            j=next[j-1];
        } else if(S[i] != T[j] && j==0){
            i++;
        }
    }
    if (j==T_length){
        return i-T_length;
    } else
        return 0;

}