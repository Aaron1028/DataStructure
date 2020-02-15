// Created by Aaron on 2020/2/12.

#include "stdio.h"
int main(){
    int A, N;
    int s = 0;
    int S[100001] = {0};
    scanf("%d %d", &A, &N);
    for (int i = 0; i < N; ++i){
        S[i] = S[i-1] * 10 + 1;
    }
    for (int j = 0; j < N; ++j) {
        s = s + S[j];
    }
    printf("%d ", s);
}
