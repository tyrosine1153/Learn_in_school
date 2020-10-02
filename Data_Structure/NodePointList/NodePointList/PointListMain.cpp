#include <stdio.h> //"PointListmain.cpp"
#include <stdlib.h>
#include "Point.h"
#include "List.h"

int WhoIsPred(Ldata d1, Ldata d2) {
	if (d1->x < d2->x) return 0;
	else if (d1->x == d2->x)
		if (d1->y < d2->y) return 0;
		else return 1;
	else return 1;
}

Ldata NewPoint(int x, int y) {
	Ldata Npoint = (Point*)malloc(sizeof(Point));
	Npoint->x = x; Npoint->y = y; Npoint->Next = NULL;
	return Npoint;
}

void Sorting(List* plist) {
	SetSortRule(plist, WhoIsPred);
	int a, su = 0;
	Ldata Tmp, Addr[100];
	Tmp = plist->Head;
	while (Tmp = Tmp->Next) { //첫 번째 자료부터 모든 자료의 포인터를
		Addr[su++] = Tmp; //배열에 저장
	}
	plist->Head->Next->Next = NULL; //첫 자료의 Next를 NULL로 설정
	plist->NumOfData = 1;
	for (a = 1; a < su; a++) { //두 번째 자료 이후부터 모든 자료를
		Addr[a]->Next = 0; //Next 포인터를 NULL로 설정하여
		LInsert(plist, Addr[a]); //리스트에 추가(Sorting Rule 적용)
	}
}

int main(void) {
	List* MyList = (List*)malloc(sizeof(List));
	int a, A[10] = { 6,2,7,9,8,3,5,4,0,1 };
	Ldata point = (Point*)malloc(sizeof(Point)), rpoint;
	InitList(MyList); //리스트의 초기화
	printf("\n새로운 노드를 리스트의 앞에 추가 \n");
	LInsert(MyList, NewPoint(1, 2)); LInsert(MyList, NewPoint(2, 3)); LInsert(MyList, NewPoint(3, 4));
	LPrint(MyList);
	// SetSortRule(MyList, WhoIsPred) ;
	printf("\n오름차순 Sorting Rule 적용 자료 추가 \n");
	Sorting(MyList);
	for (a = 0; a < 10; a += 2) { //리스트에 자료 추가
		LInsert(MyList, NewPoint(A[a], A[a + 1]));
		LPrint(MyList);
	}
	printf("\n좌표에 3인 포함된 모든 점 삭제 \n");
	if (LFirst(MyList, point)) {
		if (point->x == 3 || point->y == 3) {
			rpoint = LRemove(MyList);
			printf("(%d,%d) 제거 \n", rpoint->x, rpoint->y); free(rpoint);
		}
		while (LNext(MyList, point)) {
			if (point->x == 3 || point->y == 3) {
				rpoint = LRemove(MyList);
				printf("(%d,%d) 제거 \n", rpoint->x, rpoint->y); free(rpoint);
			}
		}
	}
	printf("\n남아 있는 모든 점 리스트 \n");
	LPrint(MyList); //리스트 자료의 출력
}