#include <iostream>
#include <tuple>

/*
    в новом стандарте появился новый цикл for для работы с последовательгостями

    !! работает для всех типов где реализовано begin() и end()
    !! для пользовательських типов нужно вручную реализовать этот цикл
*/

int arry[] = {1,2,3,4,5};


int main(int argc, const char * argv[]) 
{   
    // позначению 
    for(int i : arry)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;


    // по ссылке 
    for(int &i : arry)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}