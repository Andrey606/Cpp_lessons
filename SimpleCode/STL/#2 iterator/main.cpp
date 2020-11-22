#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "ru");
 
    vector<int> myVector = {1,9,44,422,676,78};

    vector<int>::iterator it;

    it = myVector.begin();

    cout << *it << endl; // [0]=1

    *it = 100;

    cout << *it << endl; // [0]=100

    it++;

    cout << *it << endl; // [1]=9
    cout << it[1] << endl; // [1+1]=44

    cout << endl << endl;

    for (vector<int>::iterator it2 = myVector.begin(); it2!=myVector.end(); it2++)
    {
        cout << *it2 << endl;
    }

    cout << endl << endl;

    // константный итератор, не позволяет модиицировать данные
    for (vector<int>::const_iterator it2 = myVector.cbegin(); it2!=myVector.cend(); it2++)
    {
        cout << *it2 << endl;
    }

    cout << endl << endl;

    // реверсный итератор, позволяет перебирать масив с конца в начало
    for (vector<int>::reverse_iterator it2 = myVector.rbegin(); it2!=myVector.rend(); it2++)
    {
        cout << *it2 << endl;
    }

    cout << endl << endl;

    // сдвигает итератор на какоето кол-во элементов
    cout << *it << endl;
    advance(it, 2);
    cout << *it << endl;

    cout << endl << endl;

    vector<int> myVector2 = {1,9,44,422,676,78};
    vector<int>::iterator it3 = myVector2.begin();

    for (vector<int>::iterator it2 = myVector2.begin(); it2!=myVector2.end(); it2++)
    {
        cout << *it2 << endl;
    }

    cout << endl << endl;

    myVector2.insert(it3, 5);

    for (vector<int>::iterator it2 = myVector2.begin(); it2!=myVector2.end(); it2++)
    {
        cout << *it2 << endl;
    }

    cout << endl << endl << "erase"<<endl;
    
    vector<int>::iterator itErase = myVector2.begin();
    myVector2.erase(itErase);

    for (vector<int>::iterator it2 = myVector2.begin(); it2!=myVector2.end(); it2++)
    {
        cout << *it2 << endl;
    }

    return 0;
}