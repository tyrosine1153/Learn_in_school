#include <iostream>

int main() {
	std::cout << "Hello World!!\n";
	//cout : �ܼ� ����� ����ϴ� ��ü. << : ������, std : namespace��� �ϸ� �Ҽ��� ����, :: : ���� ���� ������, ������ ���� ������
	//std�� ���� cout��ü�� ���ڿ��� �Ѱ� ����ϵ��� ��
	std::string strname;
	std::cin >> strname;
	std::cout << strname;
	return 0;
}