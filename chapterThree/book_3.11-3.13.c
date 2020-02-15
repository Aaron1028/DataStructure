// Created by Aaron on 2020/2/10.

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define ERROR -1
typedef struct SNode *Stack;
typedef int ElementType;

struct SNode{
    ElementType *Data;
    int Top;//栈顶位置数组下标
    int MaxSize;
};

//顺序栈的创建
Stack CreateStack(int MaxSize){
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S -> Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S -> Top = -1;
    S -> MaxSize = MaxSize;
    return S;

}

//判满
bool IsFull(Stack S){
    return (S -> Top == S -> MaxSize - 1);
}

//入栈
Stack Push(ElementType X, Stack S){
    if(IsFull(S)){
        printf("栈满");
        return ERROR;
    }else{
        S -> Data[++(S -> Top)] = X;
        return S;
    }
}

//判空
bool IsEmpty(Stack S){
    return (S -> Top == -1);
}

//出栈
Stack Pop(Stack S){
    if(IsEmpty(S)){
        printf("栈空");
        return ERROR;
    } else{
        return (S -> Data[(S -> Top)--]);
    }
}


int main(){
    struct SNode *stack;
    stack = CreateStack(3);
    stack = Push(100,stack);
    int i = Pop(stack);
    printf("%d",i);
}