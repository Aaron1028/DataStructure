// Created by Aaron on 2020/2/12.

#include "stdio.h"

int main(){
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int j = 0; j < m; ++j) {
        int temp;
        temp = a[0];
            for (int i = 1; i < n; ++i) {
                a[i - 1] = a[i];
            }
            a[n - 1] = temp;
    }
    for (int i = 0; i < n; ++i) {
        if(i == n - 1){
            printf("%d", a[i]);
        } else{
            printf("%d ", a[i]);
        }
    }

}