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
	while (Tmp = Tmp->Next) { //ù ��° �ڷ���� ��� �ڷ��� �����͸�
		Addr[su++] = Tmp; //�迭�� ����
	}
	plist->Head->Next->Next = NULL; //ù �ڷ��� Next�� NULL�� ����
	plist->NumOfData = 1;
	for (a = 1; a < su; a++) { //�� ��° �ڷ� ���ĺ��� ��� �ڷḦ
		Addr[a]->Next = 0; //Next �����͸� NULL�� �����Ͽ�
		LInsert(plist, Addr[a]); //����Ʈ�� �߰�(Sorting Rule ����)
	}
}

int main(void) {
	List* MyList = (List*)malloc(sizeof(List));
	int a, A[10] = { 6,2,7,9,8,3,5,4,0,1 };
	Ldata point = (Point*)malloc(sizeof(Point)), rpoint;
	InitList(MyList); //����Ʈ�� �ʱ�ȭ
	printf("\n���ο� ��带 ����Ʈ�� �տ� �߰� \n");
	LInsert(MyList, NewPoint(1, 2)); LInsert(MyList, NewPoint(2, 3)); LInsert(MyList, NewPoint(3, 4));
	LPrint(MyList);
	// SetSortRule(MyList, WhoIsPred) ;
	printf("\n�������� Sorting Rule ���� �ڷ� �߰� \n");
	Sorting(MyList);
	for (a = 0; a < 10; a += 2) { //����Ʈ�� �ڷ� �߰�
		LInsert(MyList, NewPoint(A[a], A[a + 1]));
		LPrint(MyList);
	}
	printf("\n��ǥ�� 3�� ���Ե� ��� �� ���� \n");
	if (LFirst(MyList, point)) {
		if (point->x == 3 || point->y == 3) {
			rpoint = LRemove(MyList);
			printf("(%d,%d) ���� \n", rpoint->x, rpoint->y); free(rpoint);
		}
		while (LNext(MyList, point)) {
			if (point->x == 3 || point->y == 3) {
				rpoint = LRemove(MyList);
				printf("(%d,%d) ���� \n", rpoint->x, rpoint->y); free(rpoint);
			}
		}
	}
	printf("\n���� �ִ� ��� �� ����Ʈ \n");
	LPrint(MyList); //����Ʈ �ڷ��� ���
}