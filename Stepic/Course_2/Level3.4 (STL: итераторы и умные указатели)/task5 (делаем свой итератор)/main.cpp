#include <iostream>

/*
    В этом задании вам нужно разработать итераторы для контейнера VectorList, 
    который хранит данные в списке векторов. Для упрощения задачи от вас 
    требуется реализовать только константные итераторы (прямой и обратный), 
    а также реализовать методы begin, end, rbegin и rend. 
    Для того, чтобы разобраться в устройстве контейнера, 
    начните работу над задачей с реализации метода size. 
    Заполнение контейнера будет происходить при помощи метода append, 
    который уже реализован (реализация в комментариях дана для ознакомления). 
    Метод append гарантирует, что в списке не будет пустых векторов.

    Больше подробностей в коде.
*/

#include <vector>
#include <list>

template<class T>
class VectorList
{
private:
    using VectT  = std::vector<T>;
    using ListT = std::list<VectT>;

public:
    using value_type = T;

    VectorList() = default;
    VectorList(VectorList const &) = default;
    VectorList(VectorList &&) = default;

    VectorList & operator=(VectorList &&)     = default;
    VectorList & operator=(VectorList const &) = default;

    // метод, который будет использоваться для заполнения VectorList
    // гарантирует, что в списке не будет пустых массивов
    template<class It>
    void append(It p, It q); // определена снаружи
/*  {
        if (p != q)
            data_.push_back(VectT(p,q));
    } 
*/

    bool empty() const { return size() == 0; } 

    // определите метод size
    size_t size() const 
    {
        //...

        return 0;
    }

    // определите const_iterator
    //... const_iterator ... 

    // определите методы begin / end
    //const_iterator begin() const { return ... ; }
    //const_iterator end()   const { return ... ; }

    // определите const_reverse_iterator
    //... const_reverse_iterator ...

    // определите методы rbegin / rend
    //const_reverse_iterator rbegin() const { return ... ;   }
    //const_reverse_iterator rend()   const { return ... ; }

private:
    ListT data_;
};

int main(int argc, const char * argv[]) 
{

    return 0;
}