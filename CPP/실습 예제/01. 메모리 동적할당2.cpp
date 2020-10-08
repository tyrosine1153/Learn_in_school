#include<iostream>

int main() {
	//객체를 배열 형태로 동적할당한다(Heap형태)
	int* arr = new int[5];

	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 100;

	for (int i = 0; i < 5; i++)
		std::cout << arr[i] << std::endl;
	
	//배열 형태로 생성한 대상은 배열형태를 통해 삭제한다.
	delete[] arr;
	return 0;

	//더 알아볼 것 : Heap 자료구조, std::endl, +동적할당
}