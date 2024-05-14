#include <iostream>

class ListNode
{
    private:
        int data;
        ListNode* next;

    public:
        int getData() const
        {
            return data;
        }   
        void setData(int data)
        {
            this->data = data;
        }
        ListNode* getNext() const
        {
            return next;
        }
        void setNext(ListNode* ptr)
        {
            next = ptr;
        }
        ~ListNode()
        {
            delete next;
        }
};
class LinkedList
{
    private:
        ListNode* start;
    
    public: 
        ListNode* getStart()
        {
            return start;
        }
        LinkedList()
        {
            start = nullptr;
        }
        void add(int a)
        {
            if(start != nullptr)
            {
                ListNode* ptr = start;
                while(ptr->getNext() != nullptr)
                {
                    ptr = ptr->getNext();
                }
                ListNode* newNode = new ListNode();
                newNode->setNext(nullptr);
                newNode->setData(a);
                ptr->setNext(newNode);
            }
            else
            {
                start = new ListNode();
                start->setData(a);
                start->setNext(nullptr);
            }
            
        }
        ~LinkedList()
        {
            delete start;
        }
        
        class Iterator
        {
            private:
                ListNode* ptr;
            
            public:
                ListNode* getPtr()
                {
                    return ptr;
                }
                bool operator==(const Iterator& other)
                {
                    return ptr == other.ptr;
                }
                bool operator!=(const Iterator& other)
                {
                    return ptr != other.ptr;
                }
                Iterator& operator++()
                {
                    ptr = ptr->getNext();
                    return *this;
                }
                Iterator& operator+=(int n)
                {
                    for(int i = 0; i < n; i++)
                    {
                        if(ptr)
                        {
                            ptr = ptr->getNext();
                        }
                    }
                    return *this;
                }
                int operator*()
                {
                    return ptr->getData();
                }
                friend class LinkedList;
        };

        Iterator begin()
        {
            Iterator res;
            res.ptr = start;
            return res;
        }
        Iterator end()
        {
            Iterator res;
            res.ptr = nullptr;
            return res;
        }

};
int main()
{
    LinkedList a;
    for(int i = 0; i < 10; i++)
    {
        a.add(i);
    }

    LinkedList::Iterator end = a.end();
    for(int i : a)
    {
        std::cout << i << " ";
    }

}