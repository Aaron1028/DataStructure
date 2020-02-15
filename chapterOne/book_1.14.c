#include "stdio.h"

/*给定n个整数的序列{a1，a2，...,an}，求函数子列的最大值*/
/*在线处理p19*/
int MaxSubseqSum4(int List[], int N){
    int i;
    int ThisSum, MaxSum;
    ThisSum = MaxSum = 0;
    for (i = 0; i < N; ++i) {
        ThisSum += List[i];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}

int main(){
    int a[] = {10, 5, -4};
    printf("%d",MaxSubseqSum4(a, 3));

}

