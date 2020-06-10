/*
* static_cast
*/
#include <iostream>

using namespace std;


struct Number {};

struct BigInt : Number
{
    BigInt(long int x): x_(x) {}

private:
    long int x_;
};

struct String
{
    explicit String(char const * s)
    {
        str = s;
    }

    char const *str;
};


int main(int argc, const char * argv[]) {
    
    int a = static_cast<int>(3.5);
    int a2 = 3.5;
    cout << typeid(a).name() << endl;
    cout << typeid(a2).name() << endl;

    double b = static_cast<double>(7);
    double b2 = 7;
    cout << typeid(b).name() << endl;
    cout << typeid(b2).name() << endl;

    BigInt c = static_cast<BigInt>(100500);
    BigInt c2 = 100500;
    cout << typeid(c).name() << endl;
    cout << typeid(c2).name() << endl;

    String d = static_cast<String>("Stepik");
    // String d2 = "Stepik"; // из за explicit не будет работать
    String d2("Stepik");
    cout << typeid(d).name() << endl;
    cout << typeid(d2).name() << endl;

    Number * e = static_cast<Number *>(&c);
    Number * e2 = &c;
    cout << typeid(e).name() << endl;
    cout << typeid(e2).name() << endl;

    BigInt * f = static_cast<BigInt *>(e);
    //BigInt * f2 = e; от базовог к следующему не работает
    cout << typeid(f).name() << endl;
    //cout << typeid(f2).name() << endl;

    void * g = static_cast<void *>(f);
    void * g2 = f;
    cout << typeid(g).name() << endl;
    cout << typeid(g2).name() << endl;

    BigInt * h = static_cast<BigInt *>(g);
    //BigInt * h2 = g;
    cout << typeid(h).name() << endl;
    //cout << typeid(h2).name() << endl;

    return 0;
}