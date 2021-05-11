#include <iostream>
#include <unordered_map>

/*
    unordered_map хранит множество как хеш-таблицу
    Операция добавления, удаления и поиска работают за O(1) в среднем
    Значения которые хранятся в unordered_map неизменяемые (можно удалить старое и добавить новое)

    * equal_range reserve  operator at
    * методы для работы с хеш таблицей
*/
    

int main(int argc, const char * argv[]) 
{
    std::unordered_map<std::string, int> phonebook;
    phonebook.emplace("Marge", 2128506);
    phonebook.emplace("Lisa", 2128503);
    phonebook.emplace("Bart", 2128503);
    // std::map<string,int>::iterator
    auto it = phonebook.find("Maggie");
    if(it != phonebook.end())
        std::cout << "Maggie: " << it->second << "\n";
    else
        phonebook["Maggie"] = 2128503;

    std::unordered_multimap<std::string, int> phonebook2; 
    phonebook2.emplace("Lisa", 2128503);
    phonebook2.emplace("Lisa", 2128503);  

    return 0;
}