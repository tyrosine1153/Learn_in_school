#include<iostream>
using namespace std;

/* 객체의 복사본을 생성할때 호출되는 생성자. 클래스 작성 시 복사생성자를 생략하면 디폴트 생성자처럼 컴파일러가 알아서 만듬
클래스 내부에서 메모리를 동적할당 및 해제하고 멤버포인터변수로 관리하는 경우 복사생성자 적용하지 않으면 문제가 발생
복사생성자 형태 : 클래스이름(const 클래스이름 &rhs);
*/
class CMyData {
public:
    CMyData() { cout << "CMyData()" << endl; }

    CMyData(const CMyData& rhs) // : m_nData(rhs.m_nData)
    {
        this->m_nData = rhs.m_nData;
        cout << "CMyData(const CMyData &)" << endl;
    }
    int GetData()const { return m_Data; }
    void SetData(int nParam) { m_nData = nParam; }

private:
    int m_nData = 0;
};

int main() {
    CMyData a;  // 디폴트생성자
    a.SetData(10);

    CMyData b(a);  // 복사생성자
    cout << b.GetData() << endl;

    return 0;
}
/* 복사생성자가 호출되는 경우 1. 명시적으로 객체의 복사본을 생성하는 방식으로 선언하는 경우 2. 함수형태로 호출되는 경우
함수형태로 호출할때(매개변수, 반환형식에서) 클래스가 사용되는 경우
*/
