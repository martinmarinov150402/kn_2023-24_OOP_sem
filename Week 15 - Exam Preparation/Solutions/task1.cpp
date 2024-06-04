#include <iostream>
#include <cstring>
#include <cmath>
#include <exception>

const int DEFAULT_CAPACITY = 10;

class WorkItem
{
    public:
        virtual bool status(long now) = 0;
        virtual char* name() = 0;
        virtual WorkItem* clone() = 0;
        virtual void print() = 0;
        virtual bool contains(char* name) = 0;
};
class SingleTask : public WorkItem
{
    private:
        char* Name;
        size_t nameCapacity;
        long startTime;
        double duration;
        void copy(const SingleTask& other)
        {
            startTime = other.startTime;
            duration = other.duration;
            nameCapacity = other.nameCapacity;
            Name = new char[nameCapacity];
            strcpy(Name, other.Name);
        }
        void move(SingleTask&& other)
        {

            startTime = other.startTime;
            duration = other.duration;
            nameCapacity = other.nameCapacity;
            Name = other.Name;
        }
        void free()
        {
            delete[] Name;
        }
    
    public:
        bool contains(char* name) override
        {
            return strcmp(name, this->Name) == 0;
        }
        void print() override
        {
            std::cout << Name << std::endl;
        }
        char* name() override
        {
            return Name;
        }
        bool status(long now) override
        {
            return now >= (startTime + ceil(duration / 1000));
        }
        SingleTask()
        {
            nameCapacity = DEFAULT_CAPACITY;
            Name = new char[nameCapacity];
            strcpy(Name, "");   
        }
        SingleTask(const SingleTask& other)
        {
            copy(other);
        }
        SingleTask& operator=(const SingleTask& other)
        {
            if(this != &other)
            {
                free();
                copy(other);
            }
            return *this;
        }
        ~SingleTask()
        {
            free();
        }
        SingleTask(SingleTask&& other)
        {
            move(std::move(other));
        }
        SingleTask& operator=(SingleTask&& other)
        {
            if(this != &other)
            {
                free();
                move(std::move(other));
            }
            return *this;
        }


        WorkItem* clone() override
        {
            return new SingleTask(*this);
        }
};
class TaskGroup : public WorkItem
{
    private:
        char* Name;
        WorkItem** tasks;
        size_t size;
        size_t capacity;
        size_t NameCapacity;
        void print() override
        {
            for(int i = 0; i < size; i++)
            {
                tasks[i]->print();
            }
        }

        void copy(const TaskGroup& other)
        {
            size = other.size;
            capacity = other.capacity;
            NameCapacity = other.NameCapacity;
            tasks = new WorkItem*[capacity];
            for(int i = 0; i < size; i++)
            {
                tasks[i] = other.tasks[i]->clone();
            }
            Name = new char[strlen(other.Name) + 1];
            strcpy(Name, other.Name);
        }
        void move(TaskGroup&& other)
        {

            size = other.size;
            capacity = other.capacity;
            NameCapacity = other.NameCapacity;
            tasks = other.tasks;
            Name = other.Name;
        }
        void free()
        {
            for(int i = 0; i < size; i++)
            {
                delete tasks[i];
            }
            delete[] tasks;
            delete[] Name;
        }

    public:

        bool status(long now) override
        {
            bool result = true;
            for(int i = 0; i < size; i++)
            {
                result = result && tasks[i]->status(now);
            }
            return result;
        }
        char* name() override
        {
            return Name;
        }
        TaskGroup()
        {
            size = 0;
            capacity = DEFAULT_CAPACITY;
            tasks = new WorkItem*[capacity];
        }
        TaskGroup(const TaskGroup& other)
        {
            copy(other);
        }
        TaskGroup& operator=(const TaskGroup& other)
        {
            if(this != &other)
            {
                free();
                copy(other);
            }
            return *this;
        }
        ~TaskGroup()
        {
            free();
        }
        TaskGroup(TaskGroup&& other)
        {
            move(std::move(other));
        }
        TaskGroup& operator=(TaskGroup&& other)
        {
            if(this != &other)
            {
                free();
                move(std::move(other));
            }
            return *this;
        }


        bool contains(char* Name) override
        {
            bool result = false;
            for(int i = 0; i < size; i++)
            {
                result = result || tasks[i]->contains(Name);
            }
            return result;
        }
        void addTask(WorkItem* toBeAdded)
        {
            if(contains(toBeAdded->name()))
            {
                throw std::invalid_argument("Name already existsf");
            }
            if(size == capacity)
            {
                capacity *= 2;
                WorkItem** tmp = new WorkItem*[capacity];
                for(int i = 0; i < size; i++)
                {
                    tmp[i] = tasks[i];
                }
                delete[] tasks;
                tasks = tmp;
            }
            tasks[size++] = toBeAdded->clone();
        }

        class Iterator
        {
            private:
                WorkItem** ptr;
            
            public:
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
                    ++ptr;
                    return *this;
                }
                Iterator& operator--()
                {
                    ptr--;
                    return *this;
                }
                WorkItem* operator*()
                {
                    return *ptr;
                }
                WorkItem* operator->()
                {
                    return *ptr;
                }
                Iterator operator+=(size_t delta)
                {
                    Iterator result;
                    result.ptr = ptr + delta;
                    return result;
                }
                Iterator operator-=(size_t delta)
                {
                    Iterator result;
                    result.ptr = ptr - delta;
                    return result;
                }
                friend class TaskGroup;
        };
        Iterator begin()
        {
            Iterator result;
            result.ptr = tasks;
            return result;
        }
        Iterator end()
        {
            Iterator result;
            result.ptr = tasks + size;
            return result;
        }

};
int main()
{
    
}