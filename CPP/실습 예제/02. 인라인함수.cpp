#include<iostream>
#define ADD(a,b) ((a)+(b))

int Add(int a, int b) {
    return a + b;
}

inline int AddNew(int a, int b) {
    return a + b;
}

int main() {
    int a, b;
    std::cin >> a >> b;

    std::cout << "ADD() : " << ADD(a, b) << std::endl;  // ��ũ�� : �Լ��� �ƴ�, �Ű������� ���� ���� �Ұ�
    std::cout << "ADD() : " << Add(a, b) << std::endl;  // �Լ� : ȣ��� ���������� ���� ������� �������
    std::cout << "AddNew() : " << AddNew(a, b) << std::endl;

    return 0;
}
/*
�Է� :
10 15

��� :
ADD() : 25
ADD() : 25
AddNew() : 25

inline ���� ���� ���� �Լ��� �ٸ� �� ����. ���������� �Ϻ��� �Լ�, �����Ϸ� ����ȭ ��¼��.
*/
