
#include <iostream>

using namespace std;

class test
{
private:
    static int value;
public:
    test() = default;
    virtual ~test() = default;

    static void statFunc();
};

int test::value =0;

void test::statFunc()
{
    cout << "test::statFunc() value:" << value << endl;
}


class test2 : public test
{
private:
    static int value2;
public:
    test2() = default;
    ~test2() = default;

    static void statFunc();
};

int test2::value2 =0;

void test2::statFunc()
{
    test::statFunc();

    cout << "test2::statFunc2() value2:" << value2 << endl;
}


int main() 
{
    // 1 
    cout << "1=======" << endl;
    test *testVar = new test();

    testVar->statFunc();

    delete testVar;

    // 2
    cout << "2=======" << endl;
    test2 *testVar2 = new test2();

    testVar2->statFunc();

    // 3
    cout << "3=======" << endl;
    testVar2->test::statFunc();
    testVar2->test2::statFunc();

    delete testVar2;


   
    return 0;
}