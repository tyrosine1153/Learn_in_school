#include<iostream>

int main() {
	int nData = 10;

	int& ref = nData; //참조자
	ref = 20;
	std::cout << nData << std::endl;

	int* pnData = &nData; //포인터
	*pnData = 30;
	std::cout << nData << std::endl;

	std::cout << ref << std::endl; // ref가 가리키는 값
	std::cout << pnData << std::endl; // 주소
	return 0;
}