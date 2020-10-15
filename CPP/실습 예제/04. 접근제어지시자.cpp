#include <iostream>
using namespace std;

/* 접근 제어 지시자
public: 멤버에 관한 모든 외부 접근이 허용됩니다
protected: 멤버에 관한 모든 외부 접근이 파단됩니다. 단, 상속관계에 잉ㅆ는 파생 클래스에서의 접근은 허용됩니다.
private: 외부 접근 뿐만 아니라 파생 클래스로부터의 접근까지 모두 차단됩니다.
        클래스를 선언할 때 별도로 접근 제어 지시자를 기술하지 않으면 private 로 간주합니다
*/

class CMyData {
    // 기본 접근제어 지시자는 'private임'
    int m_Ddata;

public:
    int GetData() { return m_nData; }
    void SetData(int nParam) { m_Ddata = mParam; }
    // 다음 메서드를 이용해 m_ndata에 접근할 수 있도록 허용. 사용자가 m_nData의 값을 얻거나 쓸 수 있는 유일한 통로
    // 멤버 함수의 경우 private 멤버에 접근하는 것이 자유롭다. -> 접근제어 지시자의 영행을 받지 못한다
    // 생성자도 접근제어 지시자의 영향을 받는다. ->생성자 함수를 private로 선언하면 main에서 객체 선언만으로도 컴파일 오류 발생
};

int main() {
    CMyData data;
    //data.m_ndata = 10; // 허용되지 않음
    data.SetData(10);
    cout << data.GetData() << endl;

    return 0;
}
/*사용자가 임의 접근을 차단해서 제작자가 얻는 이득 : 사용자가 임의로 멤버 변수의 값을 변화시키는 것을 통제할 수 있다*/
