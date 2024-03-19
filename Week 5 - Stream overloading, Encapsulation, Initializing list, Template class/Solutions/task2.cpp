#include <iostream>
#include <cstring>

class MyString
{
    private:
        size_t capacity;
        char* arr;
        void copy(const MyString& other);
        void free();

    public:
        MyString();
        ~MyString();
        MyString(const MyString& other);
        MyString& operator=(const MyString& other);
        char& operator[](size_t idx);
        MyString operator+(const MyString& other);
        MyString operator+(char* other);
        MyString& operator+=(const MyString& other);
        MyString& operator+=(char* other);

    friend std::istream& operator>>(std::istream& in, MyString& a);
    friend std::ostream& operator<<(std::ostream& out, const MyString& other);

};

void MyString::copy(const MyString& other)
{
    capacity = other.capacity;
    arr = new char[capacity];
    strcpy(arr, other.arr);    
}
void MyString::free()
{
    delete[] arr;
}
MyString::MyString()
{
    capacity = 10;
    arr = new char[capacity];
    strcpy(arr, "");
}
MyString::~MyString()
{
    free();
}
MyString::MyString(const MyString& other)
{
    copy(other);
}
MyString& MyString::operator=(const MyString& other)
{
    if(this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}
char& MyString::operator[](size_t idx)
{
    return arr[idx];
}
MyString MyString::operator+(const MyString& other)
{
    MyString c(*this);
    if(c.capacity < strlen(arr) + strlen(other.arr) + 1)
    {
        c.capacity = strlen(arr) + strlen(other.arr) + 1;
        char* arr2 = new char[c.capacity];
        strcpy(arr2, c.arr);
        c.free();
        c.arr = arr2;
    }
    c.arr = strcat(c.arr, other.arr);
    c.arr[strlen(c.arr)] = '\0';
    return c;

}
MyString MyString::operator+(char* other)
{
    MyString c(*this);
    if(c.capacity < strlen(arr) + strlen(other) + 1)
    {
        c.capacity = strlen(arr) + strlen(other) + 1;
        char* arr2 = new char[c.capacity];
        strcpy(arr2, c.arr);
        c.free();
        c.arr = arr2;
    }
    c.arr = strcat(c.arr, other);
    c.arr[strlen(c.arr)] = '\0';
    return c;

}

MyString& MyString::operator+=(const MyString& other)
{
    if(capacity < strlen(arr) + strlen(other.arr) + 1)
    {
        capacity = strlen(arr) + strlen(other.arr) + 1;
        char* arr2 = new char[capacity];
        strcpy(arr2, arr);
        free();
        arr = arr2;
    }
    arr = strcat(arr, other.arr);
    arr[strlen(arr)] = '\0';
    return *this;

}
MyString& MyString::operator+=(char* other)
{
    if(capacity < strlen(arr) + strlen(other) + 1)
    {
        capacity = strlen(arr) + strlen(other) + 1;
        char* arr2 = new char[capacity];
        strcpy(arr2, arr);
        free();
        arr = arr2;
    }
    arr = strcat(arr, other);
    arr[strlen(arr)] = '\0';
    return *this;

}

std::ostream& operator<<(std::ostream& out, const MyString& obj)
{
    out << obj.arr;
    return out;
}
std::istream& operator>>(std::istream& in, MyString& obj)
{
    char c;
    do
    {
        c = in.get();
        if(c == '\n')
        {
            continue;
        }
        if(strlen(obj.arr) + 1 == obj.capacity)
        {
            obj.capacity *= 2;
            char* arr2 = new char[obj.capacity];
            strcpy(arr2, obj.arr);
            delete[] obj.arr;
            obj.arr = arr2;
        }
        obj.arr[strlen(obj.arr)] = c;
        obj.arr[strlen(obj.arr)] = '\0';
    } 
    while (c != '\n');
    return in;
}


int main()
{
    MyString a;
    a = a + "asd";
    MyString b;
    b = b + a;
    b += a;
    b += "fsd";
    std::cout << b << std::endl;
    MyString c;
    std::cin >> c;
    std::cout << c << std::endl;
}