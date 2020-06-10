/*
*
* Представьте себе издательскую компанию, которая торгует книгами и аудио-записями этих книг. 
* Создайте класс publication, в котором хранятся название (строка) и цена (типа float) книги. 
* От этого класса наследуются еще два класса: book, который содержит информацию о количестве страниц в книге (типа int),
* и type, который содержит время записи книги в минутах (тип float). В каждом из этих трех классов должен быть метод getdata(), 
* через который можно получать данные от пользователя с клавиатуры, и putdata(), предназначенный для вывода этих данных.
* Напишите функцию main() программы для проверки классов book и type. Создайте их объекты в программе
* и запросите пользователя ввести и вы- вести данные с использованием методов getdata() и putdata().
*
*/

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class publication
{
    private:
        string title;
        float price;
    public:
        publication(): title("N/A"), price(0.0)
        { }
        publication(string tit, float pri): title(tit), price(pri)
        { }
        void getdata()
        {
            cout <<"Введите заголовок:"; cin >>title;
            cout <<"Введите цену:";cin >>price;
        }
        void putdata() const
        {
            cout << "title: " << title << endl;
            cout << "price: " << price << " $" << endl;
        }
};

class book: public publication
{
    private:
        int page_number;
    public:
        book(): page_number(0), publication()
        { }
        book(int num, string tit, float pri): page_number(num), publication(tit, pri)
        { }
        void getdata()
        {
            publication::getdata();
            cout << "Enter the number of page: ";
            cin >> page_number;
        }
        void putdata() const
        {
            publication::putdata();
            cout << "page_number: " << page_number << endl;
        }
};

class type: public publication
{
    private:
        float time;
    public:
        type(): time(0.0), publication()
        { }
        type(float t, string tit, float pri): time(t), publication(tit, pri)
        { }
        void getdata()
        {
            publication::getdata();
            cout << "Enter the time in minutes: ";
            cin >> time;
        }
        void putdata() const
        {
            publication::putdata();
            cout << "time: " << time << endl;
        }
};

int main()
{
    book book1; //определить публикации
    type tape1;
    book1.getdata(); //получить данные о них
    tape1.getdata();
    book1.putdata(); //вывести данные о них
    tape1.putdata();
    cout << endl;
    return 0;                                              
}

