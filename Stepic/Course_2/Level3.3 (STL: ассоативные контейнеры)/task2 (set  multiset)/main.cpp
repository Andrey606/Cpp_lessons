#include <iostream>
#include <set>

/*
    set хранит упорядоченное множество (как двоичное дерево поиска).
    Операции добавления, удаления и поиска работают за O(log n).
    Значения которые хранятся в unordered_set неизменяемые (можно удалить старое и добавить новое)
        * lower_bound, upper_bound, equal_range

    set реализован при помощи сбалансированного двоичного дерева поиска (красно-черного дерева), поэтому множества в STL хранятся в виде упорядоченной структуры, 
    что позволяет перебирать элементы множества в порядке возрастания их значений. 
*/

int main(int argc, const char * argv[]) 
{
    // SET
    std::set<int> primes = {2, 3, 5, 173, 7, 11};
    // дальнеейшее заполнение
    if (primes.find(173) != primes.end())
        std::cout << 173 << " is prime\n";

    // std::pair<iterator, bool>
    auto res = primes.insert(3); // если успешно добавлен то будет вернута пара с значением итератора и булл с статусом


    // MULTI SET
    std::multiset<int> fib = {2,2,2, 3, 5, 173, 7, 11};
    
    // iterator
    auto res = fib.insert(13);

    // pai<iterator, iterator>
    auto res = fib.equal_range(1);

    

    return 0;
}