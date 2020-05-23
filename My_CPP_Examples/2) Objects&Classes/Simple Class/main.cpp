// structure.cpp
// ��������� ��� �������� ����=������� � ������� �������

#include <iostream>
#include <clocale> // ��� ���������� ����������� ������� ��������
using namespace std;

class smallobj          // ����������� ������
{
    private:
        int somedata;   // ���� ������
    public:
        void setdata(int d)
            { somedata = d;}
        void showdata()
            { cout << "�������� ���� ����� " << somedata << endl;}
};


int main()
{
    setlocale(LC_CTYPE, "rus"); // ����� ������� ��������� ������

    smallobj s1, s2;

    s1.setdata(1066);
    s2.setdata(10766);

    s1.showdata();
    s2.showdata();

    return 0;
}
