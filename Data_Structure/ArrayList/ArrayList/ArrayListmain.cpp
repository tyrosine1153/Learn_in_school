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
	InitList(MyList); //리스트의 초기화
	LInsert(MyList, 5); LInsert(MyList, 3); LInsert(MyList, 1);//리스트에 자료 추가
	printf("%3d %3d %3d \n", //리스트 자료의 출력
		MyList->Array[0], MyList->Array[1], MyList->Array[2]);
	SetSortRule(MyList, WhoIsPred);
	//--------------------------------//정렬 기준 적용------------ 
	b = MyList->NumOfData; //기존 자료 정렬
	
	MyList->NumOfData = 0;
	for (a = 0; a < b; a++) {
		LInsert(MyList, MyList->Array[a]);
	}
	//------------------------------------------------------------
	for (a = 0; a < 10; a++) {
		LInsert(MyList, A[a]); //리스트에 자료 추가
	}
	LPrint(MyList); //리스트 자료의 출력
	b = MyList->NumOfData - 1;
	if (LFirst(MyList, &Sdata)) {
		Bdata = Sdata;
		while (MyList->CurPosition < b && LNext(MyList, &Sdata)) {
			if (Bdata == Sdata) {
				printf("중복 자료 %d 제거 \n", LRemove(MyList));
				b--;
			}
			Bdata = Sdata;
		}
	}
	LPrint(MyList); //리스트 자료의 출력
}