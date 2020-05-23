/*
*
* Модифицируйте класс time из упражнения 3 главы 6 так, чтобы вместо метода add_time() 
* можно было использовать операцию + для складывания двух значений времени. 
* Напишите программу для проверки класса.
* 
*/

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class Time 
{
    private:
    int hours;
    int minutes;
    int seconds;

    public:
        Time(): hours(0), minutes(0), seconds(0)
        { }
        Time(int h, int m, int s)
        {
            hours = h%24;
            minutes = m%60;
            seconds = s%60;
        }

        void display(void) const
        {
            cout << hours << ":" << minutes << ":" << seconds << endl;
        }

        void setTime(int h, int m, int s)
        {
            hours = h%24;
            minutes = m%60;
            seconds = s%60;
        }

        Time add(const Time& t) const
        {
            Time t2;
            int temp = 0;
            t2.hours = (t.hours+hours)%24;
            t2.minutes = (t.minutes+minutes)%60;
            t2.seconds = (t.seconds+seconds)%60;

            return t2;
        }

        Time operator+ (Time& t) const
        {
            Time temp;
            temp.hours = (t.hours+hours)%24;
            temp.minutes = (t.minutes+minutes)%60;
            temp.seconds = (t.seconds+seconds)%60;

            return temp;
        } 
};


int main()
{
    Time t1(1,59,60);
    Time t2(3,59,0);
    Time t3, t4;

    t1.display();
    t2.display();
    t3.display();
    t4.display();

    t3 = t1.add(t2);
    t4 = t1 + t2;

    t1.display();
    t2.display();
    t3.display();
    t4.display();


    return 0;                                                  
}

