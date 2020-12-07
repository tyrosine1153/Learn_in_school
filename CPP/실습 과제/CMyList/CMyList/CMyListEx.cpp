using namespace std;
#include "CMyListEx.h"
#include <iostream>

CMyListEx::~CMyListEx() 
{
	while (m_nLength)
	{
		DNodeEx* del = headNode;
		headNode = headNode->linkR;
		delete del;
		m_nLength--;
	}
}
void CMyListEx::ShowMenu() 
{
	cout << "\n-----------------" << endl;
	cout << "CMyListEX �޴�" << endl;
	cout << "1 ���� Head" << endl;
	cout << "2 ���� Tail" << endl;
	cout << "3 ���� Head" << endl;
	cout << "4 ���� Tail" << endl;
	cout << "5 ��� Head -> Tail" << endl;
	cout << "6 ��� Tail -> Head" << endl;
	cout << "0 ����" << endl;
	cout << "-----------------" << endl;
	cout << " �޴��� ������(���� �Է�) : ";
}

void CMyListEx::InsertFront() 
{
	int num;
	cout << "\n ������ �����͸� �Է����ּ��� : ";
	cin >> num;

	DNodeEx* newNode = new DNodeEx();
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

	DNodeEx* newNode = new DNodeEx();
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

	DNodeEx* del = headNode;
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
	
	DNodeEx* del = tailNode;
	tailNode = tailNode->linkL;
	delete del;
	m_nLength--;

	Print();
}

void CMyListEx::Print() 
{
	DNodeEx* cur = headNode;
	cout << "\n CMyListEx ������ : [Head]";
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
	DNodeEx* cur = tailNode;
	cout << "\n CMyListEx ������ : [Head]";
	for (int i = 0; i < m_nLength; i++)
	{
		cout << " " << cur->data;
		cur = cur->linkL;
	}
	cout << " [Tail]" << endl;
	cout << " ������ ���� : " << m_nLength << "��" << endl;
}