#include "CMyString.h"
#include <cstring>
using namespace std;

CMyString::CMyString() : m_pszData(nullptr), m_nLength(10) {}

CMyString::CMyString(const CMyString& rhs) {
	m_pszData = new char;
	*m_pszData = *rhs.m_pszData;
	m_nLength = rhs.m_nLength;
}

CMyString& CMyString::operator=(const CMyString & rhs){
	m_pszData = new char;
	*m_pszData = *rhs.m_pszData;
	m_nLength = rhs.m_nLength;
	return *this;
}

CMyString::~CMyString() {}

CMyString::CMyString(const	char* pszParam) 
	:m_pszData(nullptr), m_nLength(0) {
	SetString(pszParam);
}

CMyString::operator char* () const {
	return m_pszData;
}

CMyString::CMyString(CMyString&& rhs) : m_pszData(nullptr), m_nLength(0) {
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;
	rhs.m_pszData = nullptr;
	rhs.m_nLength = 0;
}

CMyString CMyString::operator+(const CMyString& rhs) {
	return CMyString();
}

CMyString& CMyString::operator+=(const CMyString& rhs) {
	// return 
}

char& CMyString::operator[](int nIndex) {

}

char CMyString::operator[](int nIndex) const {

}

int CMyString::SetString(const char* pszParam) {
	char error[6] = "error";
	m_nLength = strlen(pszParam);
	m_pszData = new char[m_nLength];
	if (m_nLength == 0 || pszParam == NULL) m_pszData = error;
	else
		m_pszData = (char*)pszParam;
	return 0;
}

int CMyString::GetLength() const {
	return m_nLength;
}

const char* CMyString::GetString() const {
	return m_pszData;
}

void CMyString::Release() {
	delete m_pszData;
}

int CMyString::Append(const char* pszParam) {
	// �Ű����� ��ȿ�� �˻�
	if (pszParam == NULL)
		return 0;
	
	int nLenParam = strlen(pszParam);
	if (nLenParam == 0)
		return 0;

	// ��Ʈ�� ���ڿ��� ���ٸ� ���� ���ڿ��� �Ҵ��� �Ͱ� �����ϰ� ó����
	if (m_pszData == NULL) {
		SetString(pszParam);
		return m_nLength;
	}

	// ���� ���ڿ��� ���� ���
	int nLenCur = m_nLength;
	char* pszResult = new char[nLenCur + nLenParam + 1];

	// ���ڿ� ����
	strcpy(pszResult, m_pszData);
	strcpy(pszResult + (sizeof(char) * nLenCur), pszParam);

	// ���� ���ڿ� ���� �� ��� ���� ����
	Release();

	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;

	return 0;
}