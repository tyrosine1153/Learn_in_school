# C++ 시험 문제



1. **Hello world 로 본 C++**

   ```c++
   // 예제 : Hello world
   #include <iostream>
   
   int main() {
   	std::cout << "Hello world! \n";
   
       return 0;
   }
   ```

   - `std` - 네임스페이스(Namespace)

   - `::` -범위 지정 연산자, 스코프 설정 연산자

   - `cout` - 콘솔 출력을 담당하는 객체

   - `<<` - 연산자 함수

   - => `std` 네임스페이스에 속한 `cout` 객체에 `"Hello world! \n"` 문자열을 넘겨`<<` 문자열을 화면에 출력하라

     

2. **자료형**

   - 일정 크기의 메모리에 저장된 정보를 해석하는 방법

   - 기본 자료형은 C와 다르지 않음

   - C++11 표준에서 추가된 것

     - `long long` : 64비트 정수

     - `char16_t` : 16비트 문자 //`char16_t ch = u'A';`로 표현

     - `char32_t` : 32 비트 문자  // 두 자료형은 유니코드 처리를 위해 만들어짐 일반 char 자료형은 8비트임

     - `auto` : 후술

     - `decltype(asdf)` : 괄호안에 asdf와 동일한 자료형으로 선언

       ```c++
       int x = 10;
       decltype(x) y = 20;  // y의 자료형은 int
       ```

   - 변수 선언과 정의

     ```c++
     int num = 10;  // c 스타일 선언과 정의
     int num2(10);  // c++ 스타일
     int num3(num2);  // 이런것도 가능하다
     ```

   

3. **auto 예약어**

   - 컴파일러가 자동으로 형식을 규정하는 자료형. 초기값의 형식에 맟춰 인스턴스의 형식이 자동으로 결정됨.

     ```c++
     auto data = 10;  // 형식은 int
     auto name = "Johnson";  // 형식은 const char*
     auto ch = 'A';  // 형식은 char
     ```

   

4. **메모리 동적할당**

   - `new` : 메모리 동적 할당 연산자

   - `delete` : 메모리 해제 연산자

     ```c++
     int* pData = new int;  // 인스턴스만 동적으로 생성
     int* pData2 = new int(10);  // 초기값을 적는 경우
     
     *pData = 5;
     
     std::cout << *pData << std::endl;  // 5 출력
     std::cout << *pData2 << std::endl;  // 10 출력
     
     delete pData;
     delete pData2;
     ```

     ```c++
     //객체를 배열 형태로 동적할당한다(Heap형태)
     int* arr = new int[5];
     
     for (int i = 0; i < 5; i++)
         arr[i] = (i + 1) * 100;
     
     for (int i = 0; i < 5; i++)
         std::cout << arr[i] << std::endl;
     
     //배열 형태로 생성한 대상은 배열형태를 통해 삭제한다.
     delete[] arr;
     ```

   

5. **참조자, 실습예제**

   - C에 없는 형식이며 포인터와 구조적으로 비슷함

   - 선언과 동시에 초기화 해야 함

       ```c++
       // 형식 &이름 = 원본;
       int data = 10;
       int& ref = data;  // data에 대한 참조자 선언
       ref = 20;  // 참조자의 값을 변경하면 원본이 변경된다.

       // 포인터를 쓰는 것과 비슷하다
       int data2 = 20;
       int* p = &data2;
       *p = 30;
       ```

   - 안되는 경우

       ```c++
       int* p = &3;
       int& r = 3;  // 포인터가 상수에 선언이 불가능 하듯이 상수에 대한 참조는 불가능
       int& ref;  // 참조원본이 없음(초기화 안함)
       ```

       ------

   - `L-value` 와 `R-value` : C++ 의 모든 표현식은 L-value 와 R-value로 구분 가능한데 **식의 표현이 지속성을 가질때** Lvalue 라고 하며, **범위(scope) 내에서 다시 사용이 가능한 값**이다. Rvalue는 **지속성을 가지지 않는 임시적인 값**을 의미하고(3+4 같은 임시로 생성되는 객체), 실제로 한번 사용된 이후로는 다시 참조가 불가능 하다.

   - Lvalue reference(참조자)는 변수에 별명을 붙이는 것이며 해당 값을 변경하면 원본도 함께 변경이 된다.  &연산자를 사용하며 주소 지정 연산자와는 다르다.

   - Rvalue reference는 임시로 생성되는 값들을 참조 가능하며, 불필요한 복사를 제거해 성능 향상에 도움을 준다. && 연산자를 사용한다

       ```c++
       int nVal = 10;
       
       // int& nLVal = 10;
       int& nLVal = nVal;
       // int&& nRVal = nVal;
       int&& nRVal = 10;
       
       /*주석처리 된 부분은 각각 에러를 발생 시킨다.
       L-value 참조자는 L-value만 참조할 수 있고 R-value는 R-value만 참조할 수 있다.*/
       ```

   

