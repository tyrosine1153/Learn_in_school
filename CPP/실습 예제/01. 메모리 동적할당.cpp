#include<iostream>

int main() {
	int num = 10;
	int num2(10);
	int num3(num2);

	//new : �޸� ���� �Ҵ� ������
	//delete : �޸� ���� ������
	int* pData = new int;
	int* pData2 = new int(10);
	
	*pData = 5;
	std::cout << *pData << std::endl;
	std::cout << *pData2 << std::endl;

	delete pData;
	delete pData2;
	return 0;
}