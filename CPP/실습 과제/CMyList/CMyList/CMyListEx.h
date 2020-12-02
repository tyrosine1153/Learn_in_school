#pragma once
#include "CMyList.h"

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
	DNode* headNode = nullptr;
	DNode* tailNode = nullptr;
	int m_nLength = 0;
};
