#include <iostream>
#include <list>

/*
    list - двухсвязный списокю В любом месте контейнера вставка и удаление производится за O(1)

    * push_front, emplase_front - добавление елементов в начало
    * pop_back, pop_front - удаление елементов с начала и с конца
    * splice - позволяет вырезать куски из одного списка и вставлять их в другой
    * merge, remove, remove_if, reverse, sort, unique - набор алгоритмов
    * 
    * у списка отсутствует доступ к елементам по индексу
*/


int main(int argc, const char * argv[]) 
{
    std::list<std::string> l = {"One", "Two"};
    l.emplace_back("Three"); 
    l.emplace_front("Zero"); 
    std::cout << l.front() << std::endl<< std::endl;

    using std::string;
    for(string &s : l)
    {
        std::cout << s << std::endl;
    }

    // для болле сложных операций нужно использовать итераторы
    std::cout  << std::endl;
    std::list<string>::iterator i = l.begin();
    for (; i != l.end(); ++i)
    {
        if (*i == "Two")
        {
            break;
        }
        
    }
    l.erase(i);

    for(string &s : l)
    {
        std::cout << s << std::endl;
    }

    // итератор списка можно перемещать в обоих направлениях
    auto last = l.end();
    --last;

    return 0;
}