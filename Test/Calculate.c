//
// Created by Cristiano-Ronaldo on 2020/7/19.
//
#include<stdio.h>
#include<stdlib.h>
#include "../LineList.h"
#define bool int
#define false 0
#define true 1
extern LiCharStack StackCharListInit(); //初始化
extern LiCharStack millonToend(); //中缀转后缀
extern bool checkCell(char e); //操作数or操作符
extern void PushStackChar(LiCharStack S, char e); //进栈操作
extern void  PopStackChar(LiCharStack S); //出栈操作
extern char GetStackTopChar(LiCharStack S); //得到栈顶元素
int getResult(int OPNumber1,int OPNumber2,char OPChar);//计算
/**
 * 未完成！！！！！！！！！！！！！！！！！！！
 */
void calculate(){
    LiCharStack S = millonToend(); //得到翻转后的后缀表达式
    LiCharStack CStack  = (LiCharStack) StackCharListInit(); //初始化一个计算栈
    StackCharNode* s = (StackCharNode*)malloc(sizeof(StackCharNode));  //初始化一个节点
    s = S->next; //绑定在S上
    while(s != NULL){
        //如果是操作符1+2*2/2-1
        if(checkCell(s->data)){
            char OPNumber1 = GetStackTopChar(CStack);   //操作数1
            PopStackChar(CStack); //出栈
            char OPNumber2 = GetStackTopChar(CStack);   //操作数2
            PopStackChar(CStack); //出栈
            char result = (char)getResult((int)OPNumber1,(int)OPNumber2,s->data); //获得计算结果
            printf("\n------------%c-------------\n",result);
            //将计算结果压入栈中
            PushStackChar(CStack,result);
        }
        else{  //判断是否为操作数
            PushStackChar(CStack,s->data); //压如CStack中
        }
        s = s->next;
    }

    //获得栈顶元素（结果）
    printf("\n%c",GetStackTopChar(CStack));
}

int getResult(int OPNumber1,int OPNumber2,char OPChar){
    if(OPChar == '+')
        return OPNumber1 + OPNumber2;
    if(OPChar == '-')
        return OPNumber1 - OPNumber2;
    if(OPChar == '*')
        return OPNumber1 * OPNumber2;
    if(OPChar == '/')
        return OPNumber1 / OPNumber2;
    return 1;
}
