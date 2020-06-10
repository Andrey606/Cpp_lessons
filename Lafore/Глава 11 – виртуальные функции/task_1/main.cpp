/*
*
* Напишите программу, которая принимает группу чисел от пользователя и помещает их в массив типа float. 
* После того как числа будут помещены в массив, программа должна подсчитать их среднее арифметическое и вывес- ти 
* результат на дисплей. Используйте указатели везде, где только возможно.
*
*/

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;


int main()
{
    float array[5];

    for (size_t i = 0; i < 5; i++)
    {
        cin >> array[i];
    }

    float num;

    for (size_t i = 0; i < 5; i++)
    {
        num += *(array+i);
    }

    cout << "number is: " << num << endl;
    

    return 0;                                              
}

