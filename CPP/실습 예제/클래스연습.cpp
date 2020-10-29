#include<iostream>
using namespace std;

class CMyDataArr {
private:
    int* m_pnArr;
    int top;

public:
    int arrSize;
    CMyDataArr(int size) : top(0), arrSize(size) {
        m_pnArr = new int[size];
    }
    ~CMyDataArr(){
        delete[] m_pnArr;
    }

    void Insert(int data) {
        m_pnArr[top++] = data;
    }

    void PrintData() {
        int i = 0;
        cout << "��ü ������ : ";
        for (i = 0; m_pnArr[i]; i++) {
            cout << m_pnArr[i] << " ";
        }
        cout << " [ " << i << " / " << arrSize << " �� ]";
    }
};

int main() {
    CMyDataArr arr(20);

    arr.Insert(10);
    arr.Insert(20);
    arr.Insert(96);
    arr.Insert(-45);

    arr.PrintData();

    return 0;
}
