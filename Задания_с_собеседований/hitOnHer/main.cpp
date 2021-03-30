#include <iostream>

bool hitOnHer(void)
{
    char answer;

    std::cout << "Hi, my name is Andrew." << std::endl;
    std::cout << "I really liked you and I would like to meet you. ";
	std::cout << "If you do not mind." << std::endl;
	
	do
	{
        std::cout << "Let's meet (y/n)? "; 
        std::cin >> answer;  
	}while(answer != 'y');

	return EXIT_SUCCESS;
}


int main() 
{
    hitOnHer();
    
    return 0;
}