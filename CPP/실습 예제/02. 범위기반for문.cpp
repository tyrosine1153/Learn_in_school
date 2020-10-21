#include<iostream>

int main() {
    int nList[5] = { 10,20,30,40,50 };

    for (int i = 0; i < 5; i++)
        std::cout << nList[i] << " ";//한 칸 띄고 출력한다는 뜻

    std::cout << std::endl;

    for (auto n : nList)// 범위기반. 각 요소의 값을 n에 복사한다. 배열열만큼 반복
        std::cout << n << " ";

    std::cout << std::endl;

    return 0;
}
