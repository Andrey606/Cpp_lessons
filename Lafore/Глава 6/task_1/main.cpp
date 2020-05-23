/*
* Создайте класс Int, имитирующий стандартный тип int. Единственное поле этого класса должно иметь тип int.
* Создайте методы, которые будут устанавливать значение поля, равным нулю, инициализировать его целым значением, 
* выводить значение поля на экран и складывать два значения типа Int.
* Напишите программу, в которой будут созданы три объекта класса Int, два из которых будут инициализированы. 
* Сложите два инициализирован- ных объекта, присвойте результат третьему, а затем отобразите результат на экране.
*/

#include <iostream>
#include <iomanip>

using namespace std;

class Int
{
    private:
        int var;
    public:
        Int() : var(0) 
        {}
        Int(int value) : var(value) 
        {}

        void print_value(void) const;
        int get_value(void) const;
        void set_value(int);
        Int add_number(const Int&) const;
};

void Int::print_value(void) const
{
    cout << "number is: " << var << endl;
}

int Int::get_value(void) const
{
    return var;
}

void Int::set_value(int value=0)
{
    var = value;
}

Int Int::add_number(const Int& number) const
{
    Int temp(number.var + var); // временная переменная

    return temp;
}

int main()
{
    Int number1(15);
    Int number2(10);
    Int number3;

    number1.print_value();
    number2.print_value();
    number3.print_value();

    number3 = number1.add_number(number2);

    number1.print_value();
    number2.print_value();
    number3.print_value();

    return 0;                                                  
}