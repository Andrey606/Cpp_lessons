#include <iostream>

using namespace std;

void foo(char s[]);

int main()
{
    
    char c[2] = {0};
    cin >> c;
        
    foo(c);
    

	return 0;
}

void foo(char s[])
{ 
    if(s[0] == '0')
        return;
    
    char c[2] = {0};
    cin >> c;
    foo(c);
    
    cout << s << " ";
}