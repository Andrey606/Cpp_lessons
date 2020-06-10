// structure.cpp
// подсчет числа слов в предложении с использованием перечислений

#include <iostream>
#include <clocale> // для коректного отображения русских символов
using namespace std;
#include <conio.h> // для getche()

enum itsaWord {NO, YES}; // NO = 0, YES = 1


int main()
{
    setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали

    itsaWord isWord = NO; // isWord = YES, когда вводится слово, и NO. когда водятся пробелы
    char ch='a';
    int wordcount = 0;
    cout << "Введите предложение: \n";

    do{
        ch = getche();

        if(ch == ' '|| ch == '\r')
        {
            if(isWord == YES)
            {
                wordcount++;
                isWord = NO;
            }
        }
        else
        {
            if(isWord == NO)
               isWord = YES;
        }
    }while(ch != '\r'); // выход по нажатию на Enter

    cout << "\n---Число слов: " << wordcount << "---" << endl;

    return 0;
}
