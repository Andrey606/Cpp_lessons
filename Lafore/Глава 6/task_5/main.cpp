/*
* Взяв в качестве основы структуру из упражнения 5 главы 4, создайте класс date. Его данные должны размещаться в трех полях типа int: month, day и year.
* Метод класса getdate() должен принимать значение для объекта в формате 12/31/02, а метод showdate() — выводить данные на экран.
*/

#include <iostream>
#include <iomanip>

using namespace std;

typedef struct Date{
    int month;
    int day;
    int year;
} Date;

class date
{
    private:
        Date d;
    public:
        date(): d({1,2,3})
        { }
        date(int d, int m, int y): d({d,m,y})
        { }

        void getdate(Date date)
        {
            d = date;
        }

        void showDate(void) const 
        {
            cout << d.month << "/" << d.day << "/" << d.year << endl;
        } 
};


int main()
{
    Date d = {12, 30, 4};

    date d1;
    date d2(1,5,6);

    d1.showDate();
    d2.showDate();

    d2.getdate(d);

    d2.showDate();


    return 0;                                                  
}