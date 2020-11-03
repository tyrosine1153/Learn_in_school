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
    printf("인원수(<=33), 간격");
    scanf("%d %d", &MAX, &NN);

    printf("\n 새로운 노드를 정렬하여 리스트에 추가\n");
    SetSortRule(MyList, WhoIsPred);
    while (A[a] && a < MAX)
        LInsert(MyList, NewNode(A[a++]));
    LPrint(MyList);

    printf("\n 끝까지 남은 멤버는 누구일까?");
    getch();
    printf("\n%d번째 자료를 순환하며 제거\n", NN);
    printf("\n남아있는 멤버: %c\n", Delete(MyList, NN));
}
