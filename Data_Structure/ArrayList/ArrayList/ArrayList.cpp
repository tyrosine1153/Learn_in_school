#include <stdio.h> //"ArrayList.cpp"
#include <string.h>
#include "ArrayList.h"
#include "List.h"

void InitList(List* plist) { //리스트의 초기화
	memset(plist->Array, 0, sizeof(Ldata) * LEN_List);
	plist->NumOfData = 0;
	plist->comp = NULL;
}

void SInsert(List* plist, Ldata pdata) { //정렬 삽입
	int Cur = LCount(plist);
	while (Cur > 0 && plist->comp(plist->Array[Cur - 1], pdata)) { //앞의 자료가 기준 자료보다 작을 때까지
		plist->Array[Cur] = plist->Array[Cur - 1]; //앞의 자료를 뒤 자리로 옮기고
		Cur--; //자리를 찾을 때까지 반복
	}
	plist->Array[Cur] = pdata; //찾아진 자리에 자료 저장
}

void LInsert(List* plist, Ldata pdata) { //자료 삽입
	int Cur = LCount(plist);
	if (Cur >= LEN_List) {
		printf("리스트가 꽉차서 자료를 추가할 수 없습니다\n");
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

int LFirst(List* plist, Ldata* pdata) { //첫 자료?
	if (LCount(plist)) { //있음
		plist->CurPosition = 0;
		*pdata = plist->Array[0]; //첫 자료 값
		return 1;
	}
	return 0;
}

int LNext(List* plist, Ldata* pdata) { //다음 자료?
	if (plist->CurPosition < LCount(plist)) { //있음
		plist->CurPosition++;
		*pdata = plist->Array[plist->CurPosition];
		return 1;
	}
	return 0;
}

Ldata LRemove(List* plist) { //자료 삭제
	if (LCount(plist)) {
		int rpos = plist->CurPosition; //삭제할 위치
		Ldata rdata = plist->Array[rpos]; //삭제할 자료
		plist->CurPosition = rpos - 1; //삭제한 후의 CurrentPosition
		while (rpos < plist->NumOfData) { //자료의 끝까지 지워진 자리 채움
			plist->Array[rpos] = plist->Array[rpos + 1];
			rpos++;
		}
		plist->NumOfData--;
		return rdata; //삭제된 자료 반환
	}
}

int LCount(List* plist) {
	return plist->NumOfData;
}

void SetSortRule(List* plist, int (*comp)(Ldata, Ldata)) {
	plist->comp = comp;
}