#include <iostream>

/*
    Итератор - обьект для доступа к элементам последовательности, синтаксически похожий на указатель.
    Итераторы деляться на пять категорий

    - random access iterator: ++, --, арифметика, <, >, <=, >=
    (array, vector, decque)

    - Bidirectional iterator: ++, --
    (list set map)

    - forward iterator: ++
    (forward list, unordered set, unordered map)

    - input iterator: ++, read-only
    - output iterator: ++, write only

    Функции для работы с итератором:
    1) template< class InputIt, class Distance >
    void advance( InputIt& it, Distance n ); // передвигает итератор на несколько позиций вперед
        В качестве типа для Distance могут быть арифметические типы с знаком, например, int. 
        Таким образом алгоритм std::advance можно использовать не только для сдвига итератора вперёд, 
        но и для сдвига назад (для этого нужен как минимум двунаправленный итератор).
        std::advance(it, -5); // сдвиг на 5 позиций назад

    2) size_t distance (Iterator f, Iterator l); // позволяет высчетать растояние между двумя итераторами
    3) void iter_swap(Iterator i, Iterator j); // переставляет те значение на которые указывает итераторы

    4) std::next(it) позволяет получить следующий за it итератор;
    5) std::prev(it) позволяет получить итератор идущий перед it.
        !Внимание: так же как и std::advance эти методы не проверяют выход за границу последовательности — это обязанность программиста.
*/

int main(int argc, const char * argv[]) 
{


    return 0;
}