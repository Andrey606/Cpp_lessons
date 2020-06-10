/*
*
* Напишите функцию reversit(), которая переворачивает строку (массив типа char). Используйте цикл for, 
* который меняет местами первый и последний символы, затем следующие и т. д. до предпоследнего. 
* Строка должна пере- даваться в функцию reversit() как аргумент.
* Напишите программу для выполнения функции reversit(). 
* Программа долж- на принимать строку от пользователя, вызывать функцию reversit(), а за- тем выводить полученный результат. 
* Используйте метод ввода, который позволяет использовать внутренние пробелы. 
* Протестируйте программу на примере фразы «Аргентина манит негра».
*
*/

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

void reversit(char arr[]);

const int MAX = 100;

int main()
{
    char array[MAX] = {0};
    cout << "Enter the string: "; cin.get(array, MAX);

    cout << array << endl;

    reversit(array);

    return 0;                                                  
}

void reversit(char arr[])
{
    char buff[MAX] = {0};

    cout << "size of str: " << strlen(arr) << endl;

    for (size_t i = 0; i < strlen(arr); i++)
    {
        cout << arr[(strlen(arr)-1)-i] << endl;
        buff[i] = arr[(strlen(arr)-1)-i];
    }
    
    cout << buff << endl;
}