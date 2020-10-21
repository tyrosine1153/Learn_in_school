#include<iostream>
using namespace std;

/*메서드 (Method)의 사전적 의미는 방법. 메서드 : 클래스의 멤버 함수 -> 클래스가 제공하는 기능을 실행하는 방법
멤버함수의 원형 : static 반환자료형 클래스 이름::함수이름(매개변수) const;
static과 const 예약어는 생략할 수 있음.
static : 정적 멤버함수, const : 상수형 혹은 상수화된 멤버함수

this 포인터 : 제작자가 작성중인 클래스의 실제 인스턴스에 대한 주소를 가리키는 포인터
*/
class CMyData {
public:
    CMyData(int nParam) :m_nData(nParam) {}

    void PrintData() {
        cout << m_nData << endl; // m_nData 값을 출력
        cout << CMyData::m_nData << endl; // CMyData 클래스의 맴버인 m_nData 값

        cout << this->m_nData << endl; // 메서드를 호출한 인스턴스의 m_nData 값을 출력한다
        cout << this->CMyData::m_nData << endl; // 메서드를 호출한 인스턴스의 CMyData 클래스 멤버 m_nData의 값을 출력한다
    }
private:
    int m_nData;
};

int main() {
    CMyData a(5), b(10);
    a.PrintData();  // a.PrintData(&a);처럼 존재하며 매개변수로 저장된 인스턴스의 주소는 this라는 이름의 포인터 변수로 저장됨
    b.PrintData();

    return 0;
}
