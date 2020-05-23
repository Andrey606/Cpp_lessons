/*
* Вернитесь к рассмотрению примера CIRCAREA главы 2 «Основы програм- мирования на C++». 
* Напишите функцию с именем circarea(), которая ана- логичным образом вычисляет площадь круга. 
* Функция должна принимать один аргумент типа float и возвращать значение типа float. 
* Напишите функ- цию main(), которая просит пользователя ввести значение радиуса, 
* вызы- вает функцию circarea(), а затем отображает результат вычисления на экране.
*/

#include <iostream>

using namespace std;

float circarea(float);

int main() 
{
    int radius = 0;

    cout << "Enter radius of circle: "; cin >> radius;
    cout << "Area is:" << circarea(radius) << endl;

    return 0;
}

float circarea(float radius)
{
    const float PI = 3.14159F; // вещественная константа

    return (PI *radius *radius); // вычисление площади круга
}