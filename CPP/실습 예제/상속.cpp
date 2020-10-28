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
/*부모가 있는 클래스를 사용했을때
호출 순서는 자식부터 맨위의 부모 클래스의 순서대로 되고
실행순서는 맨위의 부모 클래스부터 자식 순서대로 실행된다.  */
