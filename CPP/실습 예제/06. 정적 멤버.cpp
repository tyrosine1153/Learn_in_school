#include<iostream>
using namespace std;

class CTest {
public:
    CTest(int nParam) : m_nData(nParam) { m_nCount; }
    ~CTest() {}

    int GetData() const { return m_nData; }
    void ResetCount() { m_nCount = 0; }

    static int GetCount() {
        return m_nCount;
    }
private:
    int m_nData = 0;
    static int m_nCount;
};

int CTest::m_nCount = 0; //CTest 클래스의 정적 멤버 변수 정의

int main() {
    CTest a(10), b(5);
    cout << a.GetCount << endl;  //범위 지정 연산자가 없어도 접근가능
    b.ResetCount();
    cout << CTest::GetCount() << endl;  //인스턴스 없이도 접근가능

    return 0;
}
