/*
* Многопоточность | Потоки | thread | Многопоточное программирование | Уроки | C++ #1
* собирай проект не в wsl !
* процес состоит из потоков
* любая программа занимает минимум один процес и поток
*/

#include <iostream>
#include <thread>
#include <chrono> // для работы с временем

using namespace std;

void DoWork()
{
    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tDoWork\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}


int main() 
{
    setlocale(LC_ALL, "ru");

    cout << "START MAIN" << endl;

    // приостанавливает работу текущего потока в (мс)
    //this_thread::sleep_for(chrono::microseconds(5000));

    // узнать id текущего потока
    //cout << this_thread::get_id() << endl;

    // создаем новый поток и передаем в него имя функции (теперь программа выполняеться в двух потокакх)
    thread th(DoWork);

    //thread th2(DoWork);

    // говорим что наш поток может выполняться самостоятельно ни привязываясь не к чему, но после завершения
    // нашего основного потока (main), закончит свою работу и дочерний поток
    //th.detach();

    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    
    cout << "END MAIN" << endl;

    // альтернатива метода detach(), если мы хотим дождаться завершение задачи в другом потоке
    // но этот метод нужно ставить там где мы хотим его дожидаться
    // в тот момент когда мы дожидаемся завершение второго потока, основной будет заблокирован
    th.join();

    //th2.join();
   
    return 0;
}