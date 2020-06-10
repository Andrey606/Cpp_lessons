/*
* reinterpret_cast
*/
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) 
{
    // ниже так же работает и с сылками
    double *double_array = new double[100];
    cout << typeid(double_array).name() << endl;

    char *char_array = reinterpret_cast<char *>(double_array);
    cout << typeid(char_array).name() << endl;

    // можно преобразовать число в указатель и наоборот
    size_t ms = reinterpret_cast<size_t>(double_array);

    return 0;
}