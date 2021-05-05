#include <iostream>
#include <tuple>

/*
    Напишите шаблонную функцию to_pair, которая принимает произвольный 
    std::tuple и два индекса внутри и возвращает std::pair, содержащий 
    элементы переданного std::tuple с соответствующими индексами.

    Пример:

    auto t = std::make_tuple(0, 3.5, "Hello");
    std::pair<double, char const *> p = to_pair<1,2>(t); 
    // p содержит 3.5 и "Hello"

    Замечание: реализация должна работать в рамках стандарта C++11.
*/

template <int A, int B, typename T>
auto to_pair(T t) -> decltype(std::make_pair(std::get<A>(t), std::get<B>(t)))
{
    return std::make_pair(std::get<A>(t), std::get<B>(t));
}

int main(int argc, const char * argv[]) 
{
    auto t = std::make_tuple(0, 3.5, "Hello");
    std::pair<double, char const *> p = to_pair<1,2>(t);

    std::cout << std::get<0>(p) << std::endl;
    std::cout << std::get<1>(p) << std::endl;

    return 0;
}