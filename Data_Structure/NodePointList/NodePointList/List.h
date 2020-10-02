#ifndef _LIST_H_ //"List.h"
#define _LIST_H_

void InitList(List*); //리스트의 초기화
void LInsert(List*, Ldata); //자료 삽입
int LFirst(List*, Ldata); //첫 자료?
int LNext(List*, Ldata); //다음 자료?

Ldata LRemove(List*); //자료 삭제
void LPrint(List*); //리스트 자료 출력
int LCount(List*); //리스트 자료 개수
//정렬 규칙
void SetSortRule(List*, int (*comp)(Ldata, Ldata));

#endif