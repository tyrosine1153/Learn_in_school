#include<iostream>
// namepace : c++�� �����ϴ� ���� ��ҵ��� �� ���ַ� �����ֱ� ���� ����
// �ǹ̻� �Ҽ� ����

namespace TEST {
    int g_nData = 100;
    void TestFunc() {
        std::cout << "TEST:: TestFunc()" << std::endl;
    }
}

int main() {
    TEST::TestFunc();
    std::cout << TEST::g_nData << std::endl;

    return 0;
}
// namespace�� ������ ��� �ĺ��� �տ� �������� ������ ::�� �̿��� namespace�� ����� �� �ִ�
// main()�Լ��� Global namespace�� ����
//cout, TestFunc(), main()�� ���� ���� namespace�� ��� �ٸ�
