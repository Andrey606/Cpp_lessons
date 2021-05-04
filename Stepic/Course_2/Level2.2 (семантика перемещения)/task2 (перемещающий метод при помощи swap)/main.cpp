#include <iostream>
#include <string>

/* 
std::swap() - получает ссылку на обьект такожего типа и обменивает данные текущего обьекта и обьекта по ссылке 
*/

struct String
{
public:
    void swap(String & s)
    {
        std::swap(data_, s.data_);
        std::swap(size_, s.size_);
    }
    // перемещающий конструктор
    String(String && s)
    {
        swap(s); // меняет пустые значение этого обьекта с переданным в аргументе
    }
    // перемещающий оператор присваивания
    String& operator = (String && s)
    {
        swap(s); 
        return *this;
    }
public:
    char* data_ = nullptr;
    int size_ = 0;
};

int main(int argc, const char * argv[]) 
{
    
    return 0;
}