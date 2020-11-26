#include "CMyStringEx.h"
#include <cstring>
#include <iostream>
#pragma warning(disable:4996)

CMyStringEx::CMyStringEx(const char* pszParam) {
	m_pszData = nullptr;
	m_nLength = 0;
	SetString(pszParam);
}

int CMyStringEx::Find(const char* pszParam) {
    char* ptr = strstr(m_pszData, pszParam);
    if (ptr != NULL)
        return m_nLength - strlen(ptr);
    return -1;
}

void CMyStringEx::OnSetString(char* pszData, int nLength)
{
	if (strcmp(pszData, "¸Û¸ÛÀÌ¾Æµé") == 0) {
		strcpy(pszData, "*ÂøÇÑ¾Æµé*");
	}
}
