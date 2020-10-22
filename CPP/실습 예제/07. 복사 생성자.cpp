#include<iostream>
using namespace std;

/* ��ü�� ���纻�� �����Ҷ� ȣ��Ǵ� ������. Ŭ���� �ۼ� �� ��������ڸ� �����ϸ� ����Ʈ ������ó�� �����Ϸ��� �˾Ƽ� ����
Ŭ���� ���ο��� �޸𸮸� �����Ҵ� �� �����ϰ� ��������ͺ����� �����ϴ� ��� ��������� �������� ������ ������ �߻�
��������� ���� : Ŭ�����̸�(const Ŭ�����̸� &rhs);
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
    CMyData a;  // ����Ʈ������
    a.SetData(10);

    CMyData b(a);  // ���������
    cout << b.GetData() << endl;

    return 0;
}
/* ��������ڰ� ȣ��Ǵ� ��� 1. ��������� ��ü�� ���纻�� �����ϴ� ������� �����ϴ� ��� 2. �Լ����·� ȣ��Ǵ� ���
�Լ����·� ȣ���Ҷ�(�Ű�����, ��ȯ���Ŀ���) Ŭ������ ���Ǵ� ���
*/
