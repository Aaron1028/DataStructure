// Created by Aaron on 2020/2/9.
#include "stdio.h"
#include "stdlib.h"

typedef struct LNode *List;
typedef int ElementType;

struct LNode{
    ElementType Data;
    List Next;
}L;
List PtrL;

//��ʼ������
List Init(){
    List L;
    L = (List)malloc(sizeof(struct LNode));
    if(L == NULL)
        printf("����ռ�ʧ��");
    L -> Next = NULL;
    return L;
}

//ͷ�巨��������
List CreateHead(List L){
    int n;
    List p;
    printf("�����������ȣ�");
    scanf("%d", &n);
    printf("���������ֵ��");
    for (int i = 0; i < n; i++) {
        p = (List)malloc(sizeof(struct LNode));
        scanf("%d", &p->Data);
        p -> Next = L -> Next;
        L -> Next = p;
    }
    return L;
    free(p);
}

//β�巨��������
List CreateTail(List L){
    int n;
    List p, s = L;
    printf("�����������ȣ�");
    scanf("%d", &n);
    printf("���������ֵ��");
    for (int i = 0; i < n; i++) {
        p = (List)malloc(sizeof(struct LNode));
        scanf("%d", &p->Data);
        p -> Next = NULL;
        s -> Next = p;
        s = p;
    }
    return L;
}

//��������
void Print(List L) {
    List p = L->Next;
    if (p == NULL) {
        printf("����Ϊ��\n");
    }
    while (p != NULL) {
        printf("%d ", p -> Data);
        p = p -> Next;
    }
    free(p);
}

//������
int Length(List L){
    List p = L;
    int count = 0;
    while(p){
        p = p -> Next;
        count++;
    }
    free(p);
    return count;
}

//����Ų���
List FindNum(int X, List L){
    List p = L;
    int i = 1;
    while(p  && i < X){
        p = p -> Next;
        i++;
    }
    if(i == X)
        return i;
    else
        return NULL;

}

//��ֵ����
List FindKey(int X, List L){
    List p = L;
    while(p -> Data != X && p != NULL)
        p = p -> Next;
    if(p -> Data == X)
        return X;
    else
        return NULL;
}

//����
List Insert(int i, int X, List L){
    int j = 1;
    List p, s;
    p = L -> Next;
    while(p != NULL && j < i - 1 ){
        p = p -> Next;
        j++;
    }
    if(j = i +1) {
        s = (List) malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return L;
    } else
        return NULL;
}

//ɾ��(ָ��λ��i���±�Ϊi-1)
List Delete(int i, List L){
    int j = 1;
    List p = L, s;
    while(p && j < i){
        p = p -> Next;
        j++;
    }
    if(j = i){
        s = p -> Next;
        p -> Next = s -> Next;
        free(s);
        return L;
    } else{
        printf("����λ�ò�������");
    }
}


int main(){
    struct node* list;
    list = Init();
    list = CreateTail(list);
    list = FindKey(0,)
    Print(list);


}


