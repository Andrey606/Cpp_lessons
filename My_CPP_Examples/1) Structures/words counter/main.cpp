// structure.cpp
// ������� ����� ���� � ����������� � �������������� ������������

#include <iostream>
#include <clocale> // ��� ���������� ����������� ������� ��������
using namespace std;
#include <conio.h> // ��� getche()

enum itsaWord {NO, YES}; // NO = 0, YES = 1


int main()
{
    setlocale(LC_CTYPE, "rus"); // ����� ������� ��������� ������

    itsaWord isWord = NO; // isWord = YES, ����� �������� �����, � NO. ����� ������� �������
    char ch='a';
    int wordcount = 0;
    cout << "������� �����������: \n";

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
    }while(ch != '\r'); // ����� �� ������� �� Enter

    cout << "\n---����� ����: " << wordcount << "---" << endl;

    return 0;
}