6. **범위기반 for문**

   - 반복 횟수가 배열 요소 개수에 맞춰 자동으로 결정

   ```c++
   //for (auto 요소변수 : 배열이름) { 반복구문; }
   int nList[5] = { 10,20,30,40,50 };
   
   for (int i = 0; i < 5; i++)
       std::cout << nList[i] << " ";
   
   for (auto n : nList)  // 범위기반. 각 요소의 값을 n에 복사한다. 배열만큼 반복
       std::cout << n << " ";
   
   ```

   

7. **디폴트 매개변수 사용시 기억둘것**

   - 피호출자 함수 매개변수의 디폴트 값은 반드시 오른쪽 매개변수부터 기술해야 함

   - 매개변수가 여러개일때 왼쪽 첫번째 매개변수의 디폴트 값을 기술하려면 나머지 오른쪽 모든 매개변수에 대한 디폴트 값을 기술해야 함

   - 호출자 함수가 피호출자 함수의 매개변수를 기술하면 이는 왼쪽부터 짝을 맞추어 적용되며, 짝이 맞지 않는 매개변수는 디폴트 값을 적용한다.

     

8. **함수 다중정의 문법 오류 여부**

   - 하나의 함수이름. 변수이름이 여러 의미를 동시에 갖는 것

   - 함수 원형의 구성을 살펴보면 크게 네가지(반환형식, 호출규칙, 함수이름, 매개변수) 중에서 다중정의에 영향을 주는 것은 '매개변수' 뿐이다. 

   - 함수 템플릿 : **같은 일을 하는 코드를 다양한 자료형으로 사용할 수 있도록 함수를 선언하는 것.**  코드 제작자는 함수의 편의성과 확장성을 위해 다중정의를 한다. 하지만 같은 일을 하는 코드가 다중 정의된 함수 여러 개로 존재할 경우 같은 일을 여러번 반복해야 한다. 그래서 만들었습니다.

     ```c++
     /*template <typename T>
     반환형식 함수이름 (매개변수) { 내용; }*/
     template <typename T>
     T TestFunc(T a) {
     	std::cout << "매개변수 a : " << a << std::endl;
     	return a;
     }
     ```

     

9. **네임스페이스와 식별자 검색순서**

   - C++의 각종 요소들(변수, 함수, 클래스 등)을 한 범주로 묶어주기 위한 문법
   - 범위지정 연산자 ::을 이용해 namespace를 기술할 수 있다. main()함수는 Global namespace에 속함. cout, TestFunc(), main()은 각자 속한 namespace가 모두 다르다.

   ```c++
   /*
   namespace 이름 {
   
   }
   */
   #include<iostream>
   namespace TEST {
       int g_nData = 100;
       void TestFunc() {
           std::cout << "TEST:: TestFunc()" << std::endl;
       }
   }
   
   int main() {
       TEST::TestFunc();
       std::cout << TEST::g_nData << std::endl;
       return 0;
   }
   ```

   - 프로그램 내부에서 앞으로 자주 사용해야 하는 namespace가 있다면 모든 식별자 앞에 이를 기술할 것이 아니라 using 예약어를 선언한 후 namespace를 생략 가능

   

10. **접근제어지시자**

    - `public` 멤버에 관한 모든 외부 접근이 허용됩니다. 
    - `protected` 멤버에 관한 모든 외부 접근이 차단됩니다. 단, 상속 관계에 있는 파생클래스에서의 접근은 허용됩니다.
    - `private `외부 접근 뿐만 아니라 파생 클래스로부터의 접근까지 모두 차단됩니다. 클래스를 선언할 때 별도로 접근 제어 지시자를 기술하지 않으면 private 로 간주합니다.

    

