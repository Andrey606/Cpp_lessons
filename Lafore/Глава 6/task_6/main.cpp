/*
* Расширьте содержание класса employee из упражнения 4, включив в него класс date и перечисление etype (см. упражнение 6 главы 4). 
* Объект клас- са date будет использоваться для хранения даты приема сотрудника на ра- боту. Перечисление будет использовано для 
* хранения статуса сотрудника: лаборант, секретарь, менеджер и т. д. Последние два поля данных должны быть закрытыми в определении 
* класса employee, как и номер и оклад сотруд- ника. Вам будет необходимо разработать методы getemploy() и putemploy(), 
* предназначенные соответственно для ввода и отображения информации о сотруднике. Возможно, при создании методов вам понадобится ветвление 
* switch для работы с перечисляемым типом etype. Напишите функцию main(), которая попросит пользователя ввести данные о трех сотрудниках, 
* а за- тем выведет эти данные на экран.
*/

#include <iostream>
#include <iomanip>

using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

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

        void getdate(void)
        {
            cout << "set data!" << endl;
            cout << "set month:"; cin >> d.month;
            cout << "set day:"; cin >> d.day;
            cout << "set year:"; cin >> d.year;
        }

        void showDate(void) const 
        {
            cout << d.month << "/" << d.day << "/" << d.year << endl;
        } 
};

class employee : public date
{
    private:
        static int number;
        float salary;
        etype role;
    public:
       employee():salary(0.0)
       { number++; }
       employee(float sal):salary(sal)
       { number++; }

       void set_salary(void)
       {
           cout << "Enter the salary: ";
           cin >> salary;
       }

       void display(void) const 
       {
           cout << "number of worker: " << number << endl; 
           cout << "salary of worker: " << salary << endl; 
       }

       void getemploy()
       {
           cout << "================================" << endl;
           display();
           showDate();
           cout << "role of worker: ";
           switch (role)
            {
                case laborer: cout << "laborer" << endl; break;
                case secretary: cout << "secretary" << endl; break;
                case manager: cout << "manager" << endl; break;
                case accountant: cout << "accountant" << endl; break;
                case executive: cout << "executive" << endl; break;
                case researcher: cout << "researcher" << endl; break;   
                default: cout << "laborer" << endl; break;
            }
            cout << "================================" << endl;
       }

       void putemploy(void)
       {
            getdate();

            cout << "select role of employ:" << endl
            << "1. laborer"<< endl
            << "2. secretary"<< endl
            << "3. manager"<< endl
            << "4. accountant"<< endl
            << "5. executive"<< endl
            << "6. researcher"<< endl;

            int r;
            cin >> r; 

            switch (r-1)
            {
                case laborer: role = laborer; break;
                case secretary: role = secretary; break;
                case manager: role = manager; break;
                case accountant: role = accountant; break;
                case executive: role = executive; break;
                case researcher: role = researcher; break;   
                default: role = laborer; break;
            }
            set_salary();
       }
};

int employee::number = 0;

int main()
{
    for (size_t i = 0; i < 4; i++)
    {
        employee newEmployee;
        newEmployee.putemploy();
        newEmployee.getemploy();
    }

    return 0;                                                  
}