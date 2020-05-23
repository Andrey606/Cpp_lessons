/*
* Напишите функцию с именем zeroSmaller(), в которую передаются с по-
* мощью ссылок два аргумента типа int, присваивающую меньшему из ар-
* гументов нулевое значение. Напишите программу для проверки работы
* функции.
*/

#include <iostream>

using namespace std;

void zeroSmaller(int &a, int &b);

int main() 
{
    int number1 = 0, number2 = 0;

    cout << "Enter the number1: "; cin >> number1;
    cout << "Enter the number2: "; cin >> number2;

    zeroSmaller(number1, number2);
    
    cout << "number1 is:" << number1 << endl;
    cout << "number2 is:" << number2 << endl;

    return 0;
}

void zeroSmaller(int &a, int &b)
{
    if(a>b)
        b=0;
    else if(a<b)
        a=0;
    else
        a=0;
}