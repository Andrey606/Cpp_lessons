#include <iostream>
#include <deque>

/*
    deque - похож на вектор но он позволяет добавлять новые елементы не только в конец но и начало масива,
    с ефективностью O(1)
    реализован как std::list как список указателей на масивы фиксированого размера
    
    и доступ к елементам с такой же скоростью что и в List
*/


int main(int argc, const char * argv[]) 
{
    std::deque<std::string> d = {"One", "Two"};
    d.emplace_back("Three"); 
    d.emplace_front("Zero"); 
    std::cout << d[1] << std::endl;

    return 0;
}