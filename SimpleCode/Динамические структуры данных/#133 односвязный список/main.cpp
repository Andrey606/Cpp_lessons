#include <iostream>

using namespace std;

template<typename K>
class List
{

public:
    List(/* args */);
    ~List();

    void push_back(K data);
    int GetSize();
    K& operator[](const int index);

private:

    template<typename T>
    class Node
    {
    public:
        Node *pNext;
        T data;
        Node(T data=T(), Node *pNext=nullptr) // T data=T() - если передадут клас то вызовется его конструктор
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node<K> *head;

};

template<typename K>
List<K>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename K>
List<K>::~List()
{
}

template<typename K>
void List<K>::push_back(K data)
{
    if(head == nullptr)
    {
        head = new Node<K>(data);
        Size = 1;
    }
    else
    {
        Node<K> *current = this->head;
        while(current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<K>(data);
        Size++;
    }
}

template<typename K>
K & List<K>::operator[](const int index)
{
    int counter = 0;
    Node<K> *current = this->head;
    while (current != nullptr)
    {
        if(counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename K>
int List<K>::GetSize()
{
    return Size;
}

int main() 
{
    setlocale(LC_ALL, "ru");
    
    List<int> tmp;
    tmp.push_back(10);
    tmp.push_back(5);
    tmp.push_back(22);

    std::cout << tmp.GetSize() << std::endl;
    std::cout << tmp[0] << std::endl;
    std::cout << tmp[3] << std::endl;
  
    return 0;
}