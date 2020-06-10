/*
* Создайте класс employee, используя упражнение 4 главы 4. 
* Класс должен включать поле типа int для хранения номера сотрудника и поле типа float 
* для хранения величины его оклада. Методы класса должны позволять пользователю вводить 
* и отображать данные класса. Напишите функцию main(), которая запросит пользователя ввести 
* данные для трех сотрудни- ков и выведет полученную информацию на экран.
*/

#include <iostream>
#include <iomanip>

using namespace std;

class employee
{
    private:
        static int number;
        float salary;
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
};

int employee::number = 0;

int main()
{
    for (size_t i = 0; i < 4; i++)
    {
        employee newEmployee;
        newEmployee.set_salary();

        newEmployee.display();
    }
    
    return 0;                                                  
}