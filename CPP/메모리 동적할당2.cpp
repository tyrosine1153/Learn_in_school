#include<iostream>

int main() {
	//��ü�� �迭 ���·� �����Ҵ��Ѵ�(Heap����)
	int* arr = new int[5];

	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 100;

	for (int i = 0; i < 5; i++)
		std::cout << arr[i] << std::endl;
	
	//�迭 ���·� ������ ����� �迭���¸� ���� �����Ѵ�.
	delete[] arr;
	return 0;

	//�� �˾ƺ� �� : Heap �ڷᱸ��, std::endl, +�����Ҵ�
}