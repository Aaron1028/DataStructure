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

void getMaxLength(List L, int n){
    List p = L;
    int l = 0, r = 0, len = 1;
    int maxL = 0, maxR = 0, maxLen = 1;
    for (int i = 1; i < n; ++i) {
        if(p ->Data[i] > p ->Data[i-1]){
            r++;
            len++;
        }
        else{
            if(len > maxLen){
                maxL = l;
                maxR = r;
                maxLen = len;
            }
            l = r = i;
            len = 1;
        }
    }
    if(len > maxLen){
        maxL = l;
        maxR = r;
        maxLen = len;
    }
    for (int j = maxL; j <= maxR; ++j) {
        if(j == maxR){
            printf("%d", p->Data[j]);
        }else{
            printf("%d ", p->Data[j]);
        }

    }
}

int main(){
    int n;//顺序表长度
    scanf("%d", &n);
    List list = Init();
    list = getValue(list,n);
    getMaxLength(list,n);
    return 0;
}