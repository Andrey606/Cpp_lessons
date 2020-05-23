#include <iostream>

using namespace std;

void rotate(int a[], unsigned size, int shift);

int main()
{
    
    int arr[5] = { 1, 2, 3, 4, 5 };

    for(int i=0; i<5; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    rotate(arr, 5, 2);

    for(int i=0; i<5; i++)
        cout << arr[i] << " ";
    cout << endl;

	return 0;
}

void rotate(int a[], unsigned size, int shift)
{
    if(shift == 0)
        return;
    
    int num = a[0];
    
    for(int i=0; i<(size-1); i++)
    {
        a[i] = a[i+1];
    }
    
    a[(size-1)] = num;
    
    rotate(a, size, --shift);
}