11. **생성자와 소멸자**

    - 클래스 객체가 생성 및 소면될때 자동으로 호출되는 함수

    - 특징 : 함수임에도 반환형식이 없고 함수 이름이 클래스 이름과 같다는 점.
    - 생성자는 다중정의 할 수 있으며 소멸자는 하나만 유일.
    - 생성자와 소멸자가 없는 클래스는 없다.
    - main 함수가 호출되기 전과 함수가 끝난 후에서 생성자와 소멸자가 호출될 수 있다.

    ```c++
    class CTest {
    public:
        CTest() {// 생성자
            cout << "CTest::CTest() " << endl;
        }
        ~CTest() {// 생성자
            cout << "CTest::~CTest()" << endl;
        }
    };
    ```

    

12. **동적 객체의 생성과 소멸(생성자 소멸자 언제 호출)**

    - 동적 객체는 new와 delete 연산자를 사용해 생성과 삭제를 해야 함

    - new와 delete 연산자는 각각 생성자와 소멸자를 호출함

    - 생성자와 소멸자 호출 시점 : 객체를 선언했을 때, 동적 생성, delete 했을 때

    - 객체 동적 선언 > 인스턴스 생성 > 생성자 호출

      

13. **참조형식 멤버 초기화**

    - 클래스의 멤버 변수는 참조형식으로 선언할 수 있음

    - 참조자는 반드시 선언과 동시에 초기화 해야 함(생성자 초기화 목록 사용)

    ```c++
    class CRefTest {
    private:
        int& m_nData;
    public:
        CRefTest(int& rParam) : m_nData(rParam) { // 반드시 생성자 초기화 목록을 이용해 초기화 한다.
        /* 생성자 매개변수를 참조형식(int &rParam)이 아니라 int rParam 이라고 작성하면
        함수의 매개변수는 함수 내부의 자동변수와 같으므로 함수가 반활될 때 매개변수는 소멸*/
            cout << "CRefTest::CRefTest(int &rParam)" << m_nData << endl;
        }
        ~CRefTest() {
            cout << "CRefTest::~CRefTest()" << m_nData << endl;
        }
        int GetData() { return m_nData; }
    };
    
    int main() {
        cout << "Begin" << endl;
    
        int a(10);
        CRefTest t(a); //참조자는 반드시 선언과 동시에 초기화 해야함
        cout << "GetData() : " << t.GetData() << endl;
    
        a = 20;  // 참조한변수의 값이 바뀌면 인스턴스의 멤버함수값 또한 바뀐다.
        cout << "GetData() : " << t.GetData() << endl;
    
        cout << "End" << endl;
        return 0;
    }
    ```

    

14. **메서드 종류와 특징**

    |  종류  | 관련 예약어 | this 포인터 접근 |  일반 멤버 읽기  |  일반 멤버 쓰기  | 정적 멤버 읽기 | 정적 멤버 쓰기 |          특징           |
    | :----: | :---------: | :--------------: | :--------------: | :--------------: | :------------: | :------------: | :---------------------: |
    |  일반  |      x      |       가능       |       가능       |       가능       |      가능      |      가능      |  가장 보편적인 메서드   |
    | 상수화 |    const    |       가능       |       가능       |    **불가능**    |      가능      |   **불가능**   |  멤버 쓰기 방지가 목적  |
    |  정적  |   static    |      불가능      | **가능(제한적)** | **가능(제한적)** |      가능      |      가능      |   C의 전역함수와 유사   |
    |  가상  |   virtual   |       가능       |       가능       |       가능       |      가능      |      가능      | 상속 관계에서 의미가 큼 |

    - 일반 : 가능
    - 상수화 : 쓰기만 불가능
    - 정적 : 일반 멤버가 제한적임
    - 가상 : 상속외에서는 일반과 거의 유사

    

15. **복사생성자(언제 호출되는지?)**

    - 객체의 복사본을 생성할 때 호출됨

    - 복사 생성자를 생략하면 디폴트처럼 알아서 만들어지는데 이때 복사는 얉은 복사이다.

    - 호출되는 경우

      1. 명시적으로 객체의 복사본을 생성하는 방식으로 선언하는 경우
      2. 함수 형태로 호출되는 경우

      ```c++
      CMyData a(10);  // 디폴트생성자
      CMyData b(a);  // 1.
      Testfunc(a);  // 2.
      => 이 경우 함수의 매개변수가 클래스 형식일 때
          void Testfunc(CMyData param);  // 복사생성자 생성(2) 참조자 형식을 사용해야 함
      ```

    

