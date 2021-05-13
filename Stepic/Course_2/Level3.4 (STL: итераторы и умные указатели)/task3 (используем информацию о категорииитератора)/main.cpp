#include <iostream>
#include <iterator>
#include <vector>
#include <list>


template<class It, class Tag>
void advance_impl(It& it, size_t n, Tag tag) 
{
    std::cout << "advance_impl for any iterator" << std::endl;
    for (size_t i = 0; i < n; ++i) it++;
}

template<class It>
void advance_impl(It& it, size_t n, std::random_access_iterator_tag)
{  
    std::cout << "advance_impl for random_access_iterator_tag" << std::endl;
    it += n; 
}

template<class It>
void madvance(It& it, size_t n)
{ 
    // std::iterator_traits<It>::iterator_category() - определяет категорию итератора и взависимости от этого вызывает 
    // нужную перегрузку
    std::cout << "advance" << std::endl;
    advance_impl(it, n, typename std::iterator_traits<It>::iterator_category()); 
}

void print(std::list<int>::iterator it1, std::list<int>::iterator it2)
{
    std::cout << "list: ";
    for (; it1 != it2; ++it1)
    {
        std::cout << *it1;
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) 
{
    std::list<int> l1 = {1,2,3,4,5,6,7,8,9};
    auto it1 = l1.begin();
    madvance(it1, 2); // for any iterator

    std::vector<int> v = {1,2,3,4,5,6,7,8,9};
    auto it2 = v.begin();
    madvance(it2, 2); // for random_access_iterator_tag

    std::cout << std::endl; std::cout << std::endl;


    // #2 двигаем итераторы
    std::list<int> l = {1,2,3};
    l.insert(l.begin(), 4); // 4 1 2 3
    l.insert(l.end(), 5); // 4 1 2 3 5
    print(l.begin(), l.end());


    auto it = l.begin();// >4 1 2 3 5
    ++it; // 4 >1 2 3 5
    ++it; // 4 1 >2 3 5
    l.insert(it, 6); // 4 1 6 >2 3 5
    print(l.begin(), l.end());

    auto rit1 = l.rbegin(); // 4 1 6 2 3 >5
    ++rit1; // 4 1 6 2 >3 5
    ++rit1; // 4 1 6 >2 3 5
    l.insert(rit1.base(), 7); // 4 1 6 >2 7 3 5
    print(l.begin(), l.end());

    auto rit2 = l.rbegin(); // 4 1 6 2 7 3 >5
    ++rit2; // 4 1 6 2 7 >3 5
    ++rit2; // 4 1 6 2 >7 3 5
    l.insert(rit2.base(), 8); // 4 1 6 2 >7 8 3 5
    print(l.begin(), l.end());

    return 0;
}