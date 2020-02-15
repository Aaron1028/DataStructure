#include "stdio.h"
#define MAX 100000

int MaxSum(int list[], int n){
    int i;
    int ThisSum,MaxSum;
    ThisSum = MaxSum = 0;
    for(i = 0; i < n; i++){
        ThisSum += list[i];
        if(ThisSum > MaxSum){
            MaxSum = ThisSum;
        }
        else if(ThisSum < 0){
            ThisSum = 0;
        }
    }
    return MaxSum;
}

int main(){
    int k,i;
    int a[MAX];
    scanf("%d", &k);
    for(i = 0; i < k; i++)
        scanf("%d", &a[i]);
    printf("%d",MaxSum(a,k));
}

