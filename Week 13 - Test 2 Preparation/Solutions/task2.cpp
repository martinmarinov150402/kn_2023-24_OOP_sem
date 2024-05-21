#include <iostream>
#include <string>

class Task
{
    public:
        virtual Task* clone() = 0;
        virtual int totalTime() = 0;
        virtual void printPlan() = 0;
};

class SimpleTask : public Task
{
    private:
        std::string description;
        int time;
    
    public:
        SimpleTask(std::string description, int time)
        {
            this->description = description;
            this->time = time;
        }
        Task* clone() override
        {
            SimpleTask* res = new SimpleTask(description, time);
            return res;
        }
        int totalTime() override
        {
            return time;
        }
        void printPlan() override
        {
            std::cout << description << std::endl;
        }
};

class CompositeTask : public Task
{
    private:
        std::string name;
        Task** arr;
        int size;
        int capacity;
        void copy(const CompositeTask& other)
        {
            size = other.size;
            capacity = other.capacity;
            arr = new Task*[capacity];
            for(int i = 0; i < size; i++)
            {
                arr[i] = other.arr[i]->clone();
            }
        }
        void free()
        {
            for(int i = 0; i < size; i++)
            {
                delete arr[i];
            }
            delete[] arr;
        }
    
    public:
        CompositeTask()
        {
            capacity = 10;
            arr = new Task*[capacity];
        }
        CompositeTask(const CompositeTask& other)
        {
            copy(other);
        }
        CompositeTask& operator=(const CompositeTask& other)
        {
            if(this != &other)
            {
                free();
                copy(other);
            }
            return *this;

        }
        ~CompositeTask()
        {
            free();
        }
        void addTask(Task* task)
        {
            if(size == capacity)
            {
                capacity *= 2;
                Task** tmp = new Task*[capacity];
                for(int i = 0; i < size; i++)
                {
                    tmp[i] = arr[i];
                }
                delete[] arr;
                arr = tmp;
            }
            arr[size++] = task;
        }
        Task* clone() override
        {
            CompositeTask* res = new CompositeTask();
            res->name = name;
            res->size = size;
            res->capacity = capacity;
            for(int i = 0; i < size; i++)
            {
                res->arr[i] = arr[i]->clone();
            }
            return res;
        }

        int totalTime() override
        {
            int res = 0;
            for(int i = 0; i < size; i++)
            {
                res += arr[i]->totalTime();
            }
            return res;
        }

        void printPlan() override
        {
            for(int i = 0; i< size; i++)
            {
                arr[i]->printPlan();
            }
        }
};

int main()
{
    CompositeTask* big = new CompositeTask();
    CompositeTask* writeCode = new CompositeTask();
    SimpleTask* loginPage = new SimpleTask("Login page", 3);
    SimpleTask* contactsPage = new SimpleTask("Create contacts page", 2);
    SimpleTask* contactsList = new SimpleTask("Contacts list", 4);
    writeCode->addTask(loginPage);
    writeCode->addTask(contactsPage);
    writeCode->addTask(contactsList);
    big->addTask(writeCode);

    SimpleTask* testApp = new SimpleTask("Test app", 2);
    big->addTask(testApp);

    CompositeTask* deploy = new CompositeTask();
    SimpleTask* createAWSAccount = new SimpleTask("Create AWS account", 1);
    SimpleTask* runDeployment = new SimpleTask("Run deployment", 1);
    deploy->addTask(createAWSAccount);
    deploy->addTask(runDeployment);

    big->addTask(deploy);
    big->printPlan();

    std::cout << big->totalTime() << std::endl;



}