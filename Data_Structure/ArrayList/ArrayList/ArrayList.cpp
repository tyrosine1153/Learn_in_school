#include <stdio.h> //"ArrayList.cpp"
#include <string.h>
#include "ArrayList.h"
#include "List.h"

void InitList(List* plist) { //����Ʈ�� �ʱ�ȭ
	memset(plist->Array, 0, sizeof(Ldata) * LEN_List);
	plist->NumOfData = 0;
	plist->comp = NULL;
}

void SInsert(List* plist, Ldata pdata) { //���� ����
	int Cur = LCount(plist);
	while (Cur > 0 && plist->comp(plist->Array[Cur - 1], pdata)) { //���� �ڷᰡ ���� �ڷẸ�� ���� ������
		plist->Array[Cur] = plist->Array[Cur - 1]; //���� �ڷḦ �� �ڸ��� �ű��
		Cur--; //�ڸ��� ã�� ������ �ݺ�
	}
	plist->Array[Cur] = pdata; //ã���� �ڸ��� �ڷ� ����
}

void LInsert(List* plist, Ldata pdata) { //�ڷ� ����
	int Cur = LCount(plist);
	if (Cur >= LEN_List) {
		printf("����Ʈ�� ������ �ڷḦ �߰��� �� �����ϴ�\n");
		return;
	}
	if (Cur && plist->comp) SInsert(plist, pdata);
	else plist->Array[Cur] = pdata;
	plist->NumOfData++;
}
void LPrint(List* plist) {
	int a = 0;
	while (a < plist->NumOfData) {
		printf("%3d ", plist->Array[a++]);
	} printf("\n");
}

int LFirst(List* plist, Ldata* pdata) { //ù �ڷ�?
	if (LCount(plist)) { //����
		plist->CurPosition = 0;
		*pdata = plist->Array[0]; //ù �ڷ� ��
		return 1;
	}
	return 0;
}

int LNext(List* plist, Ldata* pdata) { //���� �ڷ�?
	if (plist->CurPosition < LCount(plist)) { //����
		plist->CurPosition++;
		*pdata = plist->Array[plist->CurPosition];
		return 1;
	}
	return 0;
}

Ldata LRemove(List* plist) { //�ڷ� ����
	if (LCount(plist)) {
		int rpos = plist->CurPosition; //������ ��ġ
		Ldata rdata = plist->Array[rpos]; //������ �ڷ�
		plist->CurPosition = rpos - 1; //������ ���� CurrentPosition
		while (rpos < plist->NumOfData) { //�ڷ��� ������ ������ �ڸ� ä��
			plist->Array[rpos] = plist->Array[rpos + 1];
			rpos++;
		}
		plist->NumOfData--;
		return rdata; //������ �ڷ� ��ȯ
	}
}

int LCount(List* plist) {
	return plist->NumOfData;
}

void SetSortRule(List* plist, int (*comp)(Ldata, Ldata)) {
	plist->comp = comp;
}