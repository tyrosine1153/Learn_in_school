#include<iostream>
using namespace std;
// ����Ʈ �������� ���Ǹ� Ŭ���� �ܺη� �и�

class CTest{
public:
    CTest();
    /*
    -> CTest() = defalt; ���� ������� ����Ʈ �����ڸ� ��� �� ���� �� �� ����
    */
    int m_ndata = 5;
};
// Ŭ���� �ܺο��� ����Ʈ ������ ����
CTest::CTest(){}

int main(){
    CTest a;
    cout << a.m_ndata << endl;

    return 0;
}
