#ifndef _ARRAY_LIST_H_ //"ArrayList.h"
#define _ARRAY_LIST_H_
#define LEN_List 50

typedef int Ldata;

typedef struct _arraylist {
	Ldata Array[LEN_List]; //자료 저장 배열
	int CurPosition; //현재 인덱스
	int NumOfData; //저장 자료 개수
	int (*comp)(Ldata, Ldata);
} ArrayList;

typedef ArrayList List;

#endif