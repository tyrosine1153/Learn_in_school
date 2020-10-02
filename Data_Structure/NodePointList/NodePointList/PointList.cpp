#include <stdio.h> //"PointListmain.cpp"
#include <stdlib.h>
#include "Point.h"
#include "List.h"

void InitList(List* plist) { //����Ʈ�� �ʱ�ȭ
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

int LFirst(List* plist, Ldata pdata) { //ù �ڷ�?
	if (LCount(plist)) {
		plist->Before = plist->Head;
		plist->Cur = plist->Head->Next;
		pdata->x = plist->Cur->x;
		pdata->y = plist->Cur->y;
		return 1; //ù �ڷ� ����
	}
	return 0; //����� �ڷᰡ ����
}

int LNext(List* plist, Ldata pdata) { //���� �ڷ�?
	if (plist->Cur->Next) {
		plist->Before = plist->Cur;
		plist->Cur = plist->Cur->Next;
		pdata->x = plist->Cur->x;
		pdata->y = plist->Cur->y;
		return 1; //���� �ڷ� ����
	}
	return 0; //���� �ڷ� ����
}

Ldata LRemove(List* plist) { //�ڷ� ����
	if (LCount(plist)) {
		Ldata rpos = plist->Cur; //������ ��ġ
		plist->Before->Next = rpos->Next;
		plist->Cur = plist->Before; //������ ���� CurrentPosition
		plist->NumOfData--; //�ڷ� ���� ����
		return rpos; //������ �ڷ� ��ȯ
	}
}

int LCount(List* plist) {
	return plist->NumOfData;
}

void SetSortRule(List* plist, int (*comp)(Ldata, Ldata)) {
	plist->comp = comp;
}