/*
* Напишите программу, использующую структуру sterling, которая описана в упражнении 10 главы 4. 
* Программа должна получать от пользователя значения двух денежных сумм, выраженных в фунтах, 
* шиллингах и пен- сах, складывать эти значения и выводить результат на экран в том же формате. 
* Необходимо разработать три функции. Первая из них должна получать от пользователя число фунтов,
* шиллингов и пенсов и возвра- щать соответствующее значение типа sterling. Вторая функция должна при- нимать 
* в качестве аргументов два значения типа sterling, складывать их и возвращать значение, также имеющее тип sterling. 
* Третья функция долж- на принимать аргумент типа sterling и выводить его значение на экран.
*/

#include <iostream>

using namespace std;

typedef struct sterling{
    int pound; // 1 pound = 240 penny
    int shilling; // 1 shilling = 12 penny
    int penny;
} sterling;

sterling pound_shilling_penny_to_sterling(int pound, int shilling, int penny);
sterling sum_sterling(sterling a, sterling b);
void print_sterling(sterling a);

int main() 
{
    sterling var1;
    cout << "Enter number of pounds: "; cin >> var1.pound;
    cout << "Enter number of shillings: "; cin >> var1.shilling;
    cout << "Enter number of penny: "; cin >> var1.penny;

    sterling var2;
    cout << "Enter number of pounds: "; cin >> var2.pound;
    cout << "Enter number of shillings: "; cin >> var2.shilling;
    cout << "Enter number of penny: "; cin >> var2.penny;

    cout << endl;

    print_sterling(var1);
    print_sterling(var2);

    cout << endl;

    sterling var3 = sum_sterling(var1, var2);
    print_sterling(var3);

    cout << endl;

    sterling var4;
    cout << "Enter number of pounds: "; cin >> var4.pound;
    cout << "Enter number of shillings: "; cin >> var4.shilling;
    cout << "Enter number of penny: "; cin >> var4.penny;
    sterling var5 = pound_shilling_penny_to_sterling(var4.pound, var4.shilling, var4.penny);
    print_sterling(var5);

   
    return 0;
}

sterling pound_shilling_penny_to_sterling(int pound, int shilling, int penny)
{
    sterling var = {pound, shilling, penny};
    return var;
}

sterling sum_sterling(sterling a, sterling b)
{
    sterling var;

    long var2 = (a.penny + b.penny) + ((a.shilling+b.shilling)*12) + ((a.pound+b.pound)*240);

    var.pound = var2/240;
    var.shilling = (var2-(var.pound*240))/12;
    var.penny = var2-(var.pound*240)-(var.shilling*12);

    return var;
}

void print_sterling(sterling a)
{
    cout <<  "pound : " << a.pound << endl; 
    cout <<  "shilling : " << a.shilling << endl;
    cout <<  "penny : " << a.penny << endl; 
}