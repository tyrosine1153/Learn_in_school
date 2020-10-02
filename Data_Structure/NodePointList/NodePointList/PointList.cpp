#include <stdio.h> //"PointListmain.cpp"
#include <stdlib.h>
#include "Point.h"
#include "List.h"

void InitList(List* plist) { //리스트의 초기화
	Ldata Head = (Point*)malloc(sizeof(Point));
	Head->Next = NULL;
	plist->Head = Head;
	plist->Head->Next = NULL;
	plist->NumOfData = 0;
	plist->comp = NULL;
}

void PrintNode(Ldata pnode) {
	printf("(%d,%d) ", pnode->x, pnode->y);
}

void LPrint(List* plist) {
	if (LCount(plist)) {
		Ldata pdata = plist->Head->Next;
		while (pdata) {
			PrintNode(pdata);
			pdata = pdata->Next;
		} printf("\n");
	}
}

void SInsert(List* plist, Ldata pdata) {
	Ldata Before = plist->Head;
	while (Before->Next && plist->comp(pdata, Before->Next)) {
		Before = Before->Next;
	}
	pdata->Next = Before->Next;
	Before->Next = pdata;
}

void LInsert(List* plist, Ldata pdata) {
	if (plist->comp)
		SInsert(plist, pdata);
	else {
		pdata->Next = plist->Head->Next;
		plist->Head->Next = pdata;
	}
	plist->NumOfData++;
}

int LFirst(List* plist, Ldata pdata) { //첫 자료?
	if (LCount(plist)) {
		plist->Before = plist->Head;
		plist->Cur = plist->Head->Next;
		pdata->x = plist->Cur->x;
		pdata->y = plist->Cur->y;
		return 1; //첫 자료 있음
	}
	return 0; //저장된 자료가 없음
}

int LNext(List* plist, Ldata pdata) { //다음 자료?
	if (plist->Cur->Next) {
		plist->Before = plist->Cur;
		plist->Cur = plist->Cur->Next;
		pdata->x = plist->Cur->x;
		pdata->y = plist->Cur->y;
		return 1; //다음 자료 있음
	}
	return 0; //다음 자료 없음
}

Ldata LRemove(List* plist) { //자료 삭제
	if (LCount(plist)) {
		Ldata rpos = plist->Cur; //삭제할 위치
		plist->Before->Next = rpos->Next;
		plist->Cur = plist->Before; //삭제한 후의 CurrentPosition
		plist->NumOfData--; //자료 개수 감소
		return rpos; //삭제된 자료 반환
	}
}

int LCount(List* plist) {
	return plist->NumOfData;
}

void SetSortRule(List* plist, int (*comp)(Ldata, Ldata)) {
	plist->comp = comp;
}