#include<iostream>
using namespace std;
/*����� �޼��� : ��� ������ �б� ������ ���������� ����� ������� �ʴ� �޼���
�Լ� ���� �ڿ� �������� const�� ����
����� �޼����� ���� ����: this �����͸� ����� �����ͷ� ����
*/
class CTest {
public:
    CTest(int nParam) : m_nData(nParam) {}
    ~CTest() {}

    int GetData() const {
        // m_nData = 20; ���Կ����� ���Ұ���
        // SetData(20); ����Լ��� ȣ���� �Ұ��ϴ�.
        m_nData2 = 20; //������ mutable ����������� ���� �� �� �ִ�.
        return m_nData;  // ��� ������ ���� ���� ���� ������ �� ���� ����.
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
