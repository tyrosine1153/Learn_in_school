using namespace std;
#include "CMyList.h"

CMyList::~CMyList() 
{
	while (m_nLength)
	{
		DNode* del = headNode;
		headNode = headNode->linkL;
		delete del;
		m_nLength--;
	}
}

void CMyList::ShowMenu() 
{
	cout << "\n-----------------" << endl;
	cout << "CMyList �޴�" << endl;
	cout << "1 ����" << endl;
	cout << "2 ���" << endl;
	cout << "0 ����" << endl;
	cout << "-----------------" << endl;
	cout << " �޴��� ������(���� �Է�) : ";
}

void CMyList::Insert()
{
	int num;
	cout << "\n ������ �����͸� �Է����ּ��� : ";
	cin >> num;

	DNode* newNode = new DNode();
	newNode->data = num;
	newNode->linkL = nullptr;

	if (m_nLength == 0)
	{
		headNode = newNode;
		tailNode = newNode;
		m_nLength++;
	}
	else 
	{	
		tailNode->linkL = newNode;
		tailNode = newNode;
		m_nLength++;
	}

	Print();
}

void CMyList::Print() 
{
	DNode* cur = headNode;
	cout << "\n CMyList ������ : [Head]";
	for (int i = 0; i < m_nLength; i++)
	{
		cout << " " << cur->data;
		cur = cur->linkL;
	}
	cout << " [Tail]" << endl;
	cout << " ������ ���� : " << m_nLength << "��" << endl;
}