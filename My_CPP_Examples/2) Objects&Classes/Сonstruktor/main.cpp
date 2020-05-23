// structure.cpp
// счетчик в качестве обьекта

#include <iostream>
#include <clocale> // для коректного отображения русских символов
using namespace std;

class Counter
{
    private:
        unsigned int count;
    public:
        Counter() : count(0)    // конструктор
            {/*пустое тело*/}
        void inc_count()        // инкрементирование счетчика
            {count++;}
        int get_count()         // получение значения счетчика
        {return count;}
};


int main()
{
    setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали

    Counter c1, c2;                     // определение с инициилизацией
    cout << "\nc1=" << c1.get_count();  // вывод
    cout << "\nc2=" << c2.get_count();

    c1.inc_count();                     // инкрементирование c1
    c2.inc_count();                     // инкрементирование c2
    c2.inc_count();                     // инкрементирование c2

    cout << "\nc1=" << c1.get_count();  // вывод
    cout << "\nc2=" << c2.get_count();

    cout << endl;

    return 0;
}
