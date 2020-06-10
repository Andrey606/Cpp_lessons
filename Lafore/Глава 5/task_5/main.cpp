/*
* Напишите функцию с именем hms_to_secs(), имеющую три аргумента типа
* int: часы, минуты и секунды. Функция должна возвращать эквивалент пе-
* реданного ей временного значения в секундах (типа long). Создайте про-
* грамму, которая будет циклически запрашивать у пользователя ввод значе-
* ния часов, минут и секунд и выводить результат работы функции на экран.
*/

#include <iostream>

using namespace std;

int hms_to_secs(int hours, int minutes, int seconds);

int main() 
{
    char command;
    int hours, minutes, seconds;
    
    do
    {
        cout << "Enter hours:"; cin >> hours; 
        cout << "Enter minutes:"; cin >> minutes;
        cout << "Enter seconds:"; cin >> seconds;        

        cout << hours << ":" << minutes << ":" << seconds << "=" << hms_to_secs(hours, minutes, seconds) << "sec"<< endl;
        
        cout << "Exit? (Y/N): ";
        cin >> command;
    }while(command != 'Y');

    return 0;
}

int hms_to_secs(int hours, int minutes, int seconds)
{
    return (hours*3600)+(minutes*60)+seconds;
}