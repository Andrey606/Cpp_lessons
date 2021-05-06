#include <iostream>

using namespace std;

/*
    perfect forwarding
    std::forward позволяет сохранять тип (rvalue или lvale) внутри функции
*/


// это шаблон и он принимает и rvalue и lvalue и тут происходят склейки
template<typename T>
void foo2(T && value) 
{
    // value внутри этой функции всегда является lvalue ref
    // но при использованни std::forward мы можем сделать value rvalue если он таким был передан 
    std::forward<T>(value); // тут value передан с таким же типом что и в функцию foo2
        
}

// !! помните, что в теле функции формальный параметр является lvalue вне зависимости от того, как он был передан в функцию.


int main(int argc, const char * argv[]) 
{

    return 0;
}

/*

    Резюме по std::move и std::forward
    std::move нужно применять:

    когда хотите явно передать значение по rvalue-ссылке:

    X x;
    foo(std::move(x)); // передача rvalue-ссылки
    или когда хотите передать rvalue-ссылку - аргумент функции в другую функцию:

    void foo(X && x)
    {
        bar(std::move(x)); // передача rvalue-ссылки
    }


    std::forward нужно применять:

    только тогда, когда вы хотите перенаправить аргумент функции - универсальную ссылку в другую функцию:

    template<class T>
    void foo(T && t)
    {
        bar(std::forward<T>(t)); // перенаправление
    }

*/