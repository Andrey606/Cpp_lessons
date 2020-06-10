#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum FAMILY {MAMA=1, PAPA=2, BABUSHKA=3, SYNOK=4};
vector<FAMILY> array1(0);
vector<FAMILY> array2(0);

void init(void)
{
    array1.push_back(MAMA);
    array1.push_back(PAPA);
    array1.push_back(BABUSHKA);
    array1.push_back(SYNOK);
}

void obratno(vector<FAMILY> array, FAMILY index)
{
    for (size_t k = 0; k < array2.size(); k++)
    {
        
    }
}

void tuda(void)
{
    for (size_t i = 0; i < array1.size(); i++)
    {
        for (size_t j = 0; j < array1.size(); j++)
        {
            if(i==j)
                continue;
            
            cout << "i: " << array1[i] << " j: " << array1[j] << endl;

            array2.push_back(static_cast<FAMILY>(i));
            array2.push_back(static_cast<FAMILY>(j));

            for (size_t k = 0; k < array2.size(); k++)
            {

            }
        }
    }
}

int main() 
{
    init();

    tuda();
    
    return 0;
}