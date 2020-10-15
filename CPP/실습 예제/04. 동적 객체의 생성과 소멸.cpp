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
    CTest* pData = new CTest; // ��ü ���� ���� > �ν��Ͻ� ���� > ������ ȣ�� (����Ʈ ������)
    CTest a; // ��ü���� > �ν��Ͻ� ���� > ������ ȣ�� (����Ʈ ������)
    delete pData; // ��ü ����
    cout << "Before b" << endl;

    pData = new CTest(20); // �ν��Ͻ� ���� > ������ ȣ��
    CTest b(10); // ��ü ���� ���� > �ν��Ͻ� ���� > ������
    delete pData; // ��ü ����

    //�迭 ��������
    cout << "Array" << endl;
    pData = new CTest[3];
    delete[] pData; // �迭�� ������ ��ü�� �迭�� �����ؾ� ��

    cout << "pointer" << endl;
    CTest* pData2[10]; // ��ü������ �ƴ� ��ü ������ �迭
    for(int i=0;i<10;i++)
        pData2[i] = new CTest(3*i);
    for(int i=0;i<10;i++)
        delete pData2[i]; //�迭�� �������� ������ ��ü���� �����ؾ���

    cout << "pointer auto for" << endl;
    CTest* pData3[10];
    for (auto& n : pData3)
        n = new CTest(10); //���� ��ü ����
    for (auto& n : pData3)
        delete n;

    cout << "End" << endl;
    return 0;
}
/*
����
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
