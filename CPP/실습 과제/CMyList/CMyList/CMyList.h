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
	void Insert(); // ���ο� ��� ����(�޸� �Ҵ�) �� link����
	void Print();
private:
	DNode* headNode = nullptr;
	DNode* tailNode = nullptr;
	int m_nLength = 0;
};
