#include <iostream>
#include <tuple>

/*
    Напишите constexpr бинарные операторы +, - и * (скалярное произведение) для структуры Point.

    Пример использования:


    constexpr size_t size = static_cast<size_t>(Point(2,4) * Point(4,3));
    int m[size]; // массив из 20 элементов

*/


struct Point
{
    constexpr Point(double x, double y) 
        : x(x), y(y) 
    {}

    double x = 0;
    double y = 0;
};

// сложение
constexpr Point operator+(const Point &p1, const Point &p2)
{
    return Point((p1.x + p2.x), (p1.y + p2.y));
}

// вычитание
constexpr Point operator-(const Point &p1, const Point &p2)
{
    return Point((p1.x - p2.x), (p1.y - p2.y));
}

// скалярное произведение
constexpr double operator*(const Point &p1, const Point &p2)
{
    return double((p1.x * p2.x) + (p1.y * p2.y));
}


int main(int argc, const char * argv[]) 
{
    constexpr size_t size = static_cast<size_t>(Point(2,4) * Point(4,3));
    int m[size]; // массив из 20 элементов

    std::cout << "size: " << size << std::endl; 

    // tests

    Point p1 = (Point(2,4) + Point(2,4)) - Point(4,3);

    return 0;
}