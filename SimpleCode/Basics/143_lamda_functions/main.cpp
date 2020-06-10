/*
* Лямбда-выражения | Лямбда функции | Анонимные функции | Изучение С++ для начинающих. Урок #143
*/

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <functional>

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

    // 201402 - 14 стандарт
    cout << "cтандарт C++: " << __cplusplus << endl << endl;

    vector<int> vc = {10, 5};
    function<void(int)> f;

    // #1 =========================
    cout << "#1 =========================" << endl;
    // анонимная/лямда функция, она не вызываеться сама по себе
    f = [](int a) 
    {
        cout << "вызвана анонимная функция с параметром - " << a << endl;
    };

    DoWork(vc, f);

    // #2 =========================
    cout << "#2 =========================" << endl;
    /* чтобы не создавать функции мы можем передавать одноразовые функции прямо в вызове */
    DoWork(vc, [](int a) { cout << "вызвана анонимная функция с параметром - " << a << endl; });

    // #3 =========================
    cout << "#3 =========================" << endl;
    int p = 0;
    // теперь переменую можно использовать внутри лямда функции
    // в 14 стандарте добавили возможность ссылаться на анонимные функции с ключевым словом auto
    auto f2 = [&p]() 
    {
        p = 5;
    };

    f2();

    cout << "p: " << p << endl;

    // #4 =========================
    cout << "#4 =========================" << endl;
    auto f3 = []() 
    {
        return 1;
    };

    auto q = f3();

    cout << "q: " << q << endl;
  
    return 0;
}