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
};
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

int main()
{
    Word a;
    Word b("Hello");
    Word c = a + 'a';
    c += 'b';
    Word d("Hello");
    Word e("Aello");
    a.print();
    b.print();
    c.print();
    std::cout << std::boolalpha << (b == d) << std::endl
              << std::boolalpha << (e < d)  << std::endl;


}
