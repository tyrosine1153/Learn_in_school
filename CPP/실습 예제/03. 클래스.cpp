#include <iostream>
using namespace std;

/*
class CLASSNAME{
접근제어지시자:
    멤버변수선언;
    멤버함수선언 및 정의;
};
*/
class USERDATA{
public: // 접근제어 지시자
    // 멤버 변수 선언
    int nAge;
    char szName[32];

    // 멤버 함수 선언 및 정의
    void Print(){
        // nAge와 szName은 Print()함수의 지역변수가 아님
        cout << nAge << " " << szName << endl;
    }
};

class CTest{
public:
    // 클래스의 생성자 함수 선언
    CTest(){
        // 인스턴스가 생성되면 멤버 데이터를 자동으로 초기화 한다
        cout << "CTest() : 생성자 함수" << endl;
        m_nData = 10;
    }

    int m_nData;

    // 멤버 함수 선언, 정의는 클래스 외부로 분리됨
    void PrintData();
};

// 클래스 외부에 분리된 멤버 함수 정의
void CTest::PrintData(){
    // 멤버 데이터에 접근하고 값을 출력한다
    cout << m_nData << endl;
}

class DEV{
public:
    DEV() : data1(10), data2(20) // 생성자 초기화 목록을 이용한 멤버 초기화
    {}
    int data1;
    int data2;
};

class TLQKF{
public:
    TLQKF() {}

    // C++부터 선언과 동시에 멤버 변수를 초기화 할 수 있다
    int tlqkf_data1 = 10;
    int tlqkf_data2 = 20;
};

// 사용자의 코드
int main(){
    USERDATA user = {20, "철수"}; // 기존 구조체 초기화 방법
    CTest t; // 객체 선언 및 인스턴스 생성되면 생성자 함수 호출
    DEV devv;
    TLQKF tlqkf;
    user.Print();
    t.PrintData();

    return 0;
}
