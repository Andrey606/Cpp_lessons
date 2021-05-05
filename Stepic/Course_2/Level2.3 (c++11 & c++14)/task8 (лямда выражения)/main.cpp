#include <iostream>
#include <functional>

/*
    
*/

std::function<int (int, int)> op = [](int x, int y) { return x*y; };


int main(int argc, const char * argv[]) 
{   
    op = [](int x, int y) -> int { return x/y; };

    // c++14
    op = [](auto x, auto y) -> int { return x/y; };


    int total=0;
    // захват по ссылке
    auto addTotal = [&total](int x) { total+=x; };

    // захват по ссылке
    auto subTotal = [total](int &x) { x-=total; };

    // можно захватить this(если это метод класса)
    //auto callUpdate = [this]() { this->x += 5; }; 

    return 0;
}

// различные виды захвата в лямда выражениях
/*
    [], [x, &y], [&], [=], [&, x], [=, &z]:
        [] - без захвата
        [x, &y] - x gпо значению, а y - по ссылке
        [&] - захват всех по ссылке
        [=] - захват всех по значению
        [&, x] - все по ссылке а x - по значению
        [=, &z] - все по значению а z - по ссылке

    перемещающий захват - [x = std::move(y)] // (только в с++14)

    !! не стоит использовать завхват по умолчанию  [&] или [=]
*/