// Created by Aaron on 2020/2/14.

#include "stdio.h"

void Print(int a[], int n){
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
}

void Swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void Perm(int a[], int p, int q){
    if(p == q - 1){
        Print(a, q);
    }else{
        for (int i = p; i < q; i++) {
            Swap(a, p , i);
            Perm(a, p + 1, q);
            Swap(a, p, i);
        }

    }
}

void main(){
    int n;
    int a[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    Perm(a,0, n);
}