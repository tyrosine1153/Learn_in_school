#include<iostream>
// namepace : c++가 지원하는 각종 요소들을 한 범주로 묶어주기 위한 문법
// 의미상 소속 구역

namespace TEST {
    int g_nData = 100;
    void TestFunc() {
        std::cout << "TEST:: TestFunc()" << std::endl;
    }
}

int main() {
    TEST::TestFunc();
    std::cout << TEST::g_nData << std::endl;

    return 0;
}
// namespace가 존재할 경우 식별자 앞에 범위지정 연산자 ::을 이용해 namespace를 기술할 수 있다
// main()함수는 Global namespace에 속함
//cout, TestFunc(), main()은 각자 속한 namespace가 모두 다름
