// Created by Aaron on 2020/2/15.

#include "stdio.h"
#include "stdlib.h"

#define N 100001

typedef struct LNode * List;
struct LNode{
    int Data[N];
    int Length;
};

List Init(){
    List L = (List)malloc(sizeof(struct LNode));
    L ->Length = 0;
    return L;
}

List getValue(List L, int n){
    List p = L;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p ->Data[i]);
    }
    p ->Length = n;
    return p;
}

List getMaxLength(List L, int n){
    List MaxLength;
    MaxLength ->Length = 0;
    int head = 0, tail = 1, length = 1;
    int count = 0;
    List p = L;
    if(p ->Data[head] < p ->Data[tail]){
        head++;
        tail++;
        length++;
    } else{
        if(length > MaxLength ->Length){
            for (int j = tail - length; j <= length ; j++) {
                int k = 0;
                MaxLength->Data[k] = p->Data[j];
                MaxLength->Length++;
                k++;
            }
        }
    }
    for (int i = 0; i < length; ++i) {
        printf("%d ",MaxLength ->Data[i]);
    }

}

 int main(){
    int n;//顺序表长度
    scanf("%d", &n);
    List list = Init();
    list = getValue(list,n);
    getValue(list,n);
    return 0;
 }