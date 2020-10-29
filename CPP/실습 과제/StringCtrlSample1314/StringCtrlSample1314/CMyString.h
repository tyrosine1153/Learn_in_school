#pragma once
class CMyString
{
public:
	CMyString();
	CMyString(const CMyString& rhs) {
		this->m_pszData = rhs.m_pszData;
	}
	~CMyString();

private:
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;
	// ����� ���ڿ��� ����
	int m_nLength;
public:
	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();
};