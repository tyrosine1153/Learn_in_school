#include <iostream>
#include "CMyString.h"
using namespace std;

int main()
{
    CMyString strData;
    strData.SetString("");
    cout << strData.GetString() << endl;
    strData.Release();
    return 0;
}