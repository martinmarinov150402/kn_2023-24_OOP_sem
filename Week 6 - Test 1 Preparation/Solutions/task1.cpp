#include <cstring>

struct Point
{
    int x, y;
};

class Field
{
    private:
        int size;
        Point center;
        char ownerName[25];
    
    public:
        char* getOwner();
        Point getCenter() const;
        int getSize() const; 
        Field(int size, Point center, char* ownerName);
};
class Flour
{
    private:
        int type;
        double price;
        int quantity;
        int fieldNumber;   
    
    public:
        int getFieldNumber() const;
        Field getFieldData(Field arr[]) const; 
        int getType() const;
        double getPrice() const;
        int getQuantity() const;
        Flour(int type, double price, int quantity, int fieldNumber);
};

int Flour::getFieldNumber() const
{
    return fieldNumber;
}
int Flour::getType() const
{
    return type;
}
double Flour::getPrice() const
{
    return price;
}
int Flour::getQuantity() const
{
    return quantity;
}

Point Field::getCenter() const
{
    return center;
}

int Field::getSize() const
{
    return size;
}

char* Field::getOwner()
{
    return ownerName;
}

Field Flour::getFieldData(Field arr[]) const
{
    return arr[fieldNumber];
}

Field::Field(int size, Point center, char* ownerName)
{
    this->size = size;
    this->center = center;
    strcpy(this->ownerName, ownerName);
}

Flour::Flour(int type, double price, int quantity, int fieldNumber)
{
    this->type = type;
    this->price = price;
    this->quantity = quantity;
    this->fieldNumber = fieldNumber;
}

int main()
{

}
