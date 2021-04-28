#include <iostream>
#include <string>


/*

Перепишите на using следующий typedef.

typedef int * (Class::*Foo)(int, double) const;

*/
int var;

class Class
{
public:
    int * someMethod(int a, double b) const {
        std::cout << "Hello" << std::endl;
        return &var;
    }   
};

typedef int * (Class::*Foo)(int, double) const;
using Foo2 = int * (Class::*)(int, double) const;

void somefunc(Foo func1)
{

}

int main(int argc, const char * argv[]) 
{
    Class obj;

    Foo2 xc = &Class::someMethod;

    (obj.*xc)(2, 2.0);

    somefunc(&Class::someMethod);


    return 0;
}