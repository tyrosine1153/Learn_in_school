#include<iostream>

int main() {
	int nData = 10;

	int& ref = nData; //������
	ref = 20;
	std::cout << nData << std::endl;

	int* pnData = &nData; //������
	*pnData = 30;
	std::cout << nData << std::endl;

	std::cout << ref << std::endl; // ref�� ����Ű�� ��
	std::cout << pnData << std::endl; // �ּ�
	return 0;
}