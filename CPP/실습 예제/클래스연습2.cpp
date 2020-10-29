#include<iostream>
using namespace std;

class CMyStrArr {
private:
    char** m_pszStr;
    int top;

public:
    int strSize;
    int i;

    CMyStrArr(int size) : top(0), strSize(size) {
        for (i = 0; i < size; i++)
            m_pszStr[i] = new char[20];
    }
    ~CMyStrArr(){
        for (i = 0; strSize; i++)
            delete[] m_pszStr[i];
        delete[] m_pszStr;
    }

    void Insert(const char* data) {
        m_pszStr[top++] = data;
    }

    void PrintData() {
        cout << "전체 데이터" << endl;
        for (i = 0; i < top; i++)
            cout << i + 1 << " : " << m_pszStr[i] << endl;
        cout << " [ " << i << " / " << strSize << " 개 ]";
    }
};

int main() {
    CMyStrArr arr(10);

    arr.Insert("월요일마다고고");
    arr.Insert("가나다123");
    arr.Insert("홍길동abc");
    arr.Insert("Tasla Linux");

    arr.PrintData();
    return 0;
}
