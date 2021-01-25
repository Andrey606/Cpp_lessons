#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

/*
1. What is the difference between a reference and a pointer ?
2. Explain the difference between  int x;  int x (); and  int x {};
3.  assert (sizeof (int)! = Sizeof (long)) ; Is this statement always true?
4. What will the following line of code print out and why ? unsigned int x = 1; std :: cout << x;
5. Can you explain the difference between  new  and  new [] ? Is it possible to delete memory using  delete []  allocated within the new operator?
6. What is the difference between  new / malloc  or  delete / free ?
7. What is the difference between stack and heap allocation ?
8. What is the evaluation order of the function parameters in C ++?
9. What is the construction order of global variables?
10. What is the forward declaration of classes? What is it used for?
11. What is the meaning of a  const  keyword and how can it be used? 
12. What is the meaning of a  static  keyword and how can it be used? 
13. What are the advantages of using friend classes?
14. What is an abstract class? What is the pure virtual function?
15. How do you create a virtual constructor and virtual destructor for a class ? Why would you do it? 
16. What is avtable and how does it work?
17. Initialization order of Bases and Members.
18. Is it possible to call a virtual function inside of a constructor / destructor?
19. What is a template and how is it used ? 
20. What is specialization? How can it help to improve efficiency? 
21.  struct Vector {int * data; int size; }; Write copy constructor, operator = and destructor for the struct Vector.
22. What is an iterator? What iterator types do you know?
23. What is  RAII ?
24. When should you use  std :: unique_ptr  vs. std :: shared_ptr ? 
25. How should runtime errors be handled in C ++? What general approaches do you know?
26. What will happen if the exception will be thrown within a constructor ?
27. C ++ supports multiple inheritance. What is the "diamond problem" that can occur with multiple inheritance? Give an example.
*/

// патерны:
/*
1) Singleton
2) Decorator
3) Abstract Factory
4) Adapter
*/


