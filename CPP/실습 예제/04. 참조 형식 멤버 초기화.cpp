#include<iostream>
using namespace std;

class CRefTest{
private:
    int& m_nData;
public:
    CRefTest(int &rParam) : m_nData(rParam){ // 반드시 생성자 초기화 목록을 이용해 초기화 한다.
    /* 생성자 매개변수를 참조형식(int &rParam)이 아니라 int rParam 이라고 작성하면
    함수의 매개변수는 함수 내부의 자동변수와 같으므로 함수가 반활될 때 매개변수는 소멸*/
        cout << "CRefTest::CRefTest(int &rParam)" << m_nData << endl;
    }
    ~CRefTest(){
        cout << "CRefTest::~CRefTest()" << m_nData << endl;
    }
    int GetData() {return m_nData;}
};

int main(){
    cout << "Begin" << endl;

    int a(10);
    CRefTest t(a); //참조자는 반드시 선언과 동시에 초기화 해야함
    cout << "GetData() : " << t.GetData() << endl;

    a = 20;
    cout << "GetData() : " << t.GetData() << endl;

    cout << "End" << endl;
    return 0;
}
