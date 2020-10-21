#include<iostream>

int TestFunc(int nParam = 10) {//nParam 매개변수의 디폴트 값은 10이다
    return nParam;
}

int TestFunc2(int nParam = 10);
//함수의 정의와 선언을 나눌경우 선언 부분에 디폴트 값을 기술해야 함

int TestFunc2(int nParam1, int nParam2 = 10) {
    return nParam * nParam;
}// 디폴트값은 오늘쪽 매개변수부터 기술해야 함

int main() {
    //호출자가 실인수를 기술하지 않았으므로 함수의 디폴트 값을 적용
    std::cout << TestFunc() << std::endl;
    //호출자가 실인수를 확정했으므로 디폴트 값을 무시
    std::cout << TestFunc(30) << std::endl;

    return 0;
}

int TestFunc2(int nParam) {
    return nParam;
}
