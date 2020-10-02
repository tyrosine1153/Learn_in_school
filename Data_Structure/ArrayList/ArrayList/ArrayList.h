#ifndef _ARRAY_LIST_H_ //"ArrayList.h"
#define _ARRAY_LIST_H_
#define LEN_List 50

typedef int Ldata;

typedef struct _arraylist {
	Ldata Array[LEN_List]; //�ڷ� ���� �迭
	int CurPosition; //���� �ε���
	int NumOfData; //���� �ڷ� ����
	int (*comp)(Ldata, Ldata);
} ArrayList;

typedef ArrayList List;

#endif