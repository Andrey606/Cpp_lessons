#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <functional>
#include <map>

/*
    На первой неделе мы познакомились с RTTI и понятием мультиметодов. В этой задаче предлагается реализовать шаблонный класс Multimethod2, реализующий мультиметод от двух аргументов, который позволяет динамически добавлять новые реализации мультиметода для различных пар классов.

    Вам нужно будет реализовать три метода класса Multimethod2:
    addImpl — добавляет реализацию мультиметода для двух типов, которые заданы через std::type_info.
    hasImpl — принимает два указателя и проверяет, есть ли реализация мультиметода для соответствующих типов.
    call — принимает два указателя и вызывает для них соответствующую реализацию.
    Реализация этих методов должна корректно обрабатывать ситуацию, когда мультиметод является коммутативным (т.е. если результат вызова мультиметода не зависит от порядка аргументов).

    Пример использования:

    ...

    Для реализации вам потребуется положить std::type_info в какой-то контейнер. Однако по стандарту 
    std::type_info нельзя копировать, поэтому просто так его в контейнер не положить. Для решения этой 
    проблемы в новом стандарте появился специальный класс-обёртка std::type_index, который можно хранить в 
    контейнерах и даже использовать в качестве ключа в упорядоченных ассоциативных контейнерах. std::type_index 
    определён в заголовочном файле <typeindex>.

    Дополнительную информацию вы найдёте в шаблоне кода.
*/

// базовый класс фигуры (полиморфный)
struct Shape { 
    virtual ~Shape() = default;
 };

// прямоугольник
struct Rectangle : Shape {  };

// треугольник
struct Triangle : Shape {  };

// функция для проверки пересечения двух прямоугольников
bool is_intersect_r_r(Shape * a, Shape * b)
{
    return false;
}

// функция для проверки пересечения прямоугольника и треугольника
bool is_intersect_r_t(Shape * a, Shape * b)
{
    return false;
}

// Base - базовый класс иерархии
// Result - тип возвращаемого значения мультиметода
// Commutative - флаг, который показывает, что
// мультиметод коммутативный (т.е. f(x,y) = f(y,x)).
template<class Base, class Result, bool Commutative>
struct Multimethod2
{
    // устанавливает реализацию мультиметода
    // для типов t1 и t2 заданных через typeid 
    // f - это функция или функциональный объект
    // принимающий два указателя на Base 
    // и возвращающий значение типа Result
    void addImpl( const std::type_info& t1, const std::type_info& t2, std::function<Result (Base *, Base *)> f )
    {
        //std::cout << t1.name() << std::endl;
        //std::cout << t2.name() << std::endl;

        implementation.emplace(std::make_pair(std::type_index(t1), std::type_index(t2)), f);
    }

    // проверяет, есть ли реализация мультиметода
    // для типов объектов a и b
    bool hasImpl(Base * a, Base * b) const
    {
        // возвращает true, если реализация есть
        // если операция коммутативная, то нужно 
        // проверить есть ли реализация для b и а 
        auto it = implementation.find({std::type_index(typeid(*a)), std::type_index(typeid(*b))});
        if (it != implementation.end())
            return true;

        if(Commutative)
        {
            it = implementation.find({std::type_index(typeid(*b)), std::type_index(typeid(*a))});
            if (it != implementation.end())
                return true;
        }

        return false;
    }

    // Применяет мультиметод к объектам
    // по указателям a и b
    Result call(Base * a, Base * b) const
    {
        // возвращает результат применения реализации
        // мультиметода к a и b
        auto it = implementation.find({std::type_index(typeid(*a)), std::type_index(typeid(*b))});
        if (it != implementation.end())
            return it->second(a, b);

        if(Commutative)
        {
            it = implementation.find({std::type_index(typeid(*b)), std::type_index(typeid(*a))});
            if (it != implementation.end())
                return it->second(b, a);
        }
    }

    std::map<std::pair<std::type_index, std::type_index>, std::function<Result (Base *, Base *)>> implementation;
};


int main() 
{
    // мультиметод для наследников Shape
    // возращающий bool и являющийся коммутативным 
    Multimethod2<Shape, bool, true> is_intersect;

    // добавляем реализацию мультиметода для двух прямоугольников
    is_intersect.addImpl(typeid(Rectangle), typeid(Rectangle), is_intersect_r_r);

    // добавляем реализацию мультиметода для прямоугольника и треугольника
    is_intersect.addImpl(typeid(Rectangle), typeid(Triangle), is_intersect_r_t);

    // создаём две фигуры    
    Shape * s1 = new Triangle();
    Shape * s2 = new Rectangle();

    std::cout << "1: " << is_intersect.hasImpl(s1, s2) << std::endl;
    std::cout << "2: " << is_intersect.hasImpl(s2, s1) << std::endl;
    std::cout << "3: " << is_intersect.hasImpl(s1, s1) << std::endl;
    std::cout << "4: " << is_intersect.hasImpl(s2, s2) << std::endl;

    // проверяем, что реализация для s1 и s2 есть
    if (is_intersect.hasImpl(s1, s2))
    {
         // вызывается функция is_intersect_r_t(s2, s1)
         bool res = is_intersect.call(s1, s2);

         // Замечание: is_intersect_r_t ожидает,
         // что первым аргументом будет прямоугольник
         // а вторым треугольник, а здесь аргументы
         // передаются в обратном порядке. 
         // ваша реализация должна самостоятельно 
         // об этом позаботиться
    }
}