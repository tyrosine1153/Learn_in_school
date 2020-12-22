using namespace std;
#include <string.h>
#include "CMyListEx.h"

int CMyListEx::listCount = 0;

CMyListEx::CMyListEx() {
	//cout << listName << endl;
}

CMyListEx::CMyListEx(int headNum) 
{
	DNode* newNode = new DNode();
	newNode->data = headNum;
	newNode->linkL = nullptr;
	newNode->linkR = nullptr;
	headNode = newNode;
	tailNode = newNode;
	m_nLength++;

	Print();
}

CMyListEx::CMyListEx(const CMyListEx& rhs) 
{
	listName = rhs.GetName();
	for (int i = 0; i < rhs.m_nLength; i++)
	{
		DNode* newNode = new DNode();
		newNode->data = rhs[i];
		newNode->linkL = nullptr;
		newNode->linkR = nullptr;

		if (i == 0)
		{
			headNode = newNode;
			tailNode = newNode;
			m_nLength++;
		}
		else
		{
			tailNode->linkR = newNode;
			newNode->linkL = tailNode;
			tailNode = newNode;
			m_nLength++;
		}
	}
}

CMyListEx::~CMyListEx() 
{
	while (m_nLength)
	{
		DNode* del = headNode;
		headNode = headNode->linkR;
		delete del;
		m_nLength--;
	}
}

int CMyListEx::operator[](int index) const
{
	DNode* cur = headNode;
	for (int i = 0; i < index; i++) 
	{
		cur = cur->linkR;
	}

	return cur->data;
}

int& CMyListEx::operator[](int index)
{
	DNode* cur = headNode;
	for (int i = 0; i < index; i++)
	{
		cur = cur->linkR;
	}

	return cur->data;
}

void CMyListEx::ShowMenu() const
{
	cout << "\n----"<<this->listName<<"----" << endl;
	cout << "����Ʈ �޴�" << endl;
	cout << "1 ���� Head" << endl;
	cout << "2 ���� Tail" << endl;
	cout << "3 ���� Head" << endl;
	cout << "4 ���� Tail" << endl;
	cout << "5 ��� Head -> Tail" << endl;
	cout << "6 ��� Tail -> Head" << endl;
	cout << "0 ����Ʈ ������" << endl;
	cout << "-----------------" << endl;
	cout << " �޴��� ������(���� �Է�) : ";
}

void CMyListEx::InsertFront()
{
	int num;
	cout << "\n ������ �����͸� �Է����ּ��� : ";
	cin >> num;

	DNode* newNode = new DNode();
	newNode->data = num;
	newNode->linkL = nullptr;
	newNode->linkR = nullptr;

	if (m_nLength == 0)
	{
		headNode = newNode;
		tailNode = newNode;
		m_nLength++;
	}
	else
	{
		headNode->linkL = newNode;
		newNode->linkR = headNode;
		headNode = newNode;
		m_nLength++;
	}

	Print();
}

void CMyListEx::InsertBack() 
{
	int num;
	cout << "\n ������ �����͸� �Է����ּ��� : ";
	cin >> num;

	DNode* newNode = new DNode();
	newNode->data = num;
	newNode->linkL = nullptr;
	newNode->linkR = nullptr;

	if (m_nLength == 0)
	{
		headNode = newNode;
		tailNode = newNode;
		m_nLength++;
	}
	else
	{
		tailNode->linkR = newNode;
		newNode->linkL = tailNode;
		tailNode = newNode;
		m_nLength++;
	}

	Print();
}

void CMyListEx::DeleteFront() 
{
	if (m_nLength == 0)
	{
		cout << "\n ����� �����Ͱ� �����ϴ�." << endl;
		return;
	}

	DNode* del = headNode;
	headNode = headNode->linkR;
	delete del;
	m_nLength--;

	Print();
}

void CMyListEx::DeleteBack() 
{
	if (m_nLength == 0)
	{
		cout << "\n ����� �����Ͱ� �����ϴ�." << endl;
		return;
	}
	
	DNode* del = tailNode;
	tailNode = tailNode->linkL;
	delete del;
	m_nLength--;

	Print();
}

void CMyListEx::Print()
{
	DNode* cur = headNode;
	cout << "\n ����Ʈ ������ : [Head]";
	for (int i = 0; i < m_nLength; i++)
	{
		cout << " " << cur->data;
		cur = cur->linkR;
	}
	cout << " [Tail]" << endl;
	cout << " ������ ���� : " << m_nLength << "��" << endl;
}

void CMyListEx::PrintReverse() 
{
	DNode* cur = tailNode;
	cout << "\n ����Ʈ ������ : [Head]";
	for (int i = 0; i < m_nLength; i++)
	{
		cout << " " << cur->data;
		cur = cur->linkL;
	}
	cout << " [Tail]" << endl;
	cout << " ������ ���� : " << m_nLength << "��" << endl;
}

void CMyListEx::SetName(string str)
{
	listName = str;
}

string CMyListEx::GetName() const 
{
	return listName;
}