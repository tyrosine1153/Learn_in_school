#include "CMyString.h"
#include <cstring>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

CMyString::CMyString() : m_pszData(nullptr), m_nLength(10) {}

CMyString::~CMyString() {}

CMyString::CMyString(const	char* pszParam)
	: m_pszData(nullptr), m_nLength(0) {
	SetString(pszParam);
}

CMyString::CMyString(const CMyString& rhs) {
	this->SetString(rhs.m_pszData);
	m_nLength = rhs.m_nLength;
}

CMyString::CMyString(CMyString&& rhs) {
	this->SetString(rhs.m_pszData);
	m_nLength = rhs.m_nLength;
	rhs.m_pszData = nullptr;
	rhs.m_nLength = 0;
}

int CMyString::GetLength() const {
	return m_nLength;
}

CMyString::operator char* () const {
	return m_pszData;
}

char& CMyString::operator[](int nIndex) {
	return m_pszData[nIndex];
}

char CMyString::operator[](int nIndex) const {
	return m_pszData[nIndex];
}

int CMyString::operator==(const CMyString& rhs) {
	if (m_pszData != NULL && rhs.m_pszData != NULL) {
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 1;
	}
	return 0;
}

int CMyString::operator!=(const CMyString& rhs) {
	if (m_pszData != NULL && rhs.m_pszData != NULL) {
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 0;
	}
	return 1;
}

CMyString CMyString::operator+(const CMyString& rhs) {
	CMyString result(*this);
	result.Append(rhs.m_pszData);
	return result;
}

CMyString& CMyString::operator+=(const CMyString& rhs) {
	Append(rhs.m_pszData);
	return *this;
}

CMyString& CMyString::operator=(const CMyString& rhs) {
	this->SetString(rhs.m_pszData);
	return *this;
}

int CMyString::SetString(const char* pszParam) {
	int nLenParam = strlen(pszParam);
	if (pszParam == NULL || nLenParam == 0)
		return 0;
	m_pszData = new char[nLenParam+1];
	strcpy(m_pszData, pszParam);
	m_nLength = nLenParam;
	
	return 0;
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

	// �� ���ڿ��� ���ļ� ������ �� �ִ� �޸𸮸� ���� �Ҵ���
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