#include <stdio.h> //"ArrayListmain.cpp"
#include <stdlib.h>
#include "ArrayList.h"
#include "List.h"

int WhoIsPred(Ldata d1, Ldata d2) {
	if (d1 < d2) return 0;
	return 1;
}
int main(void) {
	List* MyList = (List*)malloc(sizeof(List));
	int a, b;
	Ldata Sdata, Bdata, A[10] = { 6,2,7,9,8,3,5,4,0,1 };
	InitList(MyList); //����Ʈ�� �ʱ�ȭ
	LInsert(MyList, 5); LInsert(MyList, 3); LInsert(MyList, 1);//����Ʈ�� �ڷ� �߰�
	printf("%3d %3d %3d \n", //����Ʈ �ڷ��� ���
		MyList->Array[0], MyList->Array[1], MyList->Array[2]);
	SetSortRule(MyList, WhoIsPred);
	//--------------------------------//���� ���� ����------------ 
	b = MyList->NumOfData; //���� �ڷ� ����
	
	MyList->NumOfData = 0;
	for (a = 0; a < b; a++) {
		LInsert(MyList, MyList->Array[a]);
	}
	//------------------------------------------------------------
	for (a = 0; a < 10; a++) {
		LInsert(MyList, A[a]); //����Ʈ�� �ڷ� �߰�
	}
	LPrint(MyList); //����Ʈ �ڷ��� ���
	b = MyList->NumOfData - 1;
	if (LFirst(MyList, &Sdata)) {
		Bdata = Sdata;
		while (MyList->CurPosition < b && LNext(MyList, &Sdata)) {
			if (Bdata == Sdata) {
				printf("�ߺ� �ڷ� %d ���� \n", LRemove(MyList));
				b--;
			}
			Bdata = Sdata;
		}
	}
	LPrint(MyList); //����Ʈ �ڷ��� ���
}