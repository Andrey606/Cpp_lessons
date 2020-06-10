/*
* Что такое mutex | Cинхронизация потоков | Многопоточное программирование | C++ #6
* защита разделяемых потоков
*/

#include <iostream>
#include <thread>
#include <mutex>
#include "SimpleTimer.hpp"

using namespace std;

mutex mtx;

void Print(char ch)
{
    // этот участок кода можешт использоваться только одним потоком
    mtx.lock();
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t i = 0; i < 10; i++)
        {
            cout << ch;
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout << endl;
    }
    cout << endl;
    mtx.unlock();
}

using namespace std;

int main() 
{
    setlocale(LC_ALL, "ru");

    // засекаем время работы программы
    SimpleTimer timer;

    thread t1(Print, '*');
    thread t2(Print, '#');

    t1.join();
    t2.join();

    return 0;
}