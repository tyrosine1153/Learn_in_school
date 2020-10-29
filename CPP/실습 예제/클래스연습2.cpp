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
        cout << "��ü ������" << endl;
        for (i = 0; i < top; i++)
            cout << i + 1 << " : " << m_pszStr[i] << endl;
        cout << " [ " << i << " / " << strSize << " �� ]";
    }
};

int main() {
    CMyStrArr arr(10);

    arr.Insert("�����ϸ��ٰ��");
    arr.Insert("������123");
    arr.Insert("ȫ�浿abc");
    arr.Insert("Tasla Linux");

    arr.PrintData();
    return 0;
}
