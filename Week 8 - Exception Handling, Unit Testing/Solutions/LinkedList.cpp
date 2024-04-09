#include <iostream>
#include <functional>

template<typename T>
class ListNode
{
    private: 
        T data;
        ListNode<T>* next;
        void copy(const ListNode&); 
        void erase();

    public:
        ListNode();
        ListNode(T data, ListNode<T>* next);
        ListNode(const ListNode&);
        ListNode<T>& operator=(const ListNode<T>&);
        ~ListNode();
        void add(T);
        T getData();
        ListNode<T>* getNext();
        void setNext(ListNode<T>* newNext)
        {
            next = newNext;
        }
};

template<typename T>
class LinkedList
{
    private:
        ListNode<T>* head;
        ListNode<T>* getNodeOnIndex(size_t idx);
    
    public:
        LinkedList();
        void add(T);
        T removeLast();
        T removeFirst();
        T removeOnIndex(size_t idx);
        T getHead();
        T getAt(size_t idx);

        //Task2
        LinkedList<T> filter(std::function<bool(T)>);
        LinkedList<T> map(std::function<T(T)>);

};

template<typename T>
LinkedList<T> LinkedList<T>::filter(std::function<bool(T)> foo)
{
    LinkedList<T> result;
    ListNode<T>* tmp = head;
    while(tmp != nullptr)
    {
        if(foo(tmp->getData()))
        {
            result.add(tmp->getData());
        }
        tmp = tmp->getNext();
    }
    return result;
}

template <typename T>
LinkedList<T> LinkedList<T>::map(std::function<T(T)> foo)
{
    LinkedList<T> result;
    ListNode<T>* tmp = head;
    while(tmp != nullptr)
    {
        result.add(foo(tmp->getData()));
        tmp = tmp->getNext();
    }
    return result;
}
template<typename T>
ListNode<T>* ListNode<T>::getNext()
{
    return next;
}
template<typename T>
ListNode<T>::ListNode() 
{
    next = nullptr;
}

template<typename T>
ListNode<T>::ListNode(T data, ListNode<T>* next) 
{
    this->data = data;
    this->next = next;
}

template<typename T>
void ListNode<T>::copy(const ListNode<T>& other) 
{
    this->data = other.data;
    if(other.next != nullptr)
    {
        this->next = new ListNode(*other->next);
    }
    else
    {
        this->next = nullptr;
    }
}
template<typename T>
ListNode<T>::ListNode(const ListNode<T>& other) 
{
    copy(other);
}

template<typename T>
T ListNode<T>::getData()
{
    return data;
}

template<typename T>
ListNode<T>& ListNode<T>::operator=(const ListNode<T>& other)
{
    if(this != &other)
    {
        erase();
        copy(other);
    }
}
template <typename T>
void ListNode<T>::erase()
{
    if(next != nullptr)
    {
        next->erase();
    }
    delete next;
}
template<typename T>
ListNode<T>::~ListNode()
{
    erase();
}

template<typename T>
void ListNode<T>::add(T el)
{
    if(next != nullptr)
    {
        ListNode<T>* tmp = next;
        while(tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = new ListNode(el, nullptr);
    }
    else
    {
        next = new ListNode(el, nullptr);
    }
}
template<typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}

template <typename T>
void LinkedList<T>::add(T el)
{
    if(head == nullptr)
    {
        head = new ListNode<T>(el, nullptr);
    }
    else
    {
        head->add(el);
    }
}

template <typename T>
T LinkedList<T>::removeFirst()
{
    
    T val; 
    if(head == nullptr)
    {
        return val;
    }
    val = head->getData();
    ListNode<T> *tmpHead = head;
    head = head->getNext();
    tmpHead->setNext(nullptr);
    delete tmpHead;
    return val;
}

template <typename T>
T LinkedList<T>::removeLast()
{
    if(head->getNext() == nullptr)
    {
        T data = head->getData();
        delete head;
        head = nullptr;
        return data;
    }
    else
    {
        ListNode<T> *tmp = head;
        while(tmp->getNext() && tmp->getNext()->getNext() != nullptr)
        {
            tmp = tmp->getNext();
        }
        T data = tmp->getNext()->getData();
        delete tmp->getNext();
        tmp->setNext(nullptr);
        return data;
    }
}

template<typename T>
ListNode<T>* LinkedList<T>::getNodeOnIndex(size_t idx)
{
    ListNode<T>*tmp = head;
    for(int i = 0; i < idx; i++)
    {
        tmp = tmp->getNext();
    }
    return tmp;
}

template <typename T>
T LinkedList<T>::removeOnIndex(size_t idx)
{
    ListNode<T>* tmp = getNodeOnIndex(idx - 1);
    ListNode<T>* nodeToDelete = tmp->getNext();
    T data = nodeToDelete->getData();
    tmp->setNext(nodeToDelete->getNext());
    nodeToDelete->setNext(nullptr);
    delete nodeToDelete;
    return data;
}

template <typename T>
T LinkedList<T>::getAt(size_t idx)
{
    ListNode<int> *ptr = getNodeOnIndex(idx);
    if(ptr == nullptr)
    {
        throw std::exception();
    }
    return ptr->getData();
}

template<typename T>
T LinkedList<T>::getHead()
{
    return head->getData();

}
