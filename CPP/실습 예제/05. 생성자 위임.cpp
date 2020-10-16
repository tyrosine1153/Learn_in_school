#include<iostream>
using namespace std;

class CMyPoint{
public:
    CMyPoint(int x){
        cout << "CMyPoint(int x)" <<endl;
        // x���� 100�� �Ѵ��� �˻��ϰ� ������ 100���� �����
        if (x > 100)
            x = 100;

        m_x = x;
    }
    CMyPoint(int x, int y) : CMyPoint(x){ // x ���� �˻��� �����ϴ� �ڵ�� �̹� �����ϹǷ� �����Ѵ�.
        // CMyPoint(int x, int y) �����ڴ� �ʱ�ȭ ��Ͽ��� CMyPoint(int) �����ڰ� �߰��� ȣ��� �� �ֵ��� ����
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
    // �Ű������� �ϳ��� �����ڸ� ȣ��
    CMyPoint ptBegin(110);
    ptBegin.Print();

    // �� ������ ��� ȣ��
    CMyPoint ptEnd(50, 250);
    ptEnd.Print();

    return 0;
}
