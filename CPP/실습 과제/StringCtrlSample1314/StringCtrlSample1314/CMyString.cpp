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
	// 매개변수 유효성 검사
	if (pszParam == NULL)
		return 0;
	
	int nLenParam = strlen(pszParam);
	if (nLenParam == 0)
		return 0;

	// 세트된 문자열이 없다면 새로 문자열을 할당한 것과 동일하게 처리함
	if (m_pszData == NULL) {
		SetString(pszParam);
		return m_nLength;
	}

	// 현재 문자열의 길이 백업
	int nLenCur = m_nLength;

	// 두 문자열을 합쳐서 저장할 수 있는 메모리를 새로 할당함
	char* pszResult = new char[nLenCur + nLenParam + 1];

	// 문자열 조합
	strcpy(pszResult, m_pszData);
	strcpy(pszResult + (sizeof(char) * nLenCur), pszParam);
	
	// 기존 문자열 삭제 및 멤버 정보 갱신
	Release();

	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;

	return 0;
}