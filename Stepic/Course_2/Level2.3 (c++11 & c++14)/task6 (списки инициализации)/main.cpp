#include <iostream>
#include <tuple>

/*
    списки инициализации позволяют передавать списки типа {1, 2, 3...} в методы, функции, классы
*/

// для классов
template<typename T>
struct Array {
    Array(std::initializer_list<T> list) {};
};

Array<int> arr = {1, 2, 3};

// для функции
void foo(std::initializer_list<int> list)
{

}


int main(int argc, const char * argv[]) 
{   
    foo({1, 2, 3});

    return 0;
}