// Created by Aaron on 2020/2/11.

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct QNode *PuToQNode;
typedef PuToQNode Queue;
typedef int Position;
typedef int ElementType;

struct QNode{
    ElementType *Data;//存储元素的数组
    Position Front, Rear;//队列的头尾指针
    int MaxSize;//队列的最大容量
};

Queue CreateQueue(int MaxSize){
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q ->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q ->Front = Q ->Rear = 0;
    Q ->MaxSize = MaxSize;
    return Q;
}

//判满
bool IsFull(Queue Q){
    return((Q ->Rear + 1) % Q ->MaxSize == Q ->Front);
}

bool AddQ(ElementType X, Queue Q){
    if(IsFull(Q)){
        printf("队列满");
        return false;
    } else{
        Q ->Rear = (Q ->Rear + 1) % Q ->MaxSize;
        Q ->Data[Q ->Rear] = X;
        return true;
    }
}

bool IsEmpty(Queue Q){
    return (Q ->Front == Q ->Rear);
}

ElementType Delete(Queue Q){
    if(IsEmpty(Q)){
        printf("队列空");
        return false;
    }else{
        Q ->Front = (Q ->Front + 1) % Q ->MaxSize;
        return Q ->Data[Q ->Front];
    }
}