#include "task2.cpp"

class TouristPool
{
    private: 
        size_t size;
        Tourist tourists[200];

    public:
        void printAll() const;
        TouristPool();
        void pushTourist(Tourist);
};

void TouristPool::printAll() const
{
    for(size_t i = 0; i < size; i++)
    {
        tourists[i].timeToFree();
    }
}
TouristPool::TouristPool()
{
    size = 0;
}
void TouristPool::pushTourist(Tourist a)
{
    if(size < 200)
    {
        tourists[size++] = a;
    }
}

int main()
{
    Tourist vankata, peshu("Peshu", "Sofia", "CB8567AH", 6, "Magistralna-Marmarlijska"), lovchanliqta("Goshu", "Lovech", "OB8746AT", 10, "Gurko-Krajbrezhna");
    TouristPool pool;
    pool.pushTourist(peshu);
    pool.pushTourist(vankata);
    pool.pushTourist(lovchanliqta);
    pool.printAll();
}
