#include<iostream>
using namespace std;

class CRefTest{
private:
    int& m_nData;
public:
    CRefTest(int &rParam) : m_nData(rParam){ // �ݵ�� ������ �ʱ�ȭ ����� �̿��� �ʱ�ȭ �Ѵ�.
    /* ������ �Ű������� ��������(int &rParam)�� �ƴ϶� int rParam �̶�� �ۼ��ϸ�
    �Լ��� �Ű������� �Լ� ������ �ڵ������� �����Ƿ� �Լ��� ��Ȱ�� �� �Ű������� �Ҹ�*/
        cout << "CRefTest::CRefTest(int &rParam)" << m_nData << endl;
    }
    ~CRefTest(){
        cout << "CRefTest::~CRefTest()" << m_nData << endl;
    }
    int GetData() {return m_nData;}
};

int main(){
    cout << "Begin" << endl;

    int a(10);
    CRefTest t(a); //�����ڴ� �ݵ�� ����� ���ÿ� �ʱ�ȭ �ؾ���
    cout << "GetData() : " << t.GetData() << endl;

    a = 20;
    cout << "GetData() : " << t.GetData() << endl;

    cout << "End" << endl;
    return 0;
}
