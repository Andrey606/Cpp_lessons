#include <iostream>

using namespace std;

int strstr(const char *text, const char *pattern);

int main()
{
    
    cout << "res: " << strstr("hello world !", "werld") << endl;

	return 0;
}

int strstr(const char *text, const char *pattern)
{
    int point=0;
    bool flag = false;
    int point2=0;

    if(!pattern[0])
        return 0;
    
    while(text[point])
    {
        cout << "point: " << point << endl;

        if(text[point] == pattern[0])
        {
            
            point2 = 0;
            while(pattern[point2])
            {
                cout << "point2: " << point2 << " flag: " << flag << endl;
                if(pattern[point2] != text[point+point2])
                {
                    flag =false;
                    break;
                }else{
                    flag =true;
                }
                point2++;
            }
        }
        
        if(flag)
            return point;
        
        point++;
    }

    return -1;
}









