// structure.cpp
// структура для хранения инфр=ормации о деталях изделия

#include <iostream>
#include <clocale> // для коректного отображения русских символов
using namespace std;

struct part             // обьявление структуры
{
    int modelnumber;    // номер модели изделия
    int partnumber;     // номер детали
    float cost;         // стоимость детали
};


int main()
{
    setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали

    part part3;

    part part1 = {
       .modelnumber = 1,
       .partnumber = 2,
       .cost = 5.5F
    };
    // вывлд значений полей на экран
    cout << "Модель " << part1.modelnumber;
    cout << ", деталь " << part1.partnumber;
    cout << ", стоимость $" << part1.cost << endl;


    part part2 = {10, 5, 8.8F};
    // вывлд значений полей на экран
    cout << "Модель " << part2.modelnumber;
    cout << ", деталь " << part2.partnumber;
    cout << ", стоимость $" << part2.cost << endl;

    part3 = part1;
    // вывлд значений полей на экран
    cout << "Модель " << part3.modelnumber;
    cout << ", деталь " << part3.partnumber;
    cout << ", стоимость $" << part3.cost << endl;

    part1.modelnumber = 6244;
    part1.partnumber = 373;
    part1.cost = 217.55F;
    // вывлд значений полей на экран
    cout << "Модель " << part1.modelnumber;
    cout << ", деталь " << part1.partnumber;
    cout << ", стоимость $" << part1.cost << endl;

    return 0;
}
