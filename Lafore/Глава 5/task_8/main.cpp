/*
* Напишите функцию с именем swap(), обменивающую значениями два сво- их аргумента типа int (обратите внимание, 
* что изменяться должны значе- ния переменных из вызывающей программы, а не локальных переменных функции). 
* Выберите способ передачи аргументов. Напишите вызывающую программу main(), использующую данную функцию.
*/

#include <iostream>

using namespace std;

void swap(int &a, int &b);

int main() 
{
    int a = 0;
    int b = 0;

    cout << "Enter the number a: "; cin >> a;
    cout << "Enter the number b: "; cin >> b;

    cout << "number 'a' is: " << a << endl;
    cout << "number 'b' is: " << b << endl;

    swap(a, b);

    cout << "number 'a' is: " << a << endl;
    cout << "number 'b' is: " << b << endl;

    return 0;
}

void swap(int &a, int &b)
{
    int buf = a;
    a=b;
    b=buf; 
}