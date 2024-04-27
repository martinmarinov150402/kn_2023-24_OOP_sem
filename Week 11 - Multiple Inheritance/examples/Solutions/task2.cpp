#include <iostream>
#include <cstring>

class Item
{
    private:
        size_t nameCap;
        char* name;
    
    public:
        virtual void ListContents() = 0;
        char* getName()
        {
            return name;
        }
        void setName(char *name)
        {
            if(strlen(name) >= nameCap)
            {
                nameCap = strlen(name) + 1;
                delete[] this->name;
                this->name = new char[nameCap];
            }
            strcpy(this->name, name);
        }
        virtual ~Item()
        {
            delete[] name;
        }
        virtual Item* clone() = 0;
        virtual bool isDocument() = 0;
};

class TextDocument : public Item
{
    private:
        char* content;
        size_t cap;
    public: 
        TextDocument()
        {
            cap = 10;
            content = new char[10];
        }
        ~TextDocument()
        {
            delete[] content;
        }
        Item* clone() override
        {
            TextDocument* result = new TextDocument();
            result->setName(this->getName());
            result->cap = this->cap;
            result->content = new char[this->cap];
            strcpy(result->content, this->content);
            return ((Item*)result);
        }
        void ListContents() override
        {
            std::cout << content << std::endl;
        }
        bool isDocument() override
        {
            return true;
        }
        
};

class Folder : public Item
{
    private:
        size_t size;
        size_t cap;
        Item** items;

    public:
        Folder()
        {
            cap = 10;
            size = 0;
            items = new Item*[10];
        }
        ~Folder()
        {
            for(int i = 0; i < size; i++)
            {
                delete items[i];
            }
            delete[] items;
        }
        void add(Item* item)
        {
            if(size == cap)
            {
                cap *= 2;
                Item** tmp = new Item*[cap];
                for(int i = 0; i < size; i++)
                {
                    tmp[i] = items[i];
                }
                delete[] items;
                items = tmp;
            }
            items[size++] = item;
        }
        Item* clone() override
        {
            Folder* folder = new Folder();
            folder->size = this->size;
            folder->cap = this->cap;
            folder->items = new Item*[this->cap];
            for(int i = 0; i < folder->size; i++)
            {
                folder->items[i] = this->items[i]->clone();
            }
            return (Item*)folder;
        }
        void ListContents()
        {
            for(int i = 0; i < size; i++)
            {
                if(items[i]->isDocument())
                {
                    std::cout << items[i]->getName() << std::endl;
                }
                else 
                {
                    items[i]->ListContents();
                }
            }
        }
        bool isDocument() override
        {
            return false;
        }
};
int main()
{
    Folder* folder = new Folder();
    folder->setName("Danni za organizaciqta");
    Item* doc = new TextDocument();
    doc->setName("Uchreditelen akt");
    Folder* emps = new Folder(), *depts = new Folder();
    emps->setName("Slujiteli");
    depts->setName("Otdeli");
    Item *mi = new TextDocument(), *im = new TextDocument(), *pr = new TextDocument();
    mi->setName("Maria Ivanova");
    im->setName("Ivanka Marinova");
    pr->setName("Proizvodstvo");
    emps->add(mi);
    emps->add(im);
    depts->add(pr);

    folder->add(doc);
    folder->add(emps);
    folder->add(depts);

    folder->ListContents();
}