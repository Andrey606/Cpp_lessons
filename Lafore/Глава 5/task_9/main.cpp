/*
* Переработайте программу из упражнения 8 так, чтобы функция swap() 
* принимала в качестве аргументов значения типа time (см. упражнение 6).
*/

#include <iostream>

using namespace std;

typedef struct s_time{
    int hours;
    int minutes;
    int sec;
} s_time;

void swap(s_time &a, s_time &b);

int main() 
{
    s_time a = {0};
    s_time b = {0};

    cout << "Enter the number a.hours: "; cin >> a.hours;
    cout << "Enter the number a.minutes: "; cin >> a.minutes;
    cout << "Enter the number a.sec: "; cin >> a.sec;
    
    cout << "Enter the number b.hours: "; cin >> b.hours;
    cout << "Enter the number b.minutes: "; cin >> b.minutes;
    cout << "Enter the number b.sec: "; cin >> b.sec;

    cout << "number 'a' is: " << a.hours << ":" << a.minutes << ":" << a.sec << endl;
    cout << "number 'b' is: " << b.hours << ":" << b.minutes << ":" << b.sec << endl;

    swap(a, b);

    cout << "number 'a' is: " << a.hours << ":" << a.minutes << ":" << a.sec << endl;
    cout << "number 'b' is: " << b.hours << ":" << b.minutes << ":" << b.sec << endl;

    return 0;
}

void swap(s_time &a, s_time &b)
{
    s_time buf = a;
    a=b;
    b=buf; 
}