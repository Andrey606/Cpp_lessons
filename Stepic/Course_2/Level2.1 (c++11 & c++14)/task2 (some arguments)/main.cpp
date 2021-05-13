#include <iostream>
#include <string>
#include <typeinfo>

/*

функции с (...) имеют наименший аргумент при перегрузке

По аналогии с функцией printf с предыдущего степа напишите функцию print_values с переменным числом аргументов, 
которая для каждого аргумента выводит его тип и значение в поток std::ostream, который ей передан в качестве первого аргумента. 
Функция должна работать с произвольным числом аргументов.
Указание: для вывода имени типа нужно использовать std::type_info::name.
Например, вызов функции
print_values(std::cout, 0, 3.5, "Hello");
должен вывести на стандартный вывод примерно следующее (таким будет вывод на g++).
i: 0
d: 3.5
PKc: Hello

Примечание: в этой и следующих задачах на программирование будет использоваться стандарт C++11. 
Если вы захотите решать задачи локально, то не забудьте включить поддержку стандарта C++11 в вашем компиляторе. 
Например, в g++ и clang++ поддержка С++11 включается при помощи следующего параметра командной строки: -std=c++11.

Внимание: выводить нужно в поток os, а не в std::cout!

*/

// #2 test print_values
void print_values(std::ostream & os){}
template <typename T, typename... Args>
void print_values(std::ostream & os, const T& value, const Args&...args)
{
    // я ебу почему он рекурсивно не продолжает вызываться когда даже аргументы кончаются, но оно работает!
    os << typeid(value).name() << ": " << value << std::endl;
    print_values(os, args...); // args_... (args_ = 10, 2, 5) -> print_values(os, 10, 2, 5);
}

 // #1 test read
void read() {} // какойто хитрый трюк чтобы компилятор не ругался когда передаем один аргумент при рекурсии
template <typename T, typename... Args>
void read(T& value_, Args& ...args_) {
    std::cin >> value_;
    read(args_...);
}

void read(int& value_, int& ...args_) = delete; // метод read с этим набором аргументов будет удален

int main(int argc, const char * argv[]) 
{
    // #1 test read
    /*int a, b;
    double c, d;
    std::string s1, s2;
    read(a, b, c, d, s1, s2);
    //~ std::cin >> a >> b >> c >> d >> d >> s1 >> s2
    std::cout << "a = " << a << '\n'
              << "b = " << b << '\n'
              << "c = " << c << '\n'
              << "d = " << d << '\n'
              << "s1 = " << s1 << '\n'
              << "s2 = " << s2 << '\n';*/

    // #2 test print_values
    print_values(std::cout, 0, 3.5, "Hello");

    return 0;
}