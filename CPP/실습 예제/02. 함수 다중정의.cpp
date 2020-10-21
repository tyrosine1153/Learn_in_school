#include<iostream>

/*다중정의: 한개의 함수나 변수이름이 여러 의미를 동시에 갖는 것
매개변수의 구성이나 함수원형이 달라지면 이름이 같더라도 구분된다.
c++은 함수의 다형성을 지원한다
다중정의에 영항을 주는 것-> 매개변수 뿐이다*/

int Add(int a, int b, int c) {
    std::cout << "Add(int, int, int):";
    return a + b + c;
}
int Add(int a, int b) {
    std::cout << "Add(int, int):";
    return a + b;
}
int Add(double a, double b) {
    std::cout << "Add(double, double):";
    return a + b;
}

int main() {
    std::cout << Add(3, 4) << std::endl;
    std::cout << Add(3, 4, 5) << std::endl;
    std::cout << Add(3.3, 4.4) << std::endl;
}
