#pragma once
class CMyString
{
public:
	CMyString();
	CMyString(const CMyString& rhs);  // ���������
	explicit CMyString(const char* pszParam);  // ��ȯ������
	operator char* () const;  // ����ȯ ������
	CMyString(CMyString&& rhs);  // �̵�������
	~CMyString();
	int GetLength() const;
	CMyString operator+(const CMyString& rhs);  // ������
	CMyString& operator+=(const CMyString& rhs);
	CMyString& operator=(const CMyString& rhs);  // ���Կ�����
	char& operator[](int nIndex);
	char operator[](int nIndex) const;
private:
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;
	// ����� ���ڿ��� ����
	int m_nLength;
public:
	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();
	int Append(const char* pszParam);
};