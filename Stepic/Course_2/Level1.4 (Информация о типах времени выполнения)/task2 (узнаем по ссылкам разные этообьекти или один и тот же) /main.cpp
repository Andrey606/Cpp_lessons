/*
Предположим, что вам даётся два указателя на объект некоторого сложного полиморфного класса, который использует множественное наследование. Оба указателя имеют один и тот же тип, но могут ссылаться на разные однотипные базы внутри одного объекта.

Напишите шаблонную функцию, которая по двум однотипным указателям проверяет, указывают ли они на один объект.
*/
#include <iostream>

using namespace std;

// возвращает true, если p и q указывают на один и тот же объект

/*
dynamic_cast<const T*>(p) - проверяет тип указателя (а) если он соответствует девствительности <const T*> то производит преобразование
*/

struct Unit
{
    virtual ~Unit() {}
};

struct Unit2
{
    virtual ~Unit2() {}
};

struct Unit3: Unit, Unit2
{
    
};


template<class T>
bool isSameObject(T const * p, T const * q)
{
    cout << (dynamic_cast<const T*>(p) == dynamic_cast<const T*>(q))  << endl;
    cout << (dynamic_cast<const void*>(p) == dynamic_cast<const void*>(q)) << endl;

    return (dynamic_cast<const void*>(p) == dynamic_cast<const void*>(q))
}


int main(int argc, const char * argv[]) 
{
    Unit* p = new Unit3();
    Unit* q = new Unit();
    
    isSameObject<Unit>(p, q); // false
    
    return 0;
}