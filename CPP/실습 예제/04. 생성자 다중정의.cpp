#include<iostream>
using namespace std;

class CTest {
    int m_nData;
public:
    CTest() : m_nData(0) {  // ����Ʈ ������(�Ű������� ����) �ʱ�ȭ ��� ������� �ʱ�ȭ
        cout << "CTest::CTest()" << endl;
    }
    CTest(int nParam) : m_nData(nParam) {
        cout << "CTest::CTest(int nParam)" << endl;
    }
    ~CTest() {
        cout << "CTest::~CTest() " << m_nData << endl;
    }
};
//�����ڸ� �������Ƿ� ���� ����Ʈ ������ ���� ����. �� ��� CTesT c; ���� ������ �Ű������� �����Ƿ� �Ұ���

int main() {
    cout << "Begin" << endl;
    CTest a;
    cout << "Before B" << endl;
    CTest b(20);
    cout << "End" << endl;

    return 0;
}
