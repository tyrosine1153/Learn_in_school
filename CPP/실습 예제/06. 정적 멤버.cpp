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

int CTest::m_nCount = 0; //CTest Ŭ������ ���� ��� ���� ����

int main() {
    CTest a(10), b(5);
    cout << a.GetCount << endl;  //���� ���� �����ڰ� ��� ���ٰ���
    b.ResetCount();
    cout << CTest::GetCount() << endl;  //�ν��Ͻ� ���̵� ���ٰ���

    return 0;
}
