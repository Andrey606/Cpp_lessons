#include <stdio.h>
#include <stdint.h>
#include <iostream>

int main(int argc, char **argv) 
{

    // #1
    uint32_t *i;
    uint64_t *k;
    std::cout << i << std::endl;  // 0
    std::cout << k << std::endl;  // 0
    
    // #2
    i++;
    k++;
    std::cout << i << std::endl; // 4
    std::cout << k << std::endl;  // 8



    return 0;

}