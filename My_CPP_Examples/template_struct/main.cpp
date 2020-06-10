#include <iostream>

using namespace std;

template <class T>
struct A
{
  T e;
  T e1;
};

int main()
{
  A<int> a = {2, 10};
  A<double> b = {2.5, 6.8};

  cout << "a<int>: " << a.e << endl;
  cout << "a<double>: " << b.e << endl;
}
