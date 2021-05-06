#include <iostream>

using namespace std;

// это принимает только lvalue
void foo(int & t)
{
    t = 1;
}

// это принимает только rvalue
void foo(int && t)
{
    t = 1;
}

// это шаблон и он принимает и rvalue и lvalue и тут происходят склейки
template<typename T>
void foo2(T && value) 
{
    // value внутри этой функции всегда является lvalue
    value = 1;
}

// !! помните, что в теле функции формальный параметр является lvalue вне зависимости от того, как он был передан в функцию.


int main(int argc, const char * argv[]) 
{
    // lvalue
    int var = 10;
    foo(var);
    std::cout << "var: " << var << std::endl;

    // rvalue
    foo(int(10));

    // шаблон от lvalue
    int var2 = 10;
    foo2(var2); // тут мы передаем var по ccылке и T = T& -> T& + && = T&
    std::cout << "var2: " << var2 << std::endl;

    // шаблон от rvalue
    foo2(10); // тут мы передаем rvalue и T = T -> T + && = T&&

    return 0;
}