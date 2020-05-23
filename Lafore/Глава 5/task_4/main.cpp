/*
* Напишите функцию, принимающую в качестве аргументов два значения
* типа Distance и возвращающую значение наибольшего из аргументов (не-
* обходимую информацию можно найти в примере RETSTRC).
*/

#include <iostream>

using namespace std;

struct Distance
// длина в английской системе
{
    int feet;       // 1 фут = 12 дюймов
    float inches;   // 1 дюйм
};

Distance comparison(Distance a, Distance b);

int main() 
{
    Distance a = {5, 6};
    Distance b = {2, 3};
    Distance c = {0};

    cout << "a is: {" << a.feet << "," << a.inches << "}" <<  endl;
    cout << "b is: {" << b.feet << "," << b.inches << "}" <<  endl;
    cout << "c is: {" << c.feet << "," << c.inches << "}" <<  endl;

    c = comparison(a, b);
    
    cout << "a is: {" << a.feet << "," << a.inches << "}" <<  endl;
    cout << "b is: {" << b.feet << "," << b.inches << "}" <<  endl;
    cout << "c is: {" << c.feet << "," << c.inches << "}" <<  endl;

    return 0;
}

Distance comparison(Distance a, Distance b)
{
    if(((a.feet*12)+a.inches) > ((b.feet*12)+b.inches))
        return a;
    else
        return b;
}