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
/*����ȯ ������ :const_cast
const_cast<������>(���);
*/
