/*
* обработка исключений
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string path = "wmyFile.txt";


int main() 
{
    setlocale(LC_ALL, "ru");

    ifstream fin;
    fin.exceptions(ifstream::badbit | ifstream::failbit); // включаем обработку исключений в классе ifstream

    try
    {
        cout << "Попытка открыть файл!" << '\n';

        fin.open(path);

        cout << "Файл успешно открыт!" << '\n';
    }
    catch(const ifstream::failure& e)
    {
        cout << e.what() << '\n';
        cout <<  e.code() << endl;
        cout << "Ошибка открытия файла!" << '\n';
    }
    

    return 0;
}