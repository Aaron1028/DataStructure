#include "stdio.h"

int main(){
    int left, right;
    int flag = 0;
    char op;
    scanf("%d", &left);
    while(1){
        scanf("%c", &op);
        if(op == '=')
            break;
        scanf("%d", &right);
        switch(op){
            case '+':
                left = left + right;
                break;
            case '-':
                left = left - right;
                break;
            case '*':
                left = left * right;
                break;
            case '/':{
                if(right == 0){
                    flag = 1;
                    break;
                } else{
                    left = left / right;
                    break;
                }
            }
            default:
                flag = 1;
                break;
        }
    }
    if(flag == 1){
        printf("ERROR");
    } else{
        printf("%d", left);
    }

}
