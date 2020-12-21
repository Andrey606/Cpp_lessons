#include <iostream>
#include <vector>
#include <list>

using namespace std;

// rvalue - (временный обьект) то где нет указателя и обично это временые значение (передаваемые куда-то)
/*
* string('hello')
* int(2)
*/

// lvalue - то у кого можно взять ссылку или указатель
/*
* int i = 0;
* 
*/

// && -  rvalue ссылка, 
/*
* data(string &&str)
* { 
*
* }
*
* data(string("hello"));
*/

// rvalue ссылка и rvalue, позволяет оптимизировать код с С++11.

int main() 
{
    setlocale(LC_ALL, "ru");
 
    
  
    return 0;
}