int main() 
{
    // 1(✓). What is the difference between a reference and a pointer ?
    /*
    1. Указатель может быть переназначен любое количество раз, в то время как ссылка после привязки не может быть перемещена на другую ячейку памяти.
    2. Указатели могут указывать "в никуда" (быть равными NULL), в то время как ссылка всегда указывает на определенный объект. 
    GCC может без выдачи предупреждений обработать код наподобие int &x = *(int*)0;, однако поведение подобного кода может быть непредсказуемым.
    3. Вы не можете получить адрес ссылки, как можете это делать с указателями.
    4. Не существует арифметики ссылок, в то время как существует арифметика указателей. 
    Однако есть возможность получить адрес объекта, указанного по ссылке, и применить к этому адресу арифметику указателей (например &obj + 5).
    */

    // 2(✓). Explain the difference between  int x;  int x (); and  int x {};
    /*
    int x {}; // - (uniform-инициализация) это инициализировано 0 работает с с++11, но лучше int x=0; тоже самое да и поддержывается в более раних версиях
        Прямая или копирующая инициализация работают не со всеми типами данных (например, вы не сможете использовать эти способы для инициализации списка значений).
        В попытке обеспечить единый механизм инициализации, который будет работать со всеми типами данных, 
        в C++11 добавили новый способ инициализации, который называется uniform-инициализация:
        list<int> listA[10] = {0};
        tckb gt
    int x; // инициализация через конструктор по умолчанию
    int x (); // инициализация через конструктор по умолчанию
    int x={}; // инициализация через конструктор по умолчанию с С++11
    разные конструкторы используются: копирования...
    */

    // 3(✓). assert (sizeof (int)! = Sizeof (long)) ; Is this statement always true?
    /*
        Нет, это не так. В спецификациях C и C ++ указано только, что long должно быть больше или равно 32 битам. 
        int может быть меньше, но на многих платформах, в C и C ++, longи intоба 32 бита.
    */

    // 4(✓). What will the following line of code print out and why ? unsigned int x = 1; std :: cout << x;
    /*
    объект std::cout (который находится в библиотеке iostream) используется для вывода данных на экран (в консольное окно).
    вывод: 1
    */

    // 5(?). Can you explain the difference between  new  and  new [] ? Is it possible to delete memory using  delete []  allocated within the new operator?
    /*
    newвыделяет память для одного элемента и вызывает его конструктор, а также deleteвызывает его деструктор и освобождает его память.
    new[]выделяет память для массива элементов и вызывает их конструкторы, а также delete[]вызывает их деструкторы и освобождает память массива.
    */

    // 6(?). What is the difference between  new / malloc  or  delete / free ?
    /*
        Feature                  | new/delete                     | malloc/free                   
    --------------------------+--------------------------------+-------------------------------
    Memory allocated from    | 'Free Store'                   | 'Heap'                        
    Returns                  | Fully typed pointer            | void*                         
    On failure               | Throws (never returns NULL)    | Returns NULL                  
    Required size            | Calculated by compiler         | Must be specified in bytes    
    Handling arrays          | Has an explicit version        | Requires manual calculations  
    Reallocating             | Not handled intuitively        | Simple (no copy constructor)  
    Call of reverse          | Implementation defined         | No                            
    Low memory cases         | Can add a new memory allocator | Not handled by user code      
    Overridable              | Yes                            | No                            
    Use of (con-)/destructor | Yes                            | No            

    По умолчанию, если оператор new не сработал, память не выделилась, то генерируется исключение bad_alloc       
    но есть вариант выполнить операцию без исключений: 
    new (std::nothrow) int; // указатель value станет нулевым, если динамическое выделение целочисленной переменной не выполнится         
    */

    // 7(✓). What is the difference between stack and heap allocation ?
    /*
    - Стек вызовов, где хранятся параметры функции, локальные переменные и другая информация, связанная с функциями. (1мб\8мб)
    int a; 
    int b[10]; 
    int n = 20; 
    int c[n]; 
    - Куча, откуда выделяются динамические переменные.
    int *ptr  = new int[10]; 
    Вот вы и познакомились с понятиями стека и кучи. Вкратце, стек — это очень быстрое хранилище памяти, 
    работающее по принципу LIFO и управляемое процессором. 
    Но эти преимущества приводят к ограниченному размеру стека и специальному способу получения значений. 
    Для того, чтобы избежать этих ограничений, можно пользоваться кучей — она позволяет 
    создавать динамические и глобальные переменные — но управлять памятью должен либо сборщик мусора, 
    либо сам программист, да и работает куча медленнее.
    */

    // 8(?). What is the evaluation order of the function parameters in C ++?
    /*
    зависит от  компилятора
    */

    // 9(✓). What is the construction order of global variables?
    /*
    "Нет гарантированного порядка инициализации глобальных переменных из различных единиц трансляции" - цитата из Страуструпа. 
    Из него же пример замены глобальной переменной функцией, возвращающей ссылку:
    std::map<...> &list_of_something() 
    { 
        static std::map<...> lst; 
        return lst; 
    }
    unsigned create(unsigned a)
    {
        static map<int, string> something;
        something.insert(make_pair(a, "somestring"));
        return a;
    }
    Инициализация списка происходит при первом использовании.
    */

    // 10(✓). What is the forward declaration of classes? What is it used for?
    /*
    пример когда ты 
    // Forward Declaration class A
    class A;

    // Definition of class A
    class A{
        // Body
    };
    */

    // 11(✓).  What is the meaning of a  const  keyword and how can it be used? 
    /*
    все константные переменные должны быть инициализированы во время объявления.
    - const int anything; // константа на значение
        const int* u; // константа на значение
        char const* v; // константа на значение
        int* const w = &x; // константа на указатель
    
    константые методы
    - int getValue() const { return m_value; } // ключевое слово const находится после списка параметров, но перед телом функции
        Теперь getValue() является константным методом. Это означает, что мы можем вызывать его через любой константный объект.
    
    передача аргументов по константной ссылки
    - void printDate(const Date &date)
    */

    // 12(✓). What is the meaning of a  static  keyword and how can it be used? 
    /*
    - статические функции
    - статические переменные
    - статические переменные в функциях
    - статические переменные в класах
    - статические методы в класах
    */

    // 13(✓). What are the advantages of using friend classes?
    /*
    - Дружественные функции
    - Дружественные классы
    - Дружественные методы
    позволяет функции/классу работать в тесном контакте с другим классом, не заставляя другой класс делать открытыми свои закрытые члены.
    *страдает инкапсуляция
    */

    // 14(✓). What is an abstract class? What is the pure virtual function?
    /*
    -Абстрактные классы - это классы, которые содержат или наследуют без переопределения хотя бы одну чистую виртуальную функцию. 
        Абстрактный класс определяет интерфейс для переопределения производными классами.
    - Что такое чистые виртуальные функции (pure virtual functions)? Это функции, которые не имеют определения. 
        Чтобы определить виртуальную функцию как чистую, ее объявление завершается значением "=0".
        Виртуальная функция — это функция-член, которую предполагается переопределить в производных классах. 
    */

    // 15(✓). How do you create a virtual constructor and virtual destructor for a class ? Why would you do it? 
    /*
    - если зоздавать обьекты в стеке то все будет работать и все деструкторы будут вызвываться
        но если создать в динамической:
        A * pA = new B; // то без виртуального деструктора вызывется только базовый деструктор так как ссылка именно на него
    -А где это есть виртуальные конструкторы? Они и так в некотором роде виртуальные :) В конструкторе происходит заполнение виртуальной таблицы. Кроме того, при вызове конструктора потомка всегда перед ним вызовется конструктор предка.
        Ну а в деструкторе вот какой смысл. Если он не виртуальный, то при вызове деструктора потомка деструктор предка НЕ будет вызван. Иначе — будет вызван после потомка.
    */

    // 16(✓). What is a vtable and how does it work?
    /*
    - Для каждого класса, содержащего виртуальные функции, компилятор создает виртуальную таблицу , 
        также известную как vtable . Таблица vtable содержит запись для каждой виртуальной функции, 
        доступной классу, и указатель на ее определение. 
    *динамической отправкой или поздним связыванием метода - когда  Компилятор должен найти правильное определение функции (т. Е. Наиболее конкретное) во время выполнения.
        Например:
        B* b = new C();
        b->bar();
    *также существуют Vpointers
    */

    // 17(?). Initialization order of Bases and Members.
    /*

    */

    // 18(✓). Is it possible to call a virtual function inside of a constructor / destructor?
    /*
    да!
    */

    // 19(✓). What is a template and how is it used ? 
    /*
    - template <class T>
    - template <typename T>
    - template <typename T1, typename T2>

    - We write code once and use it for any data type including user defined data types.

        template<class Type>
        Type _min(Type a, Type b){
            if( a < b){
                return a;
            }
            return b;
        }
        _min(1, 2);
        _min<double>(5, 2.1);
    - Шаблоны классов -– обобщенное описание пользовательского типа, в котором могут быть параметризованы атрибуты и операции типа. 
    
    Пример:
    template <typename T>
    void printArray(const T * array, int count)
    {
        for (int ix = 0; ix < count; ix++)
            cout << array[ix] << "   ";
        cout << endl;
    } 
    */

    // 20(✓). What is specialization? How can it help to improve efficiency? 
    /*
    - шаблон
        template <typename T, int size>
        void print(StaticArray<T, size> &array)
    -Полная специализация шаблона 
        template <>
        void print(StaticArray<char, 14> &array)
    - Частичная специализация
        template <int size> // size по-прежнему является non-type параметром
        void print(StaticArray<char, size> &array)

    - Частичная специализация шаблонов методов
        * либо полностью копировать весь клас 
        * либо наследовать его

    */

    // 21(✓). struct Vector {int * data; int size; }; Write copy constructor, operator = and destructor for the struct Vector.
    /*
    struct Vector {
        Vector(const Vector &other):
            data(new (std::nothrow) int[other.size]), size(other.size)
        {
            cout << "Vector()" << endl;
            copy(other.data, other.data+other.size, data);
        }

        ~Vector()
        {
            cout << "~Vector()" << endl;
            delete[] data;
        }

        Vector &operator=(const Vector &other)
        {
            cout << "&operator=" << endl;
            if (this != &other)
                Vector(other).swap(*this);
            return *this;
        }
        
        void swap(Vector& rhs)
        {
            cout << "swap" << endl;
            std::swap(size, rhs.size); 
            std::swap(data, rhs.data); 
        }

        int * data; 
        int size; 
    };
    */

    // 22(✓). What is an iterator? What iterator types do you know?
    /*
    Итератор — структура данных, которая «указывает» на некоторый элемент контейнера, и (для некоторых контейнеров) умеет переходить к предыдущему/следующему элементу.
    set, map, vector, list, unordered_map(хеш), unordered_set(хеш)
    */

    // 23(✓). What is  RAII ?
    /*
    Resource Acquisition Is Initialization.
    программная идиома объектно-ориентированного программирования, смысл которой заключается в том, что с помощью тех или иных программных механизмов 
    получение некоторого ресурса неразрывно совмещается с инициализацией, а освобождение — с уничтожением объекта.
    Типичным (хотя и не единственным) способом реализации является организация получения доступа к ресурсу в конструкторе, а освобождения — в деструкторе соответствующего класса. 
    */

    // 24(✓). When should you use  std :: unique_ptr  vs. std :: shared_ptr ? 
    /*
    unique_ptr<T> myPtr(new T);       // Okay
    unique_ptr<T> myOtherPtr = myPtr; // Error: Can't copy unique_ptr

    unique_ptr<T> myPtr(new T);                  // Okay
    unique_ptr<T> myOtherPtr = std::move(myPtr); // Okay, resource now stored in myOtherPtr

    shared_ptr<T> myPtr(new T);       // Okay
    shared_ptr<T> myOtherPtr = myPtr; // Sure!  Now have two pointers to the resource.
    */

    // 25(?). How should runtime errors be handled in C ++? What general approaches do you know?
    /*
    try
    {
        // Здесь мы пишем стейтменты, которые будут генерировать следующее исключение
        throw -1; // типичный стейтмент throw
    }
    catch (int a)
    {
        // Любые исключения типа int, сгенерированные в блоке try, приведенном выше, обрабатываются здесь
        std::cerr << "We caught an int exception with value: " << a << '\n';
    }
    */

    // 26(?). What will happen if the exception will be thrown within a constructor ?
    /*
    деструктор не вызывется но есть исключения для конструктора
    struct A
    {
        A() try
        { 
            std::cout << "A()" << std::endl; 
            throw -1; 
        }
        catch(int e)
        {
            std::cerr << "from constructor" << e << '\n';
        }

        ~A(){ std::cout << "~A()" << std::endl; }
    };
    */

    // 27(?). C ++ supports multiple inheritance. What is the "diamond problem" that can occur with multiple inheritance? Give an example.
    /*
    Ромбовидное наследование (англ. diamond inheritance) — ситуация в объектно-ориентированных языках программирования с поддержкой множественного наследования,
    когда два класса B и C наследуют от A, а класс D наследует от обоих классов B и C. При этой схеме наследования может возникнуть неоднозначность: 
    если объект класса D вызывает метод, определенный в классе A (и этот метод не был переопределен в классе D), 
    а классы B и C по-своему переопределили этот метод, то от какого класса его наследовать: B или C?

    C++ по умолчанию не создает ромбовидного наследования: компилятор обрабатывает каждый путь наследования отдельно, 
    в результате чего объект D будет на самом деле содержать два разных подобъекта A, и при использовании членов A потребуется указать 
    путь наследования (B::A или C::A). Чтобы сгенерировать ромбовидную структуру наследования, необходимо воспользоваться виртуальным 
    наследованием класса A на нескольких путях наследования: если оба наследования от A к B и от A к C помечаются спецификатором virtual 
    (например, class B : virtual public A), C++ специальным образом проследит за созданием только одного подобъекта A, и 
    использование членов A будет работать корректно. Если виртуальное и невиртуальное наследования смешиваются, то получается один виртуальный 
    подобъект A и по одному невиртуальному подобъекту A для каждого пути невиртуального наследования к A. При виртуальном вызове метода виртуального 
    базового класса используется так называемое правило доминирования: компилятор запрещает виртуальный вызов метода, который был перегружен на
    нескольких путях наследования.
    */
    
    

    

    
    return 0;
}


/*
1) в чем разница между кучей и фри стор?
2) Throws с++?
3) Overridable
4) вопрос №6, №2, №8, 

Механизм полиморфизма позволяет автоматически направлять вызовы производным классам, ничего о них не зная. 
Если у пользователя есть указатель на базовый класс, значением которого является адрес объекта производного класса, 
то для вызова некоторого метода производного класса пользователю достаточно знать об интерфейсе базового класса.
*/