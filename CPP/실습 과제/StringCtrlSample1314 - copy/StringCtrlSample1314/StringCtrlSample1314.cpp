﻿#include <iostream>
#include "CMyString.h"
#include "CMyStringEx.h"
using namespace std;

int	main()
{
	CMyStringEx	strTest;
	//	문자열이	필터링	되어	대체되는	경우
	strTest.SetString("멍멍이아들");
	cout << strTest << endl;
	//	필터링	되지	않는	경우
	strTest.SetString("학번 : 1314, 이름 : 유정민");
	cout << strTest << endl;
	return	0;
}
