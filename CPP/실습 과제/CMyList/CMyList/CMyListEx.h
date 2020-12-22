#include "CMyList.h"

class CMyListEx : public CMyList
{
public:
	CMyListEx();
	CMyListEx(int headNum);   // int �Ű����� ������
	CMyListEx(const CMyListEx& rhs);  // ���������
	~CMyListEx();  // �Ҹ���

	int operator[](int index) const;
	int& operator[](int index);
	
	virtual void ShowMenu() const;
	void InsertFront();
	void InsertBack();
	void DeleteFront();
	void DeleteBack();
	virtual void Print();
	void PrintReverse();
	void SetName(string str);
	string GetName() const;

	static int listCount;
private:
	string listName = "������ ����Ʈ�Դϴ�";
};

/*
1. ������ ����ȭ O
2. ��������� �����ͺ��� �ʼ�, �޸� �����Ҵ� �� ���� �ʼ� O
3. �������� �����ڷ� private �ʼ� O
4. ����Լ� ���ȭ O
5. ���� ��� ���� O
6. ������ �������� O
7. ��� ���� O
8. �޼��� ������(���) O
9. �����Լ� O
*/