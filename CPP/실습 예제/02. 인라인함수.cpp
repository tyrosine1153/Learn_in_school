#include<iostream>
#define ADD(a,b) ((a)+(b))

int Add(int a, int b) {
    return a + b;
}

inline int AddNew(int a, int b) {
    return a + b;
}

int main() {
    int a, b;
    std::cin >> a >> b;

    std::cout << "ADD() : " << ADD(a, b) << std::endl;  // 메크로 : 함수가 아님, 매개변수에 형식 지정 불가
    std::cout << "ADD() : " << Add(a, b) << std::endl;  // 함수 : 호출시 내부적으로 여러 연산들의 오버헤드
    std::cout << "AddNew() : " << AddNew(a, b) << std::endl;

    return 0;
}
/*
입력 :
10 15

출력 :
ADD() : 25
ADD() : 25
AddNew() : 25

inline 예약어를 빼면 기존 함수와 다를 바 없음. 문법적으로 완벽한 함수, 컴파일러 최적화 어쩌구.
*/
