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
	void Insert(); // ���ο� ��� ����(�޸� �Ҵ�) �� link����
	virtual void Print();
protected:
	DNode* headNode = nullptr;
	DNode* tailNode = nullptr;
	int m_nLength = 0;
};

