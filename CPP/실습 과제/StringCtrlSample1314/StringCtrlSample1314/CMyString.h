#pragma once
class CMyString
{
public:
	CMyString();
	~CMyString();
	explicit CMyString(const char* pszParam);  // 변환생성자
	
	CMyString(const CMyString& rhs);  // 복사생성자
	CMyString(CMyString&& rhs);  // 이동생성자
	
	int GetLength() const;
	
	operator char* () const;  // 형변환 연산자
	char& operator[](int nIndex);
	char operator[](int nIndex) const;
	int operator==(const CMyString& rhs);
	int operator!=(const CMyString& rhs);

	CMyString operator+(const CMyString& rhs);  // 연산자
	CMyString& operator+=(const CMyString& rhs);
	CMyString& operator=(const CMyString& rhs);  // 대입연산자
protected:
	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData;
	// 저장된 문자열의 길이
	int m_nLength;
public:
	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();
	// this 객체 m_pszData에 문자열을 합치는 함수
	int Append(const char* pszParam);
};