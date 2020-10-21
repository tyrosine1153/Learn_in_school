#include<iostream>
using namespace std;

void TestFunc(const int& nParam) {
    int& nNewParam = const_cast<int&>(nParam);

    nNewParam = 20;
}

int main() {
    int nData = 10;
    TestFunc(nData);

    cout << nData << endl;
}
/*형변환 연산자 :const_cast
const_cast<새형식>(대상);
*/
