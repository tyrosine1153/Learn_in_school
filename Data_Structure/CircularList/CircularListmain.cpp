#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"Circular.h"
#include"List.h"
#include"Circular.h"
#define SSR(small,large) ((small)<(large))

int WhoIsPred(Ldata d1, Ldata d2) {
    if (SSR(d1->Item, d2->Item)) return 0;
    else return 1;
}

Ldata NewNode(char Item) {
    Ldata NN = (Node*)malloc(sizeof(Node));
    NN->Item = Item;
    NN->Next = NULL;
    return NN;
}

char Delete(List* plist, int N) {
    int a = 0;
    Ldata Cur = plist->Tail, Before;

    if (plist->NumOfData == 1)
        return plist->Tail->Item;
    else {


    }
}

int main() {
    List* MyList = (List*)malloc(sizeof(int));
    int a = 0;
    char A[33] = "abcdefABCDEFGHIJKLMNOPQRSTUVWXYZ";
    InitList(MyList);
    int MAX, NN;
    printf("�ο���(<=33), ����");
    scanf("%d %d", &MAX, &NN);

    printf("\n ���ο� ��带 �����Ͽ� ����Ʈ�� �߰�\n");
    SetSortRule(MyList, WhoIsPred);
    while (A[a] && a < MAX)
        LInsert(MyList, NewNode(A[a++]));
    LPrint(MyList);

    printf("\n ������ ���� ����� �����ϱ�?");
    getch();
    printf("\n%d��° �ڷḦ ��ȯ�ϸ� ����\n", NN);
    printf("\n�����ִ� ���: %c\n", Delete(MyList, NN));
}
