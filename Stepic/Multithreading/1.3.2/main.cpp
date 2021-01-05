#include <stdio.h> // ошибка - #include <stdio> 

void f(unsigned int n) {

    // if(n == 0) return 1; // ошибка 

    // else if(n == 1) return 1; // ошибка 

    //return f(n-2) + f(n-1); // ошибка 
}

int main(int argc, char **argv) 
{

    unsigned int n;

    scanf("%u", &n); // ошибка - scanf(n);

    f(n); // ошибка - n = f(n)

    printf("f(n) = %u\n", n);

    return 0;

}