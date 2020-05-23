/*
* Умные указатели. Smart pointers. Изучение С++ для начинающих. Урок #130
*/

#include <iostream>

using namespace std;

template<typename T>
class SmartPointer
{
public:
    SmartPointer(T *ptr)
    {
        this->ptr = ptr;
        cout << "Constructor" << endl;
    }
    ~SmartPointer()
    {
        delete ptr;
        cout << "Destructor" << endl;
    }
    T& operator*()
    {
        return *ptr;
    }

private:
    T *ptr;
};


int main() 
{
    setlocale(LC_ALL, "ru");

    int *ptr = new int(5);
    cout << *ptr << endl;
    delete ptr;

    SmartPointer<int> ptr2 = new int(500);
    cout << *ptr2 << endl;
    *ptr2 = 20;
    cout << *ptr2 << endl;
   
    return 0;
}