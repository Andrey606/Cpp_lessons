#include <iostream>

using namespace std;

/*
    правила склеек ссылок 

    * T& + & -> T&
    * T& + && -> T&
    * T&& + & -> T&
    * T&& + && -> T&&
    
    * T + && -> T&&
*/

// * если вызов foo от lvalue типа A, то Т = A& -> (A& + && = A&)
// * если вызов foo от rvalue типа A, то Т = A -> (A + && = A&&)
template<typename T>
void foo(T && t)
{

}


int main(int argc, const char * argv[]) 
{


    return 0;
}