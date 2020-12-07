#pragma once
#include "CMyList.h"

typedef struct DNodeEx
{
	int data;
	DNodeEx* linkL;
	DNodeEx* linkR;
};

class CMyListEx : public CMyList
{
public:
	CMyListEx() {}
	~CMyListEx();
	void ShowMenu();
	void InsertFront();
	void InsertBack();
	void DeleteFront();
	void DeleteBack();
	void Print();
	void PrintReverse();
private:
	DNodeEx* headNode = nullptr;
	DNodeEx* tailNode = nullptr;
	int m_nLength = 0;
};
