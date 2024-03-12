#include <iostream>
#include <cstring>

class Word
{
    private:
        char word[21];
    
    public:
        char& operator[](int idx);
        Word operator+(char b);
        Word& operator+=(char b);
        bool operator<(const Word& b);
        bool operator==(const Word& b);
        Word();
        Word(const char arr[]);
        void print();
        size_t len();
        char* getWord();
};
char* Word::getWord()
{
    return word;
}
size_t Word::len()
{
    return strlen(word);
}
void Word::print()
{
    std::cout << word << std::endl;
}
char& Word::operator[](int idx)
{
    return word[idx];
}

Word Word::operator+(char b)
{
    Word res(*this);
    if(strlen(word) < 20)
    {
        res.word[strlen(word)] = b;
        res.word[strlen(word) + 1] = '\0';
    }
    return res;
}
Word& Word::operator+=(char b)
{
    int strlenOld = strlen(word);
    if(strlenOld < 20)
    {
        word[strlenOld] = b;
        word[strlenOld + 1] = '\0';
    }
    return *this;
}

bool Word::operator==(const Word& b)
{
    return strcmp(word, b.word) == 0;
}

bool Word::operator<(const Word& b)
{
    return strcmp(word, b.word) < 0;
}

Word::Word()
{
    strcpy(word, "");
}
Word::Word(const char arr[])
{
    if(strlen(arr) > 20)
    {
        strcpy(word, "");   
    }
    else
    {
        strcpy(word, arr);
    }
}

const size_t DEFAULT_CAPACITY = 10;
class Sentance
{
    private:
        size_t capacity;
        char* arr;
        void copy(const Sentance&);
        void free();

    public:
        Sentance();
        Sentance(const Sentance&);
        Sentance& operator=(const Sentance&);
        ~Sentance();
        void addWord(Word&);
        void print();
};

void Sentance::print()
{
    std::cout << arr << std::endl;
}
Sentance::Sentance()
{
    capacity = DEFAULT_CAPACITY;
    arr = new char[capacity];
    strcpy(arr, "");
}

void Sentance::copy(const Sentance& other)
{
    capacity = other.capacity;
    arr = new char[capacity];
    strcpy(arr, other.arr);
}
void Sentance::free()
{
    delete[] arr;
}
Sentance::Sentance(const Sentance& other)
{
    copy(other);
}

Sentance& Sentance::operator=(const Sentance& other)
{
    if(this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}
Sentance::~Sentance()
{
    free();
}

void Sentance::addWord(Word& word)
{
    if(strlen(arr) + word.len() > capacity)
    {
        char* newArr = new char[strlen(arr) + word.len() + 1];
        strcpy(newArr, arr);
        delete[] arr;
        arr = newArr;
    }
    arr = strcat(arr, word.getWord());
    arr[strlen(arr)] = '\0';
}

int main()
{
    Word a;
    Word b("Hello");
    Word c = a + 'a';
    c += 'b';
    Word d("Hello");
    Word e("Aello");

    Sentance ex;
    ex.addWord(b);
    ex.addWord(c);
    ex.addWord(e);
    ex.print();


}
