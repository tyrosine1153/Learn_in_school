#include<iostream>

int TestFunc(int nParam = 10) {//nParam �Ű������� ����Ʈ ���� 10�̴�
    return nParam;
}

int TestFunc2(int nParam = 10);
//�Լ��� ���ǿ� ������ ������� ���� �κп� ����Ʈ ���� ����ؾ� ��

int TestFunc2(int nParam1, int nParam2 = 10) {
    return nParam * nParam;
}// ����Ʈ���� ������ �Ű��������� ����ؾ� ��

int main() {
    //ȣ���ڰ� ���μ��� ������� �ʾ����Ƿ� �Լ��� ����Ʈ ���� ����
    std::cout << TestFunc() << std::endl;
    //ȣ���ڰ� ���μ��� Ȯ�������Ƿ� ����Ʈ ���� ����
    std::cout << TestFunc(30) << std::endl;

    return 0;
}

int TestFunc2(int nParam) {
    return nParam;
}
