#include "CMyList.h"

class CMyListEx : public CMyList
{
public:
	CMyListEx();
	CMyListEx(int headNum);   // int 매개변수 생성자
	CMyListEx(const CMyListEx& rhs);  // 복사생성자
	~CMyListEx();  // 소멸자

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
	string listName = "삭제된 리스트입니다";
};

/*
1. 생성자 다중화 O
2. 멤버변수로 포인터변수 필수, 메모리 동적할당 및 해제 필수 O
3. 접근제어 지시자로 private 필수 O
4. 멤버함수 상수화 O
5. 정적 멤버 변수 O
6. 연산자 다중정의 O
7. 상속 관계 O
8. 메서드 재정의(상속) O
9. 가상함수 O
*/