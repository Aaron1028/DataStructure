// Created by Aaron on 2020/2/9.

#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 10
#define ERROR -1

typedef struct LNode *List;
struct LNode{
    int Data[MAXSIZE];
    int Last;
};
struct LNode L;//访问下标为i的元素：L.Data[i]，线性表长度L.Last+1
List PtrL;//访问下标为i的元素：PtrL->Data[i]，线性表长度PtrL->Last+1

//初始化顺序表
List Init(){
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L -> Last = -1;//如果是0的话，就代表有一个元素放在位置0，设为-1,则是没有元素
    return L;
}

//建立顺序表
List Creat(List L){
    int i,len;
    printf("请输入长度：");
    scanf("%d",&len);
    printf("请输入顺序表：");
    for (i = 0; i < len; ++i) {
        scanf("%d", &L -> Data[i]);
        L -> Last++;
    }
    return L;
}

//遍历数组L
void Print(List L){
    for(int i = 0; i <= L -> Last; i++)
        printf("%d ", L -> Data[i]);

}

//查找顺序表的i位置上是否有X值
int Find(int X, List L){
    int i = 0;
    while (i < L -> Last && L -> Data[i] != X)
        i++;
    if(i > L -> Last)
        return ERROR;
    else
        return i;
}

//在L的指定位序i前插入一个元素X,位序i的元素数组下标为i-1
List Insert(int i, int X, List L){
    int j;
    //检查插入位置的合法性
    if(i < 0 || i > L -> Last){
        printf("插入位置不合法");
        return ERROR;
    }

    //表空间已满，不能插入
    if(L -> Last == MAXSIZE - 1){
        printf("表已满");
        return ERROR;
    }

    //将位置i及以后的元素向后移动
    for(j = L ->Last; j >= i; j--)
        L -> Data[j+1] = L -> Data[j];
    L -> Data[i] = X;
    L -> Last++;
    return L;
}

//从L中删除位序为i的元素，该元素下标为i-1
List Delete(int i, List L){
    int j;
    //判断i的合法性
    if(i < 1 || i > L -> Last + 1){
        printf("删除位置不合法");
        return ERROR;
    }
    //将位序i+1以及后续的元素往前移动
    for(j = i; j <= L -> Last; j++)
        L -> Data[j-1] = L -> Data[j];
    L -> Last--;
    return L;
}

int main()
{
    struct node* list;
    //初始化
    list = Init();
    //创建
    Creat(list);
    //在下标为0的位置插入100
    Insert(0,100, list);
    //遍历
    Print(list);

}