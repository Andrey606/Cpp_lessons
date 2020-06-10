/*
* Возведение числа n в степень р — это умножение числа n на себя р раз.
* Напишите функцию с именем power(), которая в качестве аргументов принимает 
* значение типа double для n и значение типа int для р и возвращает
* значение типа double. Для аргумента, соответствующего степени числа, 
* задайте значение по умолчанию, равное 2, чтобы при отсутствии показателя
* степени при вызове функции число n возводилось в квадрат. Напишите
* функцию main(), которая запрашивает у пользователя ввод аргументов для
* функции power(), и отобразите на экране результаты ее работы.
*/

#include <iostream>

using namespace std;

double power(double n, int p);

int main() 
{
    double number = 0;
    int pwr = 0;

    cout << "Enter the number: "; cin >> number;
    cout << "Enter the power: ";  cin >> pwr;
    cout << number << "^" << pwr << "=" << power(number, pwr) << endl;

    return 0;
}

double power(double n, int p)
{
    if (p == 0)
        return 1;
    else if ((p % 2) == 0)
        return power(n, p / 2) * power(n, p / 2);
    else
        return n * power(n, p / 2) * power(n, p / 2);
}