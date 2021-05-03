#include <iostream>
#include <string>
#include <typeinfo>

class Base
{
public:
    Base(const  Base&) = delete; // в новом стандарте можно удалять конструктор копирование
    Base() = default;
    Base(int a, float b): _a(a), _b(b){}

    virtual void someMethod() final; //  final запрещает переопределять этот метод в производных классах
private:
    int _a = 5; // в новом стандарте можно инициализировать переменные по дефолту тут
    float _b = 6.6;
};

void Base::someMethod()
{

}

class SomeClass : public Base
{
    using Base::Base; // говорим что используем конструктор базового класса
};

int main(int argc, const char * argv[]) 
{
    SomeClass obj(); // работает
    SomeClass obj2(2,3.3); // работает

    return 0;
}