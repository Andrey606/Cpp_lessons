#include <iostream>
#include <array>

/*
    std::array - не позволяет изменять свой размер динамически 
    это обвертка над обычным масивом

    оператор [], at() - at выдает ошибку если выйти за граници масива которую можно отлавить в отличии от оператора
    back, front - получить первый и последний элемент
    fill - позволяет заполнить масив
    data - позволяет получить указатель на первый элемент
*/

int main(int argc, const char * argv[]) 
{
    std::array<std::string, 3> a = {"One", "Two", "Three"};
    std::cout << a.size() << std::endl;
    std::cout << a[1] << std::endl;

    // ошибка времени выполнения
    std::cout << a.at(3) << std::endl;

    return 0;
}