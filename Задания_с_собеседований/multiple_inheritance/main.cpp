/*
* наследование
*/

#include <iostream>

using namespace std;

class Base{
    virtual void method() {cout << "from Base" << endl;}

public:
    virtual ~Base(){method();}
    void baseMethod() {method();}
};

class A: public Base{
    void method() {cout << "from A" << endl;}

public:
    ~A(){method();}
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