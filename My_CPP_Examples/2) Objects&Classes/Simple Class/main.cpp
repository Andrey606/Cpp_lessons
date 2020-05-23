// structure.cpp
// структура для хранения инфр=ормации о деталях изделия

#include <iostream>
#include <clocale> // для коректного отображения русских символов
using namespace std;

class smallobj          // определение класса
{
    private:
        int somedata;   // поле класса
    public:
        void setdata(int d)
            { somedata = d;}
        void showdata()
            { cout << "Значение поля равно " << somedata << endl;}
};


int main()
{
    setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали

    smallobj s1, s2;

    s1.setdata(1066);
    s2.setdata(10766);

    s1.showdata();
    s2.showdata();

    return 0;
}
