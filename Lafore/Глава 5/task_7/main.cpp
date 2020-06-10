/*
* Взяв в качестве основы функцию power() из упражнения 2,
* работающую только со значением типа double, создайте перегруженные функции с этим же именем,
* принимающими в качестве аргумента значения типа char, int, long и float. Напишите программу, 
* вызывающую функцию power() со все- ми возможными типами аргументов.
*/

#include <iostream>

using namespace std;

double power(double n, int p);
char power(char n, int p);
int power(int n, int p);
long power(long n, int p);
float power(float n, int p);

int main() 
{
    long number = 0;
    int pwr = 0;

    cout << "Enter the number: "; cin >> number;
    cout << "Enter the power: ";  cin >> pwr;

    cout << "power(double)" << endl;
    cout << number << "^" << pwr << "=" << power(static_cast<double>(number), pwr) << endl;
    cout << "power(char)" << endl;
    cout << number << "^" << pwr << "=" << power(static_cast<char>(number), pwr) << endl;
    cout << "power(int)" << endl;
    cout << number << "^" << pwr << "=" << power(static_cast<int>(number), pwr) << endl;
    cout << "power(long)" << endl;
    cout << number << "^" << pwr << "=" << power(static_cast<long>(number), pwr) << endl;
    cout << "power(float)" << endl;
    cout << number << "^" << pwr << "=" << power(static_cast<float>(number), pwr) << endl;

    return 0;
}

double power(double n, int p)
{
    if (p == 0)
        return 1;
    else if ((p % 2) == 0)
        return power(n, p / 2) * power(n, p / 2);
    else
    {
        return n * power(n, p / 2) * power(n, p / 2);
    }
        
}

char power(char n, int p)
{    
    if (p == 0)
        return 1;
    else if ((p % 2) == 0)
        return power(n, p / 2) * power(n, p / 2);
    else
        return n * power(n, p / 2) * power(n, p / 2);
}

int power(int n, int p)
{
    if (p == 0)
        return 1;
    else if ((p % 2) == 0)
        return power(n, p / 2) * power(n, p / 2);
    else
        return n * power(n, p / 2) * power(n, p / 2);
}

long power(long n, int p)
{    
    if (p == 0)
        return 1;
    else if ((p % 2) == 0)
        return power(n, p / 2) * power(n, p / 2);
    else
        return n * power(n, p / 2) * power(n, p / 2);
}

float power(float n, int p)
{    
    if (p == 0)
        return 1;
    else if ((p % 2) == 0)
        return power(n, p / 2) * power(n, p / 2);
    else
        return n * power(n, p / 2) * power(n, p / 2);
}