#include<iostream>
// using 선언 : 자주 사용하는 namespace를 모든 식별자 앞에 기술하지 않도록 using예약어로 생략하는 것
using namespace std; //std 네임스페이스를 생략한다

// 네임스페이스 안에 또 다른 네임스페이스가 속할 수 있음
namespace FIRST{
    int g_nData = 100;
    namespace SECOND{
        int g_nData = 200;
        namespace THIRD{
            int g_nData = 300;
        }  // int g_nData 변수는 이름은 같아도 전혀 다른 세 개의 전역 변수
    }
}

// namespace와 다중 정의
void TestFunc(){  // 전역함수(개념상 무소속)
     cout << "::TestFunc()" << endl;
}
namespace TEST{
    void TestFunc(){  // TEST 소속
        cout << "TEST:: TestFunc()" << endl;
    }
}
namespace MYDATA{
    void TestFunc(){  // MYDATA 소속
        cout << "MYDATA:: TestFunc()" << endl;
    }
}
// TestFunc 함수는 세번 정의되는데 각각 속한 namespace가 다름
// TEST,MYDATA에 using 선언을 하면 에러가 걸린다
// error: call of overloaded 'TestFunc()' is ambiguous|

int main(){
    cout << FIRST::g_nData << endl;  // 접근할 때는 정확히 namespace를 명시해야 함
    cout << FIRST::SECOND::g_nData << endl;
    cout << FIRST::SECOND::THIRD::g_nData << endl;

    TestFunc();  // 묵시적 전역
    ::TestFunc();  // 명시적 전역
    TEST::TestFunc();
    MYDATA::TestFunc();

    return 0;
}
