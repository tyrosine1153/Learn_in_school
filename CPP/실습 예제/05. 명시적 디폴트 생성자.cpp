#include<iostream>
using namespace std;
// 디폴트 생성자의 정의를 클래스 외부로 분리

class CTest{
public:
    CTest();
    /*
    -> CTest() = defalt; 같은 방식으로 디폴트 생성자를 언언 및 정의 할 수 있음
    */
    int m_ndata = 5;
};
// 클래스 외부에서 디폴트 생성자 정의
CTest::CTest(){}

int main(){
    CTest a;
    cout << a.m_ndata << endl;

    return 0;
}
