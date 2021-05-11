#include <iostream>
#include <unordered_set>

/*
    чтобы определить свой ключ нужно:
    - определить оператор на равенство
    - определить хеш-функцию
*/

struct Person {std::string name; std::string surname;};

bool operator==(Person const& a, Person const& b)
{
    return a.name == b.name && a.surname < b.surname;
}

// по умолчанию внутри не упорядоченных асоативных контейнеров используется шаблонный класс std::hash
// для того чтобы реализовать std::hash для своего пользовательского класса нам нужно специализировать std::hash
namespace std 
{
    template <> 
    struct hash<Person> 
    {
        size_t operator()(Person const& p) const 
        {
              hash<string> h;
              return h(p.name) ^ h(p.surname);
        }
    };
}

int main(int argc, const char * argv[]) 
{
    // уникальны по сочетанию имя + фамилия
    std::unordered_set<Person> primes = {{"Andrew", "Kuluew"}};

    std::hash<std::string> h;

    std::cout << (( h("Dennis") ^ h("Straustrup") ) == ( h("Bjarne") ^ h("Ritchie") )) << std::endl;

    return 0;
}