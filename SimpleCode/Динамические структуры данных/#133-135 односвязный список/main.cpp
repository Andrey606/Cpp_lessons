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
    void clear();
    void pop_front(); // удаляет первый елемент масива

    void push_front(K data);
    void insert(K value, int index);
    void removeAt(int index);
    void pop_back();

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
    clear();
}

template<typename K>
void List<K>::clear()
{
    while(Size)
        pop_front();
}

template<typename K>
void List<K>::pop_front()
{
    Node<K> *tmpNode = this->head;
    this->head = this->head->pNext;
    delete tmpNode;
    Size--;
}

template<typename K>
void List<K>::push_front(K data)
{
    head = new Node<K>(data, head);
    Size++;
}

template<typename K>
void List<K>::insert(K value, int index)
{
    if(index==0)
    {
        push_front(value);
    }
    else
    {
        int counter = 0;
        Node<K> *current = this->head;
        while(current->pNext != nullptr)
        {
            if(counter == (index-1))
            {
                break;
            }
            current = current->pNext;
            counter++;
        }
        current->pNext = new Node<K>(value, current->pNext);
        Size++;
    }
}

template<typename K>
void List<K>::removeAt(int index)
{
    if(index==0)
    {
        pop_front();
    }
    else
    {
      int counter = 0;
        Node<K> *current = this->head;
        while(current->pNext != nullptr)
        {
            if(counter == (index-1))
            {
                break;
            }
            current = current->pNext;
            counter++;
        }
        Node<K> *tmp = current->pNext;
        current->pNext = tmp->pNext;
        delete tmp;
        Size--;  
    }
    
    
}

template<typename K>
void List<K>::pop_back()
{
    removeAt(Size-1);
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
    tmp[0] = 11;
    std::cout << tmp[0] << std::endl;

    tmp.pop_front();
    std::cout << tmp[0] << std::endl;
    tmp.pop_front();
    std::cout << tmp[0] << std::endl;

    std::cout << std::endl << std::endl;
    tmp.push_front(-1);
    tmp.push_front(-2);
    tmp.push_front(-3);
    tmp.push_front(-4);
    for (size_t i = 0; i < tmp.GetSize(); i++)
    {
        std::cout << tmp[i] << std::endl;
    }

    std::cout << std::endl << std::endl;
    tmp.insert(101, 0);
    tmp.insert(100, 1);
    tmp.insert(99, 1);
    for (size_t i = 0; i < tmp.GetSize(); i++)
    {
        std::cout << tmp[i] << std::endl;
    }

    std::cout << std::endl << std::endl;
    tmp.removeAt(0);
    tmp.removeAt(1);
    tmp.removeAt(1);
    tmp.removeAt(1);
    tmp.removeAt(1);
    for (size_t i = 0; i < tmp.GetSize(); i++)
    {
        std::cout << tmp[i] << std::endl;
    }

    std::cout << std::endl << std::endl;
    tmp.pop_back();
    for (size_t i = 0; i < tmp.GetSize(); i++)
    {
        std::cout << tmp[i] << std::endl;
    }
  
    return 0;
}