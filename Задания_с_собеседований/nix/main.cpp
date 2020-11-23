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
    A* obj;
    obj->method();
    obj++; // мы сдвинули память на 1

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

    return 0;
}