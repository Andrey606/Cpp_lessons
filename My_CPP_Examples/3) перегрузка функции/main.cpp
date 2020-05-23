#include <iostream>

using namespace std;

float perimetr(float x, float y)
{
    return x+y;
}

float perimetr(float x, float y, float z)
{
    return x+y+z;
}

int main(int argc, const char *argv)
{
    cout << perimetr(5.2, 6.8) << endl;
    cout << perimetr(5.2, 6.8, 7.6) << endl;

    return 0;
}
