/*
* Лямбда выражения и возврат результата выполнения потока
*/

#include <iostream>
#include <thread>
#include <chrono> // для работы с временем

using namespace std;

int Sum(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "=============\t" << "Sum STARTED\t=============" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    int sum = a+b;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "=============\t" << "Sum STOPPED\t=============" << endl;

    return sum;
}


int main() 
{
    setlocale(LC_ALL, "ru");

    int result;
    // запускаем в потоке лямду которая вызовет функцию сам и вернет ее результат
    thread th([&result]()
    {
        result = Sum(2, 5);
    });
   
    for (int i = 0; i<10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    th.join();
    cout << "Sum result = " << result << endl;
   
    return 0;
}