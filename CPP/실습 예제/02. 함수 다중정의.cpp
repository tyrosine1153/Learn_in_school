#include<iostream>

/*��������: �Ѱ��� �Լ��� �����̸��� ���� �ǹ̸� ���ÿ� ���� ��
�Ű������� �����̳� �Լ������� �޶����� �̸��� ������ ���еȴ�.
c++�� �Լ��� �������� �����Ѵ�
�������ǿ� ������ �ִ� ��-> �Ű����� ���̴�*/

int Add(int a, int b, int c) {
    std::cout << "Add(int, int, int):";
    return a + b + c;
}
int Add(int a, int b) {
    std::cout << "Add(int, int):";
    return a + b;
}
int Add(double a, double b) {
    std::cout << "Add(double, double):";
    return a + b;
}

int main() {
    std::cout << Add(3, 4) << std::endl;
    std::cout << Add(3, 4, 5) << std::endl;
    std::cout << Add(3.3, 4.4) << std::endl;
}
