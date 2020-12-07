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
	cout << "CMyListEX 메뉴" << endl;
	cout << "1 삽입 Head" << endl;
	cout << "2 삽입 Tail" << endl;
	cout << "3 삭제 Head" << endl;
	cout << "4 삭제 Tail" << endl;
	cout << "5 출력 Head -> Tail" << endl;
	cout << "6 출력 Tail -> Head" << endl;
	cout << "0 종료" << endl;
	cout << "-----------------" << endl;
	cout << " 메뉴를 고르세요(숫자 입력) : ";
}

void CMyListEx::InsertFront() 
{
	int num;
	cout << "\n 삽입할 데이터를 입력해주세요 : ";
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
	cout << "\n 삽입할 데이터를 입력해주세요 : ";
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
		cout << "\n 출력할 데이터가 없습니다." << endl;
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
		cout << "\n 출력할 데이터가 없습니다." << endl;
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
	cout << "\n CMyListEx 데이터 : [Head]";
	for (int i = 0; i < m_nLength; i++)
	{
		cout << " " << cur->data;
		cur = cur->linkR;
	}
	cout << " [Tail]" << endl;
	cout << " 데이터 개수 : " << m_nLength << "개" << endl;
}

void CMyListEx::PrintReverse() 
{
	DNodeEx* cur = tailNode;
	cout << "\n CMyListEx 데이터 : [Head]";
	for (int i = 0; i < m_nLength; i++)
	{
		cout << " " << cur->data;
		cur = cur->linkL;
	}
	cout << " [Tail]" << endl;
	cout << " 데이터 개수 : " << m_nLength << "개" << endl;
}