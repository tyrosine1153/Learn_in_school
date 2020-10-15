#include <iostream>
using namespace std;

class CTest{
    int m_nData;
public:
    CTest(): m_nData(0){
        cout << "CTest::Ctest()" << endl;
    }
    CTest(int nParam):m_nData(nParam){
        cout << "CTest::CTest(int nParam)" << endl;
    }
    ~CTest(){
        cout << "CTest::~CTest()" << m_nData << endl;
    }
};

int main(){
    cout << "Begin" <<endl;
    CTest* pData = new CTest; // 객체 동적 선언 > 인스턴스 생성 > 생성자 호출 (디폴트 생성자)
    CTest a; // 객체선언 > 인스턴스 생성 > 생성자 호출 (디폴트 생성자)
    delete pData; // 객체 삭제
    cout << "Before b" << endl;

    pData = new CTest(20); // 인스턴스 생성 > 생성자 호출
    CTest b(10); // 객체 동적 선언 > 인스턴스 생성 > 생성자
    delete pData; // 객체 삭제

    //배열 동적생성
    cout << "Array" << endl;
    pData = new CTest[3];
    delete[] pData; // 배열로 생성한 객체는 배열로 삭제해야 함

    cout << "pointer" << endl;
    CTest* pData2[10]; // 객체생성이 아님 객체 포인터 배열
    for(int i=0;i<10;i++)
        pData2[i] = new CTest(3*i);
    for(int i=0;i<10;i++)
        delete pData2[i]; //배열에 동적으로 생성된 객체들을 삭제해야함

    cout << "pointer auto for" << endl;
    CTest* pData3[10];
    for (auto& n : pData3)
        n = new CTest(10); //동적 객체 생성
    for (auto& n : pData3)
        delete n;

    cout << "End" << endl;
    return 0;
}
/*
형태
CTest *pData = new CTest(n);
delete pData;

CTest *pData = new CTest[n]{10,20,30};
delete[] pData;

CTest *pData[10];
for(int i=0;i<10;i++)
    pData[i] = new CTest(3*i);
for(int i=0;i<10;i++)
    delete pData[i];
*/
