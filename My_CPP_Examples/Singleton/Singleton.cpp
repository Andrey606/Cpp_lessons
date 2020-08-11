#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Singleton.cpp
#include "Singleton.h"
  
Singleton* Singleton::p_instance = 0;

  
int main()
{
    Singleton *obj;
    Singleton *obj2;

    std::cout << obj << std::endl;
    std::cout << obj2 << std::endl;

    obj = obj->getInstance();
    obj2 = obj2->getInstance();

    std::cout << obj << std::endl;
    std::cout << obj2 << std::endl;

    return 0;
}


