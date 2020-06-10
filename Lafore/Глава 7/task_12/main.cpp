/*
*
* Создайте класс bMoney. Он должен хранить денежные значения как long double. Используйте метод mstold() 
* для преобразования денежной строки, введенной пользователем, в long double, и метод ldtoms() для преобразова- ния 
* числа типа long double в денежную строку для вывода (см. упражне- ния 6 и 10). Вы можете вызывать для ввода и вывода методы getmoney()
* и putmoney(). Напишите другой метод класса для сложения двух объектов типа bMoney и назовите его madd(). 
* Сложение этих объектов легко произ- вести: просто сложите переменную типа long double одного объекта с та- кой же 
* переменной другого объекта. Напишите функцию main(), которая просит пользователя несколько раз ввести денежную
* строку, а затем вы- водит сумму значений этих строк. Вот как может выглядеть определение класса:
*/

#include <iostream>
#include <iomanip>
#include <string.h>
#include <cmath>

using namespace std;

class bMoney {
    private:
        long double money; 
    public: 
        bMoney ( ): money(0.0)
        { }
        bMoney ( char s [ ] )
        {
            char str [ 50 ] = {0};
            money = strtold(s, nullptr);
        }
        void madd ( bMoney m1, bMoney m2 )
        {
            cout << m1.money << "+" <<  m2.money << "=" << (m1.money + m2.money) <<  "$" << endl;
        }
        void getmoney ( void ) const 
        {
            cout << "money: " << money << "$" << endl;
        }
        void putmoney ( )
        {
            char str [ 50 ] = {0};
            cout << "Enter the value of dollars (156.5 $): ";
            cin.get(str, 50, '$');
            money = strtold(str, nullptr);
        }
};

int main()
{ 
    bMoney m1, m2 = "152.7", m3;

    m1.putmoney();
    m1.getmoney();
    m2.getmoney();

    m3.madd(m1, m2);

    return 0;
}