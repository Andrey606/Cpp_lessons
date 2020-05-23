/*
*
* Модифицируйте класс bMoney из упражнения 12 главы 7 «Массивы и стро- ки», включив арифметические операции, 
* выполненные с помощью пере- груженных операций:
* 
* ЬМоnеу = bMoney + ЬМоnеу 
* ЬМоnеу = bMoney - ЬМоnеу
* bМоnеу = bMoney * long double (цена за единицу времени, затраченного на изделие) 
* long double = bMoney / ЬМоnеу (общая цена, деленная на цену за изделие) 
* bMoney = ЬМоnеу / long double (общая цена, деленная на количество изделий)
*
* Заметим, что операция / перегружена дважды. Компилятор может разли- чить оба варианта,
* так как их аргументы разные. Помним, что легче вы- полнять арифметические операции с объектами класса bMoney, 
* выполняя те же операции с его long double данными.
* Убедитесь, что программа main() запросит ввод пользователем двух де- нежных строк и числа с плавающей точкой. 
* Затем она выполнит все пять операций и выведет результаты. Это должно происходить в цикле, так, чтобы пользователь мог ввести еще числа, если это понадобится.
*/

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class bMoney {
    private:
        long double money; 
    public: 
        bMoney ( ): money(0.0)
        { }
        bMoney ( long double m )
        {
            money = m;
        }
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
            string str;
            cout << "Enter the value of dollars (156.5 $): ";
            getline(cin, str, '$');
            money = stold(str);
        }
        // ЬМоnеу = bMoney + ЬМоnеу 
        bMoney operator+ (bMoney t) const 
        {
            return bMoney (money + t.money);
        }
        // ЬМоnеу = bMoney - ЬМоnеу
        bMoney operator- (bMoney t) const 
        {
            return bMoney (money - t.money);
        }
        // bМоnеу = bMoney * long double (цена за единицу времени, затраченного на изделие) 
        bMoney operator* (long double t) const 
        {
            return bMoney (money * t);
        }
        // long double = bMoney / ЬМоnеу (общая цена, деленная на цену за изделие) 
        long double operator/ (bMoney t) const
        {
            return (money/t.money);
        }
        // bMoney = ЬМоnеу / long double (общая цена, деленная на количество изделий)
        bMoney operator/ (long double  t ) const
        {
            return bMoney (money/t);
        }
        // bMoney += ЬМоnеу
        bMoney operator+= (bMoney t)
        {
            money += t.money;
            return bMoney (money);
        }
        // bMoney++
        bMoney operator++ (int)
        {
            money++;
            return bMoney (money);
        }
        // -bMoney
        bMoney operator- (void)
        {
            cout << "-bMoney case" << endl;
            return bMoney (-money);
        }
};


int main()
{
    bMoney m1, m2, m3;
    long double num;
    char ans;

    do
    {
        m1.putmoney();
        m2.putmoney();

        // 1 ЬМоnеу = bMoney + ЬМоnеу 
        cout << "m3 = m1 + m2" << endl;
        m3 = m1 + m2;
        m3.getmoney();

        // 2 ЬМоnеу = bMoney - ЬМоnеу
        cout << "m3 = m1 - m2" << endl;
        m3 = m1 - m2;
        m3.getmoney();

        // 3 bМоnеу = bMoney * long double (цена за единицу времени, затраченного на изделие) 
        num = 2;
        cout << "m3 = m1 * num(2)" << endl;
        m3 = m1 * num;
        m3.getmoney();

        // 4 long double = bMoney / ЬМоnеу (общая цена, деленная на цену за изделие) 
        cout << "num = m1 / m2" << endl;
        num = m1 / m2;
        cout << "num: " << num << endl;

        // 5 bMoney = ЬМоnеу / long double (общая цена, деленная на количество изделий)
        num = 5;
        cout << "m3 = m1 / num(5)" << endl;
        m3 = m1 / num;
        m3.getmoney();

        // -----------------------------------------------

        // 6 ЬМоnеу += ЬМоnеу 
        cout << "m3 += m2" << endl;
        m3 += m2;
        m3.getmoney();

        // 7 ЬМоnеу ++ 
        cout << "m3++" << endl;
        m3++;
        m3.getmoney();

        // 8 -ЬМоnеу
        cout << "-m3" << endl;
        m3 = -m3+m3;
        m3.getmoney();


        cout  << endl << "continue? (y/n)" << endl;
        cin >> ans;
    } while (ans != 'n');

    return 0;                                                  
}

