#include<iostream>

int main() {
    int nList[5] = { 10,20,30,40,50 };

    for (int i = 0; i < 5; i++)
        std::cout << nList[i] << " ";//�� ĭ ��� ����Ѵٴ� ��

    std::cout << std::endl;

    for (auto n : nList)// �������. �� ����� ���� n�� �����Ѵ�. �迭����ŭ �ݺ�
        std::cout << n << " ";

    std::cout << std::endl;

    return 0;
}
