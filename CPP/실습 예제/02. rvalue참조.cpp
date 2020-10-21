#include<iostream>

int TestFunc(int nParam) {
	return nParam;
}

int main() {
	int nInput = 0;
	std::cout << "Input number : ";
	std::cin >> nInput;

	/* r-value 참조, c++11 문법. 자료형&& 이름 = 원본;
	r-value - 대입 연산자의 두 피연산자 중 오른쪽에 위치한 것
	일반적인 변수와 상수 모두 해당. 연산에 따라 생성된 임시객체*/
	int&& rData = nInput + 5;
	std::cout << rData << std::endl;
	std::cout << nInput << std::endl;

	int&& result = TestFunc(10);

	result += 10;
	std::cout << result << std::endl;

	return 0;
}
