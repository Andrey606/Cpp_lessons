/*
* Напишите функцию, которая при каждом вызове будет выводить на эк- ран количество раз,
* которое она вызывалась ранее. Напишите программу, которая будет вызывать данную функцию не менее 10 раз. 
* Попробуйте реализовать данную функцию двумя различными способами: с использо- ванием глобальной переменной и
* статической локальной переменной для хранения числа вызовов функции. Какой из способов предпочтительней? 
* Почему для решения задачи нельзя использовать обычную локальную пе- ременную?
*/

#include <iostream>

using namespace std;

void counter_local(void);
void counter_global(void);

int count;

int main() 
{
    counter_local(); // 0
    counter_local(); // 1
    counter_local();
    counter_local();
    counter_local();
    counter_local();
    counter_local();
    counter_local();
    counter_local();
    counter_local(); // 9

    counter_global(); // 0
    counter_global();
    counter_global();
    counter_global();
    counter_global();
    counter_global();
    counter_global();
    counter_global();
    counter_global();
    counter_global(); // 9
   
    return 0;
}

void counter_local(void)
{
    static int count_2;

    cout << "func was called " << count_2++ << " times" << endl;
}

void counter_global(void)
{
    cout << "func was called " << count++ << " times" << endl;
}