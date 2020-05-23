/*
RTTI - run-time type information
* reinterpret_cast
*/
#include <iostream>

using namespace std;

struct Unit
{
    virtual ~Unit() {}
};

struct Elf: Unit {};

int main(int argc, const char * argv[]) 
{
    Elf e;
    Unit &ur = e;
    Unit *up = &e;
 
    cout << typeid(ur).name() << endl; // Elf
    cout << typeid(*up).name() << endl; // Elf
    cout << typeid(up).name() << endl; // Unit
    cout << typeid(Elf).name() << endl; // Elf
    cout << (typeid(ur) == typeid(Elf)) << endl; // 1

    return 0;
}