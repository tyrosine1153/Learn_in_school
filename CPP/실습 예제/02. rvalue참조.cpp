#include<iostream>

int TestFunc(int nParam) {
	return nParam;
}

int main() {
	int nInput = 0;
	std::cout << "Input number : ";
	std::cin >> nInput;

	/* r-value ����, c++11 ����. �ڷ���&& �̸� = ����;
	r-value - ���� �������� �� �ǿ����� �� �����ʿ� ��ġ�� ��
	�Ϲ����� ������ ��� ��� �ش�. ���꿡 ���� ������ �ӽð�ü*/
	int&& rData = nInput + 5;
	std::cout << rData << std::endl;
	std::cout << nInput << std::endl;

	int&& result = TestFunc(10);

	result += 10;
	std::cout << result << std::endl;

	return 0;
}
