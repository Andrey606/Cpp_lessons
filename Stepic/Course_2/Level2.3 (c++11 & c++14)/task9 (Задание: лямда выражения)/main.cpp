#include <iostream>
#include <functional>

/*
    Рассмотрим следующую функцию for_each.

    template<class F>
    void for_each_int(int * p, int * q, F f)
    {
        for ( ; p != q; ++p )
            f(*p);
    }
    Определите переменную square_fun, хранящую безымянную функцию, которая возводит переданное число в квадрат.

    Пример:

    int m[10] = {1,2,3,4,5,6,7,8,9,10};

    for_each_int(m, m + 10, square_fun); // теперь m = {1,4,9,16,25,36,49,64,81,100};

*/


template<class F>
void for_each_int(int * p, int * q, F f)
{
    for ( ; p != q; ++p )
        f(*p);
}

std::function<int (int, int)> op = [](int x, int y) { return x*y; };


int main(int argc, const char * argv[]) 
{   
    auto square_fun = [](int &a){ a = a*a; };
    int m[10] = {1,2,3,4,5,6,7,8,9,10};

    for_each_int(m, m + 10, square_fun); // теперь m = {1,4,9,16,25,36,49,64,81,100};

    return 0;
}