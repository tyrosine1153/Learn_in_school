#include <iostream>
using namespace std;

/*
class CLASSNAME{
��������������:
    �����������;
    ����Լ����� �� ����;
};
*/
class USERDATA{
public: // �������� ������
    // ��� ���� ����
    int nAge;
    char szName[32];

    // ��� �Լ� ���� �� ����
    void Print(){
        // nAge�� szName�� Print()�Լ��� ���������� �ƴ�
        cout << nAge << " " << szName << endl;
    }
};

class CTest{
public:
    // Ŭ������ ������ �Լ� ����
    CTest(){
        // �ν��Ͻ��� �����Ǹ� ��� �����͸� �ڵ����� �ʱ�ȭ �Ѵ�
        cout << "CTest() : ������ �Լ�" << endl;
        m_nData = 10;
    }

    int m_nData;

    // ��� �Լ� ����, ���Ǵ� Ŭ���� �ܺη� �и���
    void PrintData();
};

// Ŭ���� �ܺο� �и��� ��� �Լ� ����
void CTest::PrintData(){
    // ��� �����Ϳ� �����ϰ� ���� ����Ѵ�
    cout << m_nData << endl;
}

class DEV{
public:
    DEV() : data1(10), data2(20) // ������ �ʱ�ȭ ����� �̿��� ��� �ʱ�ȭ
    {}
    int data1;
    int data2;
};

class TLQKF{
public:
    TLQKF() {}

    // C++���� ����� ���ÿ� ��� ������ �ʱ�ȭ �� �� �ִ�
    int tlqkf_data1 = 10;
    int tlqkf_data2 = 20;
};

// ������� �ڵ�
int main(){
    USERDATA user = {20, "ö��"}; // ���� ����ü �ʱ�ȭ ���
    CTest t; // ��ü ���� �� �ν��Ͻ� �����Ǹ� ������ �Լ� ȣ��
    DEV devv;
    TLQKF tlqkf;
    user.Print();
    t.PrintData();

    return 0;
}
