/*
* const_cast
*/
#include <iostream>

using namespace std;

void foo(double const & d)
{
    const_cast<double &>(d) = 10;
}

int main(int argc, const char * argv[]) 
{
    // 0
    int Num = 10;
    int Num2 = 10;

    // значение константоное
    /*const int *numPtr = &Num;
    int const *numPtr2 = &Num;
    *numPtr = 11; // ошибка
    *numPtr2 = 12; // ошибка */

    // указатель константный
    /*
    int *const numPtr3 = &Num;
    *numPtr3 = 11; // ок
    numPtr3 = &Num2;// ошибка */

    
    // 1
    /*double num = 1;

    cout << num << endl;
    foo(num);
    cout << num << endl;*/

    // 2
    int a = 27;
    int const b = 412;
    int * pa = &a;

    int const c = const_cast<int const &>(a);
    int const c2 = a;
    cout << typeid(c).name() << endl;
    cout << typeid(c2).name() << endl;

    int d = const_cast<int &>(b);
    int d2 = b;
    cout << typeid(d).name() << endl;
    cout << typeid(d2).name() << endl;

    int const * p1 = const_cast<int const *>(pa);
    int const * p11 = pa;
    cout << typeid(p1).name() << endl;
    cout << typeid(p11).name() << endl;

    int * const * p2 = const_cast<int * const *>(&pa);
    int * const * p22 = &pa;
    cout << typeid(p2).name() << endl;
    cout << typeid(p22).name() << endl;

    int const ** p3 = const_cast<int const **>(&pa);
    //int const ** p33 = pa; // ошибка
    cout << typeid(p3).name() << endl;

    int const * const * p4 = const_cast<int const * const *>(&pa);
    int const * const * p44 = &pa;
    cout << typeid(p4).name() << endl;
    cout << typeid(p44).name() << endl;

    return 0;
}