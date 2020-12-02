#pragma once
#include<iostream>
using namespace std;
typedef struct DNode
{
	int data;
	DNode* link;
};

class CMyList
{
public:
	CMyList() {}
	~CMyList();
	void ShowMenu();
	void Insert(); // 새로운 노드 생성(메모리 할당) 및 link연결
	void Print();
private:
	DNode* headNode = nullptr;
	DNode* tailNode = nullptr;
	int m_nLength = 0;
};
