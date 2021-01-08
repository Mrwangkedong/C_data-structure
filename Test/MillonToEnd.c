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
extern void PushStackChar(LiCharStack S, char e); //进栈操作
extern void  PopStackChar(LiCharStack S); //出栈操作
extern char GetStackTopChar(LiCharStack S); //得到栈顶元素
extern bool EmptyStackChar(LiCharStack S); //判断是否为空

/**
 * 检查元素类型，是数字？还是操作符
 * @param e 元素值
 * @return  true表示操作符，false表示数字
 */
bool checkCell(char e){
    if(e == '+' || e == '-' || e == '*' || e == '/' || e == '(' || e == ')')
        return true;
    else
        return false;
}
/**
 * 返回操作符等级的比较
 * @param op1 操作符1
 * @param op2 操作符2
 * @return true代表 op1 >= op2
 */
bool checkOpera(char op1,char op2){
    int item1 = 0;
    int item2 = 0;
    //操作符号1的等级
    if(op1 == '+' || op1 == '-')
        item1=1;
    else if (op1 == '*' || op1 == '/')
        item1=2;
    else
        item1=3;
    //操作符号2的等级
    if(op2 == '+' || op2 == '-')
        item2=1;
    else if (op2 == '*' || op2 == '/')
        item2=2;
    else
        item2=3;

    if(item1>=item2)
        return true;
    else
        return false;
}

void outputStackChar(LiCharStack S){

    S = S->next;
    while (S != NULL){
        printf("%c\t",S->data);
        S = S->next;
    }
}

/**
 * 翻转栈
 * @param S 待翻转的栈
 * @return  翻转后的栈
 */
LiCharStack ReverseStackChar(LiCharStack S){
    LiCharStack S2 = StackCharListInit();

    S = S->next;
    while (S != NULL){
        PushStackChar(S2,S->data);
        S = S->next;
    }

    return S2;
}

/**
 * 中缀转后缀
 */
LiCharStack millonToend(){
    LiCharStack OpStack = NULL,BeStack = NULL,FinalStack = NULL;//定义操作符栈、全局栈
    char e;
    OpStack = (LiCharStack) StackCharListInit();
    BeStack = (LiCharStack) StackCharListInit();
    char str[20]; //定义表达式字符串
    gets(str);
    for (int i = 0; i < sizeof(str); ++i) {
        if(str[i] == '\0')
            break;
        if(checkCell(str[i])){   //操作符进入OpStack
            //如果是空栈，直接进入
            if(EmptyStackChar(OpStack))
                PushStackChar(OpStack,str[i]);
            else{
                //获取操作栈栈顶元素
                char topData = GetStackTopChar(OpStack);
                //将大于等于自己的栈顶元素出到BeStack中
                while(checkOpera(topData,str[i])){
                    PopStackChar(OpStack);  //操作符出栈，当遇到小于自己的操作符则停止
                    PushStackChar(BeStack,topData);//操作符进入全局栈
                    topData = GetStackTopChar(OpStack);  //再次获得Top元素
                    if(topData == 'x')  //x表示OpStack为空
                        break;
                }
                //str【i】进栈
                PushStackChar(OpStack,str[i]);
            }
        }else{
            PushStackChar(BeStack,str[i]);  //数字进入BeStack
        }

    }
    //将OPStack清空
    while(OpStack->next != NULL){
        char topData = GetStackTopChar(OpStack);
        PopStackChar(OpStack);  //操作符出栈，当遇到小于自己的操作符则停止
        PushStackChar(BeStack,topData);//操作符进入全局栈
    }

    printf("\n***********");
    FinalStack = ReverseStackChar(BeStack);
    outputStackChar(FinalStack);
    printf("\n///////////\n");
    return FinalStack;
}


