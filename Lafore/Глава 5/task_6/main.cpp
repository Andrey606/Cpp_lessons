/*
* Модифицируйте программу, описанную в упражнении 11 главы 4 «Струк- туры», 
* складывающую два структурных значения типа time. Теперь про- грамма должна 
* включать в себя две функции. Первая, time_to_secs(), при- нимает в качестве 
* аргумента значение типа time и возвращает эквивалентное значение в секундах типа long.
* Вторая, secs_to_time(), в качестве аргумента принимает число секунд, имеющее тип long,
* а возвращает эквивалентное значение типа time.
*/

#include <iostream>

using namespace std;

typedef struct s_time{
    int hours;
    int minutes;
    int sec;
} s_time;

long time_to_secs(s_time t);
s_time secs_to_time(long sec);

int main() 
{
    s_time t = {0,0,0};
    int sec = 0;

    cout << "Enter sec: ";
    cin >> sec;
    t = secs_to_time(sec);
    cout << t.hours << ":" << t.minutes << ":" << t.sec << endl;

    cout << "Enter hours: "; cin >> t.hours;
    cout << "Enter minutes: "; cin >> t.minutes;
    cout << "Enter seconds: "; cin >> t.sec;

    cout << "Seconds: " << time_to_secs(t) << endl;

    return 0;
}

long time_to_secs(s_time t)
{
    return (t.hours*3600)+(t.minutes*60)+(t.sec);
}

s_time secs_to_time(long sec)
{
    s_time t = {0, 0, 0};

    t.hours = sec/3600;
    t.minutes = (sec-(t.hours*3600))/60;
    t.sec = (sec-(t.minutes*60)-(t.hours*3600));

    return t;
}