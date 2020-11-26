#pragma once
class CMyString
{
public:
	CMyString();
	~CMyString();
	explicit CMyString(const char* pszParam);  // ��ȯ������
	
	CMyString(const CMyString& rhs);  // ���������
	CMyString(CMyString&& rhs);  // �̵�������
	
	int GetLength() const;
	
	operator char* () const;  // ����ȯ ������
	char& operator[](int nIndex);
	char operator[](int nIndex) const;
	int operator==(const CMyString& rhs);
	int operator!=(const CMyString& rhs);

	CMyString operator+(const CMyString& rhs);  // ������
	CMyString& operator+=(const CMyString& rhs);
	CMyString& operator=(const CMyString& rhs);  // ���Կ�����
protected:
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;
	// ����� ���ڿ��� ����
	int m_nLength;
public:
	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();
	// this ��ü m_pszData�� ���ڿ��� ��ġ�� �Լ�
	int Append(const char* pszParam);
};