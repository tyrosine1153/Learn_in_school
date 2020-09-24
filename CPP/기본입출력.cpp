#include <iostream>

int main() {
	std::cout << "Hello World!!\n";
	//cout : 콘솔 출력을 담당하는 객체. << : 연산자, std : namespace라고 하며 소속의 개념, :: : 범위 지정 연산자, 스코프 설정 연산자
	//std에 속한 cout객체에 문자열을 넘겨 출력하도록 함
	std::string strname;
	std::cin >> strname;
	std::cout << strname;
	return 0;
}