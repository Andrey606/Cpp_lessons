#include <iostream>
#include <set>

/*
    контейнери map и set отсортированые и если ты хочешь
    использовать свой тип данных для хранение нужно определить оператор сравнение чтобы контейнер 
    мог сортировать данные
*/

struct Person {std::string name; std::string surname;};

bool operator<(Person const& a, Person const& b)
{
    return a.name < b.name || (a.name == b.name && a.surname < b.surname);
}

// также можно передать в контенер метод сравнения
struct PersonComp{
    bool operator()(Person const& a,
                    Person const& b) const {
                        return a.surname < b.surname;
                    }
};

int main(int argc, const char * argv[]) 
{
    // SET
    std::set<Person> primes = {{"Andrew", "Kuluew"}};

    // а тут будет сортировка только по фамилии
    std::set<Person, PersonComp> primes2 = {{"Andrew", "Kuluew"}};


    return 0;
}