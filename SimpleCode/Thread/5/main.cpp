/*
* С++ потоки и методы класса | С++ метод класса в потоке | Многопоточное программирование | C++ #5
* Запуск метода класса в отдельном потоке
*/

#include <iostream>
#include <thread>
#include <chrono> // для работы с временем

using namespace std;

class MyClass
{
public:
    void DoWork()
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "=============\t" << "DoWork STARTED\t=============" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "=============\t" << "DoWork STOPPED\t=============" << endl;
    }
    void DoWork2(int a)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "=============\t" << "DoWork2 STARTED\t=============" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "DoWork2 значение параметра\t" << a << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "=============\t" << "DoWork2 STOPPED\t=============" << endl;
    }
    int Sum(int a, int b)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "=============\t" << "Sum STARTED\t=============" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "=============\t" << "Sum STOPPED\t=============" << endl;
        return a+b;
    }
private:

};


int main() 
{
    setlocale(LC_ALL, "ru");

    MyClass m;
    int result;

    // #1 ================================
    // символ & - означает что все переменные выше будут видны внутри анонимной функции
    thread th([&]()
    {
        result =  m.Sum(2,5);
    });

    // #2 ================================
    // так можно запускать методы класса в другом потоке, в случае если метод ничего не возвращает
    thread th2(&MyClass::DoWork, m);

    // #3 ================================
    thread th3(&MyClass::DoWork2, m, 555);
   
    for (int i = 0; i<10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    th.join();
    th2.join();
    th3.join();
    cout << "Sum result = " << result << endl;
   
    return 0;
}