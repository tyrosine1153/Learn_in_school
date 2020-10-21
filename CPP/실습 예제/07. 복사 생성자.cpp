#include<iostream>
using namespace std;

class CMyData {
public:
    CMyData() { cout << "CMyData()" << endl; }

    CMyData(const CMyData& rhs) // : m_nData(rhs.m_nData)
    {
        this->m_nData = rhs.m_nData;
        cout << "CMyData(const CMyData &)" << endl;
    }
    int GetData()const { return m_Data; }
    void SetData(int nParam) { m_nData = nParam; }

private:
    int m_nData = 0;
};

int main() {
    CMyData a;
    a.SetData(10);

    CMyData b(a);
    cout << b.GetData() << endl;

    return 0;
}
