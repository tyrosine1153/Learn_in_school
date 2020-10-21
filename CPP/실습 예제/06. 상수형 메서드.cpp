#include<iostream>
using namespace std;
/*상수형 메서드 : 멤버 변수에 읽기 접근은 가능하지만 쓰기는 허용하지 않는 메서드
함수 원형 뒤에 형한정어 const를 붙임
상수형 메서드의 내부 원리: this 포인터를 상수형 포인터로 변경
*/
class CTest {
public:
    CTest(int nParam) : m_nData(nParam) {}
    ~CTest() {}

    int GetData() const {
        // m_nData = 20; 대입연산자 사용불가능
        // SetData(20); 멤버함수도 호출이 불가하다.
        m_nData2 = 20; //하지만 mutable 멤버변수에는 값을 쓸 수 있다.
        return m_nData;  // 멤버 변수의 값을 읽을 수는 있지만 쓸 수는 없다.
    }
    int SetData(int nParam) { m_nData = nParam; }

private:
    int m_nData = 0;
    mutable int m_nData2 = 0;
};

int main() {
    CTest a(10);
    cout << a.GetData() << endl;
    return 0;
}
