#include<iostream>
using namespace std;
typedef struct DNode
{
	int data;
	DNode* linkL;
	DNode* linkR;
}DNode;

class CMyList
{
public:
	CMyList() {}
	~CMyList();
	virtual void ShowMenu();
	void Insert(); // 새로운 노드 생성(메모리 할당) 및 link연결
	virtual void Print();
protected:
	DNode* headNode = nullptr;
	DNode* tailNode = nullptr;
	int m_nLength = 0;
};

