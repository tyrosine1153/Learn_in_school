#include<iostream>
using namespace std;

class CTest {
    int m_nData;
public:
    CTest() : m_nData(0) {  // 디폴트 생성자(매개변수가 없음) 초기화 목록 멤버변수 초기화
        cout << "CTest::CTest()" << endl;
    }
    CTest(int nParam) : m_nData(nParam) {
        cout << "CTest::CTest(int nParam)" << endl;
    }
    ~CTest() {
        cout << "CTest::~CTest() " << m_nData << endl;
    }
};
//생성자를 다중정의로 만들어서 디폴트 생성자 생략 가능. 이 경우 CTesT c; 꼴의 선언은 매개변수가 없으므로 불가능

int main() {
    cout << "Begin" << endl;
    CTest a;
    cout << "Before B" << endl;
    CTest b(20);
    cout << "End" << endl;

    return 0;
}
