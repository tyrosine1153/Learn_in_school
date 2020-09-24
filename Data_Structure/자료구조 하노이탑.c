#include<stdio.h>

void hanoi(int n, char from, char by, char to){
    if(n==1)    printf("���� 1���� %c���� %c�� �ñ��.\n",from,to);
    else{
        hanoi(n-1, from, to, by);
        printf("���� %d�� %c���� %c�� �����.\n", n, from, to);
        hanoi(n-1, by, from, to);
    }
}

int main(){
    hanoi(5,'A','B','C');
    return 0;
}
