/*
* Возврат результата из потока по ссылке
*/

#include <iostream>
#include <thread>
#include <chrono> // для работы с временем

using namespace std;

void DoWork(int &a)
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "=============\t" << "DoWork STARTED\t=============" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    a+=5;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "=============\t" << "DoWork STOPPED\t=============" << endl;
}


int main() 
{
    setlocale(LC_ALL, "ru");

    int a = 10;

    cout << "a = " << a << endl;

    thread th(DoWork, ref(a));
   
    for (int i = 0; i<10; i++)
    {
        cout << "a = " << a << endl;
        cout << "ID потока = " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    th.join();
   
    return 0;
}