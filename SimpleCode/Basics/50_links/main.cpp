/*
* Ссылки. Урок #50
*/

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <functional>

using namespace std;

class Message
{
public:
    explicit Message(const string& topicName=nullptr);
    ~Message()=default;
public:
   
    const string& topicName();

private:
    string _topicName;
};

Message::Message(const string& topicName):
    _topicName(topicName)
{
}

const string& Message::topicName()
{
    return _topicName;
}

int main() 
{
    setlocale(LC_ALL, "ru");
 
    
    int a = 5;


    // указатель
    int *pa = &a;

    // ссылка (reference)
    // ссылка тоже хранит адрес на переменую
    // 1) не нужно использовать символ взятия адресса 
    // 2) не нужно разименовывать для взятия значения на которое указывает указатель
    // + 3) нет возможности залесть не на тот участок памяти pa++;
    // + 4) через ссылку мы работаем с данными на прямую
    // 5) ссылку нужно сразу инициализировать иначе ошибка при копиляции
    int &aRef = a; // хранит адрес переменой


    // 1) ====================================
    // указатель
    /*cout << "*pa\t" << *pa << endl;
    cout << "pa\t" << pa << endl;
    pa++;
    cout << "*pa\t" << *pa << endl;
    cout << "pa\t" << pa << endl;

    // ссылка (reference)
    cout << "&aRef\t" << aRef << endl;

    aRef++;

    cout << "&aRef\t" << aRef << endl;*/
    
    // 2) ====================================

    cout << "&aRef\t" << &aRef << endl;
    cout << "*pa\t" << *pa << endl;

    aRef = 55; // теперь и переменая "а" и "aRef" = 55  

    cout << "&aRef\t" << aRef << endl;
    cout << "*pa\t" << *pa << endl;

    // 3) ====================================


    // ppa хранит адрес aRef
    int *ppa = &aRef;

    cout << "*ppa = &aRef\t" << *ppa << endl; // ppa = pa = aRef = a

    *ppa = 12;

    cout << "a\t" << a << endl; // ppa = pa = aRef = a

    //1
    Message  msg;
    cout << msg.topicName() << endl; // error - Aborted (core dumped)

    //2
    // Message  msg("dcsds");
    // cout << msg.topicName() << endl;

  
    return 0;
}