#pragma once
class CMyString
{
public:
	CMyString();
	CMyString(const CMyString& rhs);  // 복사생성자
	explicit CMyString(const char* pszParam);  // 변환생성자
	operator char* () const;  // 형변환 연산자
	CMyString(CMyString&& rhs);  // 이동생성자
	~CMyString();
	int GetLength() const;
	CMyString operator+(const CMyString& rhs);  // 연산자
	CMyString& operator+=(const CMyString& rhs);
	CMyString& operator=(const CMyString& rhs);  // 대입연산자
	char& operator[](int nIndex);
	char operator[](int nIndex) const;
private:
	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData;
	// 저장된 문자열의 길이
	int m_nLength;
public:
	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();
	int Append(const char* pszParam);
};