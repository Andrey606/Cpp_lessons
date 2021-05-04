#include <iostream>

/*
    Дополните класс Array перемещающим конструктором и перемещающим оператором присваивания.
    Замечание: все объявленные методы класса Array уже реализованы.
*/

template<class T>
struct Array
{
    // все объявленные ниже методы уже реализованы
    explicit Array(size_t size = 0) : size_(size), data_(new T[size]){}
    Array(Array const& a);
    Array & operator=(Array const& a);
    ~Array()
    {
        if(size_ != 0)
        {
            size_ = 0;
            delete[] data_;
            data_ = nullptr;
        }
    }

    size_t size() const
    {
        return size_;
    }
    T &         operator[](size_t i)
    {
        return data_[i];
    }
    T const&    operator[](size_t i) const
    {
        return data_[i];
    }

    void swap(Array & s)
    {
        std::swap(data_, s.data_);
        std::swap(size_, s.size_);
    }

    // реализуйте перемещающий конструктор
    Array(Array && s) : Array()
    {
        swap(s); // меняет пустые значение этого обьекта с переданным в аргументе
    }

    // реализуйте перемещающий оператор присваивания
    Array& operator = (Array && s)
    {
        swap(s); 
        return *this;
    }

private:    
    size_t  size_ = 0;
    T *     data_ = nullptr;    
};

int main(int argc, const char * argv[]) 
{

    // init
    std::cout << "init first array" << std::endl;
    Array<int> obj1(10);
    for (size_t i = 0; i < obj1.size(); i++)
    {
        obj1[i] = i;
        std::cout << obj1[i] << " ";
    }
    std::cout << std::endl; 

    // init second array by first (check перемещающий конструктор)
    std::cout << "init second array by first (check перемещающий конструктор)" << std::endl;
    Array<int> obj2(std::move(obj1));
    std::cout << "первый массив: "<< std::endl;
    for (size_t i = 0; i < obj1.size(); i++)
    {
        std::cout << obj1[i] << " ";
    }
    std::cout << std::endl;    
    std::cout << "второй массив: "<< std::endl;
    for (size_t i = 0; i < obj2.size(); i++)
    {
        std::cout << obj2[i] << " ";
    }
    std::cout << std::endl;   

    // init third array by second (check перемещающий оператор присваивания)
    std::cout << "init third array by second (check перемещающий оператор присваивания)" << std::endl;
    Array<int> obj3 = std::move(obj2);
    std::cout << "второй массив: "<< std::endl;
    for (size_t i = 0; i < obj2.size(); i++)
    {
        std::cout << obj2[i] << " ";
    }
    std::cout << std::endl;    
    std::cout << "третий массив: "<< std::endl;
    for (size_t i = 0; i < obj3.size(); i++)
    {
        std::cout << obj3[i] << " ";
    }
    std::cout << std::endl; 
    



    return 0;
}