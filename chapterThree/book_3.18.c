// Created by Aaron on 2020/2/11.

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define ERROR -1

typedef struct Node * PuToNode;

typedef int ElementType;
struct Node{
    ElementType Data;
    PuToNode Next;
};
typedef PuToNode Position;

typedef struct QNode * PtrToQNode;
struct QNode{
    Position Front,Rear;//头、尾指针
    int MaxSize;
};
typedef PtrToQNode Queue;

bool IsEmpty(Queue Q){
    return(Q ->Front == NULL);
}

ElementType Delete(Queue Q){
    Position FrontCell;
    ElementType FrontElem;
    if(IsEmpty(Q)){
        printf("队列空");
        return ERROR;
    }else{
        FrontCell = Q -> Front;
        if(Q ->Front == Q ->Rear)//队列只有一个元素
            Q ->Front = Q ->Rear =NULL;
        else
            Q ->Front = Q ->Front ->Next;
        FrontElem = FrontCell ->Data;
        free(FrontCell);
        return FrontElem;
    }
}