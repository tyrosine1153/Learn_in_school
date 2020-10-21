#include<iostream>
using namespace std;

/*�޼��� (Method)�� ������ �ǹ̴� ���. �޼��� : Ŭ������ ��� �Լ� -> Ŭ������ �����ϴ� ����� �����ϴ� ���
����Լ��� ���� : static ��ȯ�ڷ��� Ŭ���� �̸�::�Լ��̸�(�Ű�����) const;
static�� const ������ ������ �� ����.
static : ���� ����Լ�, const : ����� Ȥ�� ���ȭ�� ����Լ�

this ������ : �����ڰ� �ۼ����� Ŭ������ ���� �ν��Ͻ��� ���� �ּҸ� ����Ű�� ������
*/
class CMyData {
public:
    CMyData(int nParam) :m_nData(nParam) {}

    void PrintData() {
        cout << m_nData << endl; // m_nData ���� ���
        cout << CMyData::m_nData << endl; // CMyData Ŭ������ �ɹ��� m_nData ��

        cout << this->m_nData << endl; // �޼��带 ȣ���� �ν��Ͻ��� m_nData ���� ����Ѵ�
        cout << this->CMyData::m_nData << endl; // �޼��带 ȣ���� �ν��Ͻ��� CMyData Ŭ���� ��� m_nData�� ���� ����Ѵ�
    }
private:
    int m_nData;
};

int main() {
    CMyData a(5), b(10);
    a.PrintData();  // a.PrintData(&a);ó�� �����ϸ� �Ű������� ����� �ν��Ͻ��� �ּҴ� this��� �̸��� ������ ������ �����
    b.PrintData();

    return 0;
}
