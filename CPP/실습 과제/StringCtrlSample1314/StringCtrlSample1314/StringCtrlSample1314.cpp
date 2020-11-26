#include <iostream>
#include "CMyString.h"
#include "CMyStringEx.h"
using namespace std;

int	main()
{
	CMyStringEx	strTest;
	strTest.SetString("학번 : 1314, 이름 : 유정민");
	cout << strTest << endl;
	int	nIndex = strTest.Find("유정민");
	cout << "Index : " << nIndex << endl;
	return	0;
}
