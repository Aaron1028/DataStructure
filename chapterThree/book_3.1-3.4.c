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
struct LNode L;//�����±�Ϊi��Ԫ�أ�L.Data[i]�����Ա���L.Last+1
List PtrL;//�����±�Ϊi��Ԫ�أ�PtrL->Data[i]�����Ա���PtrL->Last+1

//��ʼ��˳���
List Init(){
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L -> Last = -1;//�����0�Ļ����ʹ�����һ��Ԫ�ط���λ��0����Ϊ-1,����û��Ԫ��
    return L;
}

//����˳���
List Creat(List L){
    int i,len;
    printf("�����볤�ȣ�");
    scanf("%d",&len);
    printf("������˳���");
    for (i = 0; i < len; ++i) {
        scanf("%d", &L -> Data[i]);
        L -> Last++;
    }
    return L;
}

//��������L
void Print(List L){
    for(int i = 0; i <= L -> Last; i++)
        printf("%d ", L -> Data[i]);

}

//����˳����iλ�����Ƿ���Xֵ
int Find(int X, List L){
    int i = 0;
    while (i < L -> Last && L -> Data[i] != X)
        i++;
    if(i > L -> Last)
        return ERROR;
    else
        return i;
}

//��L��ָ��λ��iǰ����һ��Ԫ��X,λ��i��Ԫ�������±�Ϊi-1
List Insert(int i, int X, List L){
    int j;
    //������λ�õĺϷ���
    if(i < 0 || i > L -> Last){
        printf("����λ�ò��Ϸ�");
        return ERROR;
    }

    //��ռ����������ܲ���
    if(L -> Last == MAXSIZE - 1){
        printf("������");
        return ERROR;
    }

    //��λ��i���Ժ��Ԫ������ƶ�
    for(j = L ->Last; j >= i; j--)
        L -> Data[j+1] = L -> Data[j];
    L -> Data[i] = X;
    L -> Last++;
    return L;
}

//��L��ɾ��λ��Ϊi��Ԫ�أ���Ԫ���±�Ϊi-1
List Delete(int i, List L){
    int j;
    //�ж�i�ĺϷ���
    if(i < 1 || i > L -> Last + 1){
        printf("ɾ��λ�ò��Ϸ�");
        return ERROR;
    }
    //��λ��i+1�Լ�������Ԫ����ǰ�ƶ�
    for(j = i; j <= L -> Last; j++)
        L -> Data[j-1] = L -> Data[j];
    L -> Last--;
    return L;
}

int main()
{
    struct node* list;
    //��ʼ��
    list = Init();
    //����
    Creat(list);
    //���±�Ϊ0��λ�ò���100
    Insert(0,100, list);
    //����
    Print(list);

}