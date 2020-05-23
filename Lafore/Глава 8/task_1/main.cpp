/*
*
* Добавьте в класс Distance из программы ENGLPLUS этой главы перегру- женную операцию -, 
* которая вычисляет разность двух интервалов. Она должна позволять выполнение выражений типа dist3=dist1-dist2;. 
* Предпо- лагаем, что эта операция никогда не будет использоваться для вычитания большего интервала из меньшего 
* (так как отрицательного интервала быть не может).
*
*/

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class Distance // класс английских мер длины
{
    private:
        int feet;
        float inches;
    public:
        // конструктор без параметров
        Distance ( ) : feet ( 0 ), inches ( 0.0 )
        { }
        // конструктор с двумя параметрами
        Distance ( int ft, float in ) : feet ( ft ), inches ( in )
        { }
        // получение информации от пользователя
        void getdist ( )
        {
            cout << "\nВведите футы: "; cin >> feet;
            cout << "Введите дюймы: "; cin >> inches;
        }
        // показ информации
        void showdist ( )
        { cout << feet << "\'-" << inches << '\"' << endl; }
        // сложение двух длин
        Distance operator+ ( Distance ) const;
        // вычитание двух длин
        Distance operator- ( Distance ) const;
};

// сложение двух длин
Distance Distance::operator+ ( Distance d2 ) const
{
    int f = feet + d2.feet; // складываем футы
    float i = inches + d2.inches; // складываем дюймы
    if ( i >= 12.0 ) // если дюймов стало больше 12
    {
        i -= 12.0; // то уменьшаем дюймы на 12
        f++; // и увеличиваем футы на 1
    }
    return Distance ( f, i ); // создаем и возвращаем временную переменную
}

// сложение двух длин
Distance Distance::operator- ( Distance d2 ) const
{
    int f = feet - d2.feet; // складываем футы
    float i = inches - d2.inches; // складываем дюймы
    if ( i >= 12.0 ) // если дюймов стало больше 12
    {
        i -= 12.0; // то уменьшаем дюймы на 12
        f++; // и увеличиваем футы на 1
    }
    return Distance ( f, i ); // создаем и возвращаем временную переменную
}

int main()
{
    Distance d1(100, 5);
    Distance d2(1, 4);
    Distance d3;

    d1.showdist();
    d2.showdist();
    d3.showdist();

    d3 = d1 - d2;

    d1.showdist();
    d2.showdist();
    d3.showdist();

    return 0;                                                  
}

