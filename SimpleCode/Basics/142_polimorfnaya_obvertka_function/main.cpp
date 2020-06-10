/*
* std::function | Полиморфная обёртка функции | Изучение С++ для начинающих. Урок #142
+ std::function
* что то похожее на указатель на функцию но из мира ооп
*/

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

void Foo(int a)
{
    if(a > 10 && a < 40)
    {
        cout << "Foo: " << a << endl;
    }
}

void Bar(int a)
{
    if(a % 2 == 0)
    {
        cout << "Bar: " << a << endl;
    }
}

void DoWork(vector<int> &vc, function<void(int)> f)
{
    for(auto el : vc)
    {
        f(el);
    }
}

void DoWork2(vector<int> &vc, vector<function<void(int)>> &fArray)
{
    for(auto f : fArray)
    {
        for(auto el : vc)
        {
            f(el);
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "ru");

    vector<int> vc = { 1, 51, 4, 10, 44, 98, 22, 29, 56 };
    
    cout << "==== #1" << endl;

    DoWork(vc, Foo);
    DoWork(vc, Bar);

    cout << "==== #2" << endl;

    vector<function<void(int)>> fArr = { Foo, Bar };
    DoWork2(vc, fArr);
    
    return 0;
}