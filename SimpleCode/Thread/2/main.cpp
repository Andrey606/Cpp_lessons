/*
* передача параметров в поток
*/

#include <iostream>
#include <thread>
#include <chrono> // для работы с временем

using namespace std;

void DoWork(int a, int b, string msg)
{
    cout << msg << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "=============\t" << "DoWork STARTED\t=============" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "a+b = " << a+b << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "=============\t" << "DoWork STOPPED\t=============" << endl;
}


int main() 
{
    setlocale(LC_ALL, "ru");

    thread th(DoWork, 2, 3, "our message");
   
    for (int i = 0; true; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    th.join();
   
    return 0;
}