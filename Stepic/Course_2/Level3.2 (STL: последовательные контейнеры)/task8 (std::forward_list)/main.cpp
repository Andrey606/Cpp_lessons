#include <iostream>
#include <forward_list>

/*
    forward_list - в любое место контейнера вставка и удаление производится за О(1)
*/


int main(int argc, const char * argv[]) 
{
    std::forward_list<std::string> fl = {"One", "Two"};
    fl.emplace_front("Zero"); 
    fl.push_front("Minus One"); 
    std::cout << fl.front() << std::endl<< std::endl;

    return 0;
}