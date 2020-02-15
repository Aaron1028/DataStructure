#include "stdio.h"

/*给定n个整数的序列{a1，a2，...,an}，求函数子列的最大值*/
/*暴力循环p15*/
int MaxSubseqSum1(int List[], int N){
    int i, j, k;
    int ThisSum, MaxSum = 0;
    for (i = 0; i < N; ++i) {//子列左端位置
        for (j = i; j < N; ++j) {//子列右端位置
            ThisSum = 0;//是List[i]到List[j]的子列和
            for (k = i; k <= j; ++k)
                ThisSum += List[k];
            if(ThisSum > MaxSum)
                MaxSum = ThisSum;
        }//j循环结束
    }//i循环结束
    return MaxSum;
}
int main(){
    int list[10] = {10, 5, -4, 7, 6, -5, -4};
    printf("%d", MaxSubseqSum1(list, 7));
}


