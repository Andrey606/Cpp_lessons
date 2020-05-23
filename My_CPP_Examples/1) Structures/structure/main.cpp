// structure.cpp
// ��������� ��� �������� ����=������� � ������� �������

#include <iostream>
#include <clocale> // ��� ���������� ����������� ������� ��������
using namespace std;

struct part             // ���������� ���������
{
    int modelnumber;    // ����� ������ �������
    int partnumber;     // ����� ������
    float cost;         // ��������� ������
};


int main()
{
    setlocale(LC_CTYPE, "rus"); // ����� ������� ��������� ������

    part part3;

    part part1 = {
       .modelnumber = 1,
       .partnumber = 2,
       .cost = 5.5F
    };
    // ����� �������� ����� �� �����
    cout << "������ " << part1.modelnumber;
    cout << ", ������ " << part1.partnumber;
    cout << ", ��������� $" << part1.cost << endl;


    part part2 = {10, 5, 8.8F};
    // ����� �������� ����� �� �����
    cout << "������ " << part2.modelnumber;
    cout << ", ������ " << part2.partnumber;
    cout << ", ��������� $" << part2.cost << endl;

    part3 = part1;
    // ����� �������� ����� �� �����
    cout << "������ " << part3.modelnumber;
    cout << ", ������ " << part3.partnumber;
    cout << ", ��������� $" << part3.cost << endl;

    part1.modelnumber = 6244;
    part1.partnumber = 373;
    part1.cost = 217.55F;
    // ����� �������� ����� �� �����
    cout << "������ " << part1.modelnumber;
    cout << ", ������ " << part1.partnumber;
    cout << ", ��������� $" << part1.cost << endl;

    return 0;
}
