#include <iostream>
#include <unordered_set>

/*
    unordered_set хранит множество как хеш-таблицу
    Операция добавления, удаления и поиска работают за O(1) в среднем
    Значения которые хранятся в unordered_set неизменяемые (можно удалить старое и добавить новое)

    * equal_range reserve
    * методы для работы с хеш таблицей
*/
    

int main(int argc, const char * argv[]) 
{
    std::unordered_set<int> primes = {2, 3, 5, 7, 11};
    // дальнейшее заполнение 
    if(primes.find(173) != primes.end())
        std::cout << 173 << "is prime\n";

    // std::pair<iterator, bool>
    auto res = primes.insert(3);

    // в  unordered_multiset хранится мулитимножество
    std::unordered_multiset<int> fib = {2, 2, 2, 3, 5, 7, 11};
    // iteratro
    auto it = fib.insert(13);

    return 0;
}