// structure.cpp
// структура для хранения инфр=ормации о деталях изделия

#include <iostream>
#include <clocale> // для коректного отображения русских символов
using namespace std;

enum days_of_week {Sun, Mon, Tue, Wed, Thu, Fri, Sat};


int main()
{
    setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали

    days_of_week day1, day2;
    day1 = Mon;
    day2 = Thu;

    int diff = day2 - day1;

    cout << "Разница в днях: " << diff << endl;

    if(day1 < day2)
        cout << "day1 наступит раньше, чем day2 \n";

    return 0;
}
