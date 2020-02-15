// Created by Aaron on 2020/2/10.

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define ERROR -1
typedef struct SNode *Stack;
typedef int ElementType;
struct SNode{
    ElementType Data;
    Stack Next;
};

//创建一个链栈的头结点
Stack CreateStack(){
    Stack S;
    S = malloc(sizeof(struct SNode));
    S -> Next = NULL;
    return S;
}

bool IsEmpty(Stack S){
    return (S -> Next == NULL);
}

//入栈
Stack Push(ElementType X, Stack S){
    Stack p;
    p = (Stack)malloc(sizeof(struct SNode));
    p -> Data = X;
    p -> Next = S -> Next;
    S -> Next = p;
    return S;
}

Stack Pop(Stack S){
    Stack p;
    ElementType X;
    if(IsEmpty(S)){
        printf("栈空");
        return ERROR;
    }
    p = S -> Next;
    X = p -> Data;
    S -> Next = p -> Next;
    free(p);
    return X;
}

int main(){
    struct SNode *stack;
    stack = CreateStack(stack);
}