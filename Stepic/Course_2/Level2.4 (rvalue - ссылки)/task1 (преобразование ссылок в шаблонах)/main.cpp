#include <iostream>

using namespace std;

/*
    правила склеек ссылок 

    * T& & -> T&
    * T& && -> T&
    * T&& & -> T&
    * T&& && -> T&&
*/

template<typename T>
void foo(T && t)
{

}


int main(int argc, const char * argv[]) 
{


    return 0;
}