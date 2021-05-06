#include <iostream>
#include <vector>

/*
    оператор [], at() - at выдает ошибку если выйти за граници масива которую можно отлавить в отличии от оператора
    resize
    capasity, reserve, shrink_to_fit
    pop_back
    data
*/

void legacy_function(std::string *p, size_t size)
{

}

int main(int argc, const char * argv[]) 
{
    std::vector<std::string> v = {"One", "Two"};
    v.reserve(100); // зарезервировать буфер на 100 строк
    v.push_back("Three"); // добавляем новую строку (сначала создаем времменый обьект std::string("Three"), и только потом он передасться в масив)
    v.emplace_back("Four"); // добавляем новую строку (сразу "Four" передаем в масиы)
    legacy_function(v.data(), v.size());
    std::cout << v[2] << std::endl;

    return 0;
}