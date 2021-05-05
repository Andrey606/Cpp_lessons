#include <iostream>
#include <functional>

//BLACK будет соответствовать число 0, WHITE — 1, а RED — 2.
// так лучше не делать
/*
Такие перечисления не являются типобезопасными — они представлены целыми числами, 
несмотря на то, что сами типы перечислений различны. Это позволяет, например, 
сравнивать значения из разных перечислений.  Другая проблема — это нарушение областей видимости: 
enum не задаёт области видимости, соответственно, все элементы перечисления "видны" снаружи 
(т.е. можно к ним обращаться не указывая имя перечисления*/
enum COLORS 
{
    BLACK, WHITE, RED, GREEN = 4, BLUE = 8
}; 

// В новом стандарте появился новый тип перечислений enum class, который не обладает этими недостатками.
// Элементы такого перечисления невозможно неявно преобразовать в целые числа.
enum class COLORS2
{ 
    BLACK, WHITE, RED, GREEN = 4, BLUE = 8
};

// Тип классового перечисления теперь не зависит от реализации (по умолчанию int) и может быть задан явно:
// При этом для доступа к элементам такого перечисления необходимо будет указывать имя перечисления.
enum class DAYS : unsigned int 
{
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};

/*
    Не стоит использовать перечисления старого типа. Если такие 
    перечисления уже есть в проекте, то их можно улучшить, указав явно соответствующий
    целочисленный тип. При этом сохранится совместимость с существующим кодом, т.к. элементы перечисления 
    будут доступны без указания имени перечисления:
*/
/*enum COLORS : unsigned int 
{ 
    BLACK, WHITE, RED, GREEN = 4, BLUE = 8
}; */

int main(int argc, const char * argv[]) 
{   
   
    return 0;
}