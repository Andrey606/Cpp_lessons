/*
* наследование
*/

#include <iostream>

using namespace std;

class Base{
    virtual void method() {cout << "from Base" << endl;}

public:
    Base(){cout << "from Base()" << endl; method();}
    virtual ~Base(){method();cout << "from ~Base()" << endl;}
    void baseMethod() {method();}
};

class A: public Base{
    void method() {cout << "from A" << endl;}

public:
    A(){cout << "from A()" << endl;}
    ~A(){method();cout << "from ~A()" << endl;}
};


int main() 
{
    Base* base = new A;

    cout << "1" << endl;
    base->baseMethod();

    cout << "2" << endl;
    delete base;
   
    return 0;
}