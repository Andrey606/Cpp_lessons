/*
* Создайте класс с именем time, содержащий три поля типа int, предназна- ченные для хранения часов, минут и секунд. 
* Один из конструкторов клас- са должен инициализировать поля нулевыми значениями, а другой конст- руктор — заданным набором значений. 
* Создайте метод класса, который будет выводить значения полей на экран в формате 11:59:59, и метод, складывающий значения двух объектов 
* типа time, передаваемых в качест- ве аргументов.
* В функции main() следует создать два инициализированных объекта (по- думайте, должны ли они быть константными) 
* и один неинициализиро- ванный объект. Затем сложите два инициализированных значения, а ре- зультат присвойте третьему объекту и 
* выведите его значение на экран. Где возможно, сделайте методы константными.
*/

#include <iostream>
#include <iomanip>

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
};

int main()
{
    Time t1(1,59,60);
    Time t2(3,59,0);
    Time t3;

    t1.display();
    t2.display();
    t3.display();

    t3 = t1.add(t2);

    t1.display();
    t2.display();
    t3.display();

    return 0;                                                  
}