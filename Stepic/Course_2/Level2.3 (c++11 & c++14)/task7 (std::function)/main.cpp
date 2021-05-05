#include <iostream>
#include <functional>

/*
    std::function - обвертка которая позволяет универсальным способом  хранить указатель на функции, методы и 
    функциональные обьекты(обьекты с перегруженым оператором круглые скобки)
*/

int mult(int a, int b) {return a*b;}

struct IntDiv
{
    int operator()(int a, int b) const
    {
        return a/b;
    }
};



int main(int argc, const char * argv[]) 
{   
    std::function<int (int, int)> op;

    op = &mult;
    std::cout << "2*2= " << op(2,2) << std::endl;

    op = IntDiv();
    std::cout << "4/2= " << op(4,2) << std::endl;

    return 0;
}