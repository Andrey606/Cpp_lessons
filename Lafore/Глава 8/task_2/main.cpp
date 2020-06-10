/*
*
* Напишите программу, которая заменяет перегруженную операцию + на перегруженную операцию += в программе STRPLUS этой главы. 
* Эта опера- ция должна позволять записывать выражения типа:
* s1 += s2;
* где s2 прибавляется (объединяется) к строке s1, результат при этом оста- ется в s1. 
* Операция должна также позволять использовать результат для других вычислений, например в выражениях типа
* s3 = s1 += s2;
* 
*/

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class String // наш класс для строк
{
    private:
        enum { SZ = 80 }; // максимальный размер строки
        char str [ SZ ]; // массив для строки
    public:
        // конструктор без параметров 
        String ( )
        { strcpy ( str, "" ); }
        // конструктор с одним параметром
        String ( char s [ ] )
        { strcpy ( str, s ); }
        // показ строки
        void display ( ) const
        { cout << str << endl; }
        // оператор сложения
        String operator+ ( String ss ) const
        {
            String temp; // временная переменная
            if ( strlen ( str ) + strlen ( ss.str ) < SZ )
            {
                strcpy ( temp.str, str ); // копируем содержимое первой строки
                strcat ( temp.str, ss.str ); // добавляем содержимое второй строки
            }
            else
            {
                cout << "\nПереполнение!";
                exit ( 1 );
            }
            return temp; // возвращаем результат
        }

        String operator+= ( String ss )
        {
            if ( strlen ( str ) + strlen ( ss.str ) < SZ )
            {
                strcpy ( str, str ); // копируем содержимое первой строки
                strcat ( str, ss.str ); // добавляем содержимое второй строки
            }
            else
            {
                cout << "\nПереполнение!";
                exit ( 1 );
            }
            return str; // возвращаем результат
        }
};


int main()
{
    String s1 = "String1";
    String s2 = "String2";
    String s3;

    cout << 1 << endl;
    s1.display();
    cout << 2 << endl;
    s2.display();
    cout << 3 << endl;
    s3.display();

    //s3 = s1 + " " + s2;
    //s1 += s2;
    s3 = s1 += s2;

    cout << 1 << endl;
    s1.display();
    cout << 2 << endl;
    s2.display();
    cout << 3 << endl;
    s3.display();

    return 0;                                                  
}

