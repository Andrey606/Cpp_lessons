#include <iostream>
/*
    basic_string - контейнер для хранения символьных последовательностей

    тоесть все строки что были раньше это были basic_string от разных типов

    basic_string<char> //  string
    basic_string<wchar_t> // wstring
    basic_string<char> // u16string
    basic_string<char> // u32string

    у него есть методы:

    * c_str() - возвращает указатель на внутений буфер сторроки
    * поддержка не явных преобразований со строками в стиле С
    * operator[], at
    * reserve capasity shrink_to_fit
    * append operator+ operator+=
    * substr replace compare
    * find, rfind find_first_of find_first_not_of find_last_of find_last_not_of
*/


int main(int argc, const char * argv[]) 
{

    return 0;
}