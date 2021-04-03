#include <iostream>

using namespace std;

/*При помощи typedef определите тип ComplexFunction, который является 
указателем на функцию, которая принимает int и указатель на функцию, принимающую double
 и возвращающую int, и возвращает указатель на функцию, которая принимает char const * и возвращает int *.*/

typedef auto (* ComplexFunction)(int, auto (*)(double) -> int) -> auto (*)(char const *) -> int *;

// или 

typedef int * (*(*ComplexFunction)(int, int (*)(double))) (char const*);


int main(int argc, const char * argv[]) 
{
    //std::cout << *mainFunc(2, argFunc)("") << std::endl;

    return 0;
}