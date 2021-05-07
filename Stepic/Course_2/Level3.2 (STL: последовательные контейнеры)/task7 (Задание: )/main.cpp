#include <iostream>
#include <list>

/*
    Напишите функцию max_increasing_len, которая принимает последовательность, хранящуюся в std::list, 
    по двум итераторам, и вычисляет для неё длину самого длинного строго возрастающего подотрезка.

    Пример:

    std::list<int> const l1 = {7,8,9,4,5,6,1,2,3,4};
    size_t len1 = max_increasing_len(l1.begin(), l1.end()); // 4, соответствует подотрезку 1,2,3,4

    std::list<int> const l2 = {-3,-2,-1,0,0,1,2,3,4,5};
    size_t len2 = max_increasing_len(l2.begin(), l2.end()); // 6, соответствует подотрезку 0,1,2,3,4,5
*/

// так как в задании не указан тип элементов,
// которые хранятся в списке, то давайте сделаем
// эту функцию шаблонной
// Параметр It — это тип итератора 
template<class It>
size_t max_increasing_len(It p, It q)
{
    size_t tmp_max_increasing_len = 0;
    size_t max_increasing_len = 0;

    --q;
    for (; p != q; ++p)
    {
        auto nextIt = p; ++nextIt;
        bool flag = false;

        std::cout << *p <<  "<" << *nextIt << "=" << (*p < *nextIt) << " | ";

        if(*p < *nextIt)
        {
            max_increasing_len++;
        }
        else
        {
            if(tmp_max_increasing_len < max_increasing_len)
                tmp_max_increasing_len = max_increasing_len;

            max_increasing_len=0;
        }
    }
    
    if(tmp_max_increasing_len < max_increasing_len)
        return ++max_increasing_len;
    else    
        return ++tmp_max_increasing_len;
}

int main(int argc, const char * argv[]) 
{
    std::list<int> const l1 = {7,8,9,4,5,6,1,2,3,4};
    size_t len1 = max_increasing_len(l1.begin(), l1.end()); // 4, соответствует подотрезку 1,2,3,4
    std::cout << "len1: " << len1 << std::endl;

    std::list<int> const l2 = {-3,-2,-1,0,0,1,2,3,4,5};
    size_t len2 = max_increasing_len(l2.begin(), l2.end()); // 6, соответствует подотрезку 0,1,2,3,4,5
    std::cout << "len2: " << len2 << std::endl;

    return 0;
}