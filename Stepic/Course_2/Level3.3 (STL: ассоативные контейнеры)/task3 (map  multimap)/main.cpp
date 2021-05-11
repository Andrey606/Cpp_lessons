#include <iostream>
#include <map>

/*
    упорядоченный ачоативный контейнер 
    операция добавления удаления и поиска работают за O(log(n))
    Значения которые хранятся в unordered_set неизменяемые (можно удалить старое и добавить новое)

    для хранений используется двоичное сбалансированое дерево поиска

    typedef std::pair<const Key, T> value_type;

    * lower bound upper_bound equal_range
    * operator[] at()
*/

/*
    Метод operator[]:
    1. работает только с неконстантным map
    2. требует наличие у T констуктора по умолчанию
    3. работает за O(log(n))(не стоит использовать map как масив)

    Метод at():
    1. генерит ошибку времени выполнения, если такой ключ отсутстувует
    2. работает за O(log(n)
*/
    

int main(int argc, const char * argv[]) 
{
    std::map<std::string, int> phonebook;
    phonebook.emplace("Marge", 2128506);
    phonebook.emplace("Lisa", 2128503);
    phonebook.emplace("Bart", 2128503);
    // std::map<string,int>::iterator
    auto it = phonebook.find("Maggie");
    if(it != phonebook.end())
        std::cout << "Maggie: " << it->second << "\n";
    else
        phonebook["Maggie"] = 2128503;

    std::multimap<std::string, int> phonebook2; 
    phonebook2.emplace("Lisa", 2128503);
    phonebook2.emplace("Lisa", 2128503);  

    return 0;
}