#include <iostream>
#include <tuple>

/*
    constexpr - в новом стандарте (11, 14) испольуется для вычисление функций и переменных на этапе компиляции

    #1
    constexpr double var = 2.5; // константа времени компиляции
    constexpr double var = 2.5 / 6;

    #2 
    constexpr int pow(int k, int n)
    {
        return k==0 ? 1 : x * pow (x, k-1);
    }

    для этого слова есть ряд ограничений
    - внутри constexpr функций нельзя вызывать не constexpr функции
    - тело constexpr функции должно состоять из единого ретерна

*/


int main(int argc, const char * argv[]) 
{


    return 0;
}