/*比较两种算法计算多项式的时间*/
#include "stdio.h"
#include "time.h"
#include "math.h"

clock_t start, stop;
double duration;

#define MAXN 10
#define MAXK 1e7

/*计算多项式的直接方法,p4*/
double f1(int n, double a[], double x){
    int i;
    double p = a[0];
    for(i = 1; i <= n; i++)
        p += a[i] * pow(x, i);
    return p;
}

/*计算多项式函数的秦九韶法*/
double f2(int n, double a[], double x){
    int i;
    double p = a[n];
    for(i = n; i > 0; i--)
        p = a[i - 1] + x * p;
    return p;
}

double run(double(*f)(int, double *, double), double a[], int case_n){
    int i;
    start = clock();//开始计时
    for(i = 0; i < MAXK; i++)//循环MAXK次
        (*f)(MAXN - 1, a, 1.1);
    stop = clock();//结束计时

    duration = ((double)(stop - start)) / CLK_TCK;

    printf("ticks%d = %f\n",case_n, (double)(stop - start));
    printf("duration%d = %6.4e\n", case_n, duration);
}

int main(){
    int i;
    double a[MAXN];//多项式的系数

    for(i = 0; i < MAXN; i++)
        a[i] = (double)i;

    run(f1 ,a, 1);
    run(f2 ,a, 1);
    return 0;
}

