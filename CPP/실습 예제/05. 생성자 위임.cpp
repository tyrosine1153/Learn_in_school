#include<iostream>
using namespace std;

class CMyPoint{
public:
    CMyPoint(int x){
        cout << "CMyPoint(int x)" <<endl;
        // x값이 100이 넘는지 검사하고 넘으면 100으로 맞춘다
        if (x > 100)
            x = 100;

        m_x = x;
    }
    CMyPoint(int x, int y) : CMyPoint(x){ // x 값을 검사해 대입하는 코드는 이미 존제하므로 재사용한다.
        // CMyPoint(int x, int y) 생성자는 초기화 목록에서 CMyPoint(int) 생성자가 추가로 호출될 수 있도록 위임
        cout << "CMyPoint(int, int)" << endl;
        if (y > 200)
            y = 200;

        m_y = y;
    }
    void Print(){
        cout << "X: " << m_x << endl;
        cout << "Y: " << m_y << endl;
    }
private:
    int m_x = 0;
    int m_y = 0;
};

int main(){
    // 매개변수가 하나인 생성자만 호출
    CMyPoint ptBegin(110);
    ptBegin.Print();

    // 두 생성자 모두 호출
    CMyPoint ptEnd(50, 250);
    ptEnd.Print();

    return 0;
}
