#include <assert.h>
#include <map>
#include <limits>
#include <iostream>
#include <random>
#include <list>
#include "test.h"

using namespace std;

// #1
class A
{
public:
    int *a;

    void method_a()
    {
        a = new int(2);
        std::cout << "method_a" << std::endl;
    }
    void method()
    {
        std::cout << "1" << std::endl;
    }
    A operator++()
    {
        std::cout << "2" << std::endl;
        return A();
    }
};

// #2 
typedef std::list<int> list_l;
extern bool bad(int);

int main(int argc, char* argv[])
{
    // #1 нормально ли будет работать код, и ничего что я не создал обект класса, чем отличаются методы от функции
    A* obj = nullptr;
    obj->method(); // Дело в том, что у тебя этот метод дёргает все статическое, для его работы не требуется выделение памяти
    obj->method_a(); // segmantation failed так как идет работа с динамической памятью
    obj++; // мы просто сдвинули указатель память на 1

    A obj2;
    obj2.method_a(); // так работает
    // #2 где тут ошибка?, как устроен  двухсвязного списка, итератор, ++it
    /*list_l l = {1, 2, 3, 4, 5};
    for (list_l::iterator it = l.begin(); it != l.end(); ++it)
    {
        if(bad(*it))
        {
            l.erase(it); // ошибка!! вот как надо -> it = l.erase(it);
        }
    }*/

    // #3 зачем нужны виртуальные деструкторы

    // #4 от чего зависит размер указателей
    int *a;
    cout << "*int: " << sizeof(a) << endl;
    cout << "size_t: " << sizeof(size_t) << endl;

    return 0;
}