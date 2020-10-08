#include<iostream>
// using ���� : ���� ����ϴ� namespace�� ��� �ĺ��� �տ� ������� �ʵ��� using������ �����ϴ� ��
using namespace std; //std ���ӽ����̽��� �����Ѵ�

// ���ӽ����̽� �ȿ� �� �ٸ� ���ӽ����̽��� ���� �� ����
namespace FIRST{
    int g_nData = 100;
    namespace SECOND{
        int g_nData = 200;
        namespace THIRD{
            int g_nData = 300;
        }  // int g_nData ������ �̸��� ���Ƶ� ���� �ٸ� �� ���� ���� ����
    }
}

// namespace�� ���� ����
void TestFunc(){  // �����Լ�(����� ���Ҽ�)
     cout << "::TestFunc()" << endl;
}
namespace TEST{
    void TestFunc(){  // TEST �Ҽ�
        cout << "TEST:: TestFunc()" << endl;
    }
}
namespace MYDATA{
    void TestFunc(){  // MYDATA �Ҽ�
        cout << "MYDATA:: TestFunc()" << endl;
    }
}
// TestFunc �Լ��� ���� ���ǵǴµ� ���� ���� namespace�� �ٸ�
// TEST,MYDATA�� using ������ �ϸ� ������ �ɸ���
// error: call of overloaded 'TestFunc()' is ambiguous|

int main(){
    cout << FIRST::g_nData << endl;  // ������ ���� ��Ȯ�� namespace�� ����ؾ� ��
    cout << FIRST::SECOND::g_nData << endl;
    cout << FIRST::SECOND::THIRD::g_nData << endl;

    TestFunc();  // ������ ����
    ::TestFunc();  // ����� ����
    TEST::TestFunc();
    MYDATA::TestFunc();

    return 0;
}