16. **깊은복사와 얕은복사**

    ```c++
    int *pA, *pB;
    
    pA = new int;
    *pA = 10;
    
    pB = new int;
    pB = pA;  // 얉은 복사.
    ```

    - pB는 동적할당을 했는데 할당한 메모리가 아니라 포인터로 pA의 메모리를 가리킴. 읽기에는 문제 없어 보이지만 쓰기와 삭제에 심각한 오류가 남.
    - 깊은 복사 하는 법 : `*pB = *pA;`, `*pB = 10;`

    - 클래스에 포인터 매개변수가 존재하지 않을 경우면 디폴트 복사생성자는 얕은 복사를 사용해도 상관 없지만, 클래스에 포인터 매개변수가 존재하는 경우면 얉은 복사는 심각한 오류를 일으킬 수 있음

      

17. **임시객체와 이동시맨틱**

    - 이름없는 임시객체 : 존재하는 인스턴스지만 식별자가 부여되지 않음. 변확생성자가 묵시적으로 호출되는 것을 explicit 예약어로 막으려는 이유. 함수의 반환 형식이 클래스일때 이름 없는 임시객체가 발생함

    - 이동 시맨틱은 이동 생성자와 이동 대입 연산자로 구현됨. 이름 없는 임시객체가 생성되더라도 부하가 최소화 될 수 있도록 구조를 변경하기 위함임. 복사 생성자와 대입 연산자에 rValue를 참조한것

      ```c++
      // 이동 생성자
      CTestData(CTestData	&&rhs) : m_nData(rhs.m_nData), m_pszName(rhs.m_pszName) {
      	cout << " CTestData(CTestData &&rhs) " << m_pszName << endl;
      }
      
      // 이동 대입 연산자 
      CTestData(const CTestData& rhs) : m_nData(rhs.m_nData), m_pszName(rhs.m_pszName) {
      	cout << " CTestData(const CTestData& rhs) " << m_pszName << endl;
      }
      
      // 대입 연산자
      CTestData& operator=(const CTestData& rhs) {
      	m_nData	= rhs.m_nData;
      	m_pszName = rhs.m_pszName;
      	cout << " operator=(const	CTestData& rhs) " << m_pszName << endl;
      	return *this;
      }
      ```

      

18. **r-value 참조(매개변수형식에 다른 실인수 예)**

    ![](C:\Users\jungm\AppData\Roaming\Typora\typora-user-images\image-20201223235806258.png)

    ```c++
    // 매개변수 형식
    TestFunc(int)
    // 실인수 예
    int x = 3;
    Testfunc(x);
    TestFunc(4);
    TestFunc(x + 5);
    TestFunc(5 + 6);
    
    // 매개변수 형식
    TestFunc(int&)
    // 실인수 예
    int	x = 3;
    TestFunc(x);
    
    // 매개변수 형식
    TestFunc(int&&)
    // 실인수 예
    int	x = 3;
    TestFunc(4);
    TestFunc(x + 5);
    TestFunc(5 + 6);
    //TestFunc(x)는	불가능!
    ```

    

19. **상속에서 생성자 소멸자(호출관계)**

    - A의 상속의 B의 상속의 C 가 있을 때, C클래스의 인스턴스를 선언하면 

    - **생성자와 소멸자의 호출 순서**는 C, B, A. 하지만 **생성자 실행 순서**는 A, B, C. 

    - 파생 클래스의 생성자는 자신이 호출된 후 기본 클래스의 생성자 중 어떤 것이 호출될지 선택할 수 있음

      ```c++
      class CTestEx : public CTest {
      public:
      	CTestEx() {	cout << "CTestEx()" << endl; }
      	CTestEx(int	nParam)	:CTest(nParam) { // CTest(nParam)이거
      		cout << "CTestEx(int)" << endl;
      	}
      	CTestEx(double	dParam)	:CTest(dParam) { // CTest(dParam)이거
      		cout << "CTestEx(double)" << endl;	
      	}
      };
      ```

    - 생성자 상속으로 생성자 선택도 할 필요가 없음

      ```c++
      class CTestEx : public CTest {
      public:
      	using CTest::CTest;
      };
      ```

      

