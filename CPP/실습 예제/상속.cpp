#include<iostream>
using namespace std;

class CMyData{
public:
    CMyData() : m_nx(0){
        cout << "CMyData()" << endl;
    }
    CMyData(int nX) : m_nx(nX){}

    int GetData(){return m_nx;}
    void SetData(int nX){m_nx=nX;}
private:
    int m_nx;
};

class CMyDataEx : public CMyData{
public:
    CMyDataEx(){
        cout << "CMyDataEx()" << endl;
        m_ny = 0;
    }
    CMyDataEx(int nx, int ny){
        SetData(nx,ny);
    }
    void SetData(int nx, int ny){
        CMyData::SetData(nx);
        m_ny = ny;
    }
    int GetX(){return CMyData::GetData();}
    int GetY(){return m_ny;}
private:
    int m_ny;
};

int main(){
    CMyDataEx data;
    data.SetData(30,40);
    cout << data.GetX() << endl;
    cout << data.GetY() << endl;
    return 0;
}
/*�θ� �ִ� Ŭ������ ���������
ȣ�� ������ �ڽĺ��� ������ �θ� Ŭ������ ������� �ǰ�
��������� ������ �θ� Ŭ�������� �ڽ� ������� ����ȴ�.  */
