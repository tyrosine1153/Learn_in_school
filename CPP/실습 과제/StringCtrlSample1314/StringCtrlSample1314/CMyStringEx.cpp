#include "CMyStringEx.h"
#include <cstring>

int CMyStringEx::Find(const char* pszParam) {
    char* ptr = strstr(m_pszData, pszParam);
    if (ptr != NULL)
        return m_nLength - strlen(ptr);
    return -1;
}
