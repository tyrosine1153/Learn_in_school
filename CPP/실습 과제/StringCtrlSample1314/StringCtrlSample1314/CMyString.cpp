#include "CMyString.h"
#include <cstring>

CMyString::CMyString()
	:m_pszData(nullptr)
	, m_nLength(0)
{
}

CMyString::~CMyString()
{
}


int CMyString::SetString(const char* pszParam)
{
	char error[6] = "error";
	m_nLength = strlen(pszParam);
	m_pszData = new char[m_nLength];
	if (m_nLength == 0 || pszParam == NULL) m_pszData = error;
	else
		m_pszData = (char*)pszParam;
	return 0;
}


const char* CMyString::GetString() const
{
	return m_pszData;
}


void CMyString::Release() const
{
	delete m_pszData;
}