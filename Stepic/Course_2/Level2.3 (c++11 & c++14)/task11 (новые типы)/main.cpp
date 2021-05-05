#include <iostream>
#include <functional>

/*
  
*/


int main(int argc, const char * argv[]) 
{   
    char     ch1{ 'a' };  // or { u8'a' } - u8 используется для UTF-8
    wchar_t  ch2{ L'a' }; // размер переменной зависит от архитектуры
    char16_t ch3{ u'a' }; // - u используется для UTF-16
    char32_t ch4{ U'a' }; // - U используется для UTF-32    

    // кодировки Unicode
    /*
        - UTF-8 
        - UTF-16
        - UTF-32
    */

    /*
    В новом стандарте появилась возможность указывать сырые строки
    сырые строки - строки в которых могут встречаться управляющие последовательности (кавычки и слеши)
    */
    std::cout << R"(My string \ vvb)" << std::endl; // My string \ vvb
    std::cout << R"sasas(My string \ vvb)sasas" << std::endl; // My string \ vvb "sasas" - это рандомное слово чтобы показать где начало и конец строки

    // nтакже можно вывводить символы из таблици 
    std::cout << u8"symbol: \u2018" << std::endl; // symbol: ‘

    // а также можно комбинировать
    std::cout << LR"(raw wide string literal \t (without a tab))" << std::endl; // 
    return 0;
}