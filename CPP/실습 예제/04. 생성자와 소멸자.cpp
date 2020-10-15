#include<iostream>
using namespace std;

/*생성자와 소멸자
- 생성자 소멸자는 클래스 객체가 생성 및 소멸될 때 자동으로 호출되는 함수이다.
- 둘의 가장 큰 특징은 함수임에도 반환 형식이 없다는 것과 함수 이름이 클래스 이름과 같다는 것.
- 소면자의 이름 앞에는 ~을 붙인다.
- 생성자는 다중 정의할 수 있고, 소멸자는 유일하다.
- 디폴트 생성자 : 매개변수가 하나도 없는 생성자.
- 클래스 제작자가 디퐅트 생성자와 소멸자를 기술하지 않아도 컴파일러가 알아서 넣는다.
*/

class CTest {
public:
    CTest() {// 생성자
        cout << "CTest::CTest() " << endl;
    }
    ~CTest() {// 생성자
        cout << "CTest::~CTest()" << endl;
    }
};

//인스턴스를 전역변수로 선언. 생선자가 main()함수보다 먼저 호출됨
CTest global;
int main() {
    cout << "Begin " << endl;
    // 인스턴스를 지역변수로 선언. 선언된 시점이 객체가 생성되는 시점. 지역변수 특성상 선언된 블록(main() 함수도 포함) 범위가 끝나면 자동으로 소멸
    CTest localA;
    cout << "Before B" << endl;
    CTest localB;
    cout << "End " << endl;

    return 0;
}
/*생성자는 다중 정의할 수 있으며 소멸자는 다중 정의 할 수 없다.
생성자와 소멸자는 생략할 수 있으나 생략할 경우 컴파일러가 만들어 넣는다.*/
