#include <iostream>
#include <vector>
#include <string>

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

// патерны полиморфизм

int main() 
{
    // 1. What is the difference between a reference and a pointer ?
    /*
    1. Указатель может быть переназначен любое количество раз, в то время как ссылка после привязки не может быть перемещена на другую ячейку памяти.
    2. Указатели могут указывать "в никуда" (быть равными NULL), в то время как ссылка всегда указывает на определенный объект. 
    GCC может без выдачи предупреждений обработать код наподобие int &x = *(int*)0;, однако поведение подобного кода может быть непредсказуемым.
    3. Вы не можете получить адрес ссылки, как можете это делать с указателями.
    4. Не существует арифметики ссылок, в то время как существует арифметика указателей. 
    Однако есть возможность получить адрес объекта, указанного по ссылке, и применить к этому адресу арифметику указателей (например &obj + 5).
    */

    // 2. Explain the difference between  int x;  int x (); and  int x {};
    /*
    int x {}; // - это инициализировано 0 работает с с++11, но лучше int x=0; тоже самое да и поддержывается в более раних версиях
    int x;  int x (); // - в этих может быть мусор

    разные конструкторы используются: копирования...
    */

    // 3. assert (sizeof (int)! = Sizeof (long)) ; Is this statement always true?
    /*
        Нет, это не так. В спецификациях C и C ++ указано только, что long должно быть больше или равно 32 битам. 
        int может быть меньше, но на многих платформах, в C и C ++, longи intоба 32 бита.
    */

    // 4. What will the following line of code print out and why ? unsigned int x = 1; std :: cout << x;
    /*
    1
    */

    // 5. Can you explain the difference between  new  and  new [] ? Is it possible to delete memory using  delete []  allocated within the new operator?
    /*
    newвыделяет память для одного элемента и вызывает его конструктор, а также deleteвызывает его деструктор и освобождает его память.
    new[]выделяет память для массива элементов и вызывает их конструкторы, а также delete[]вызывает их деструкторы и освобождает память массива.
    */

    // 6. What is the difference between  new / malloc  or  delete / free ?


    
    return 0;
}