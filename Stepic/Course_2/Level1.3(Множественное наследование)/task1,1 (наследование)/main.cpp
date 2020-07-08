/*
* Множественное наследование
*/
#include <iostream>

using namespace std;

struct A
{
    A(){}
};

//Make B inherit publicly (default) from A
struct B : A
{   
public:
    B(int a, int b):a(a), b(b){}
    B():a(), b(){}
    int a;
    int b;

} BObj = {1, 2};

int main(int argc, const char * argv[]) {
    B a = {};


    return 0;
}

