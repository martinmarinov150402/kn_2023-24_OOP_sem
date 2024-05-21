#include <iostream>

template <typename T>
class Sequence
{
    private:
        size_t k;
        T *arr;
        void copy(const Sequence& other)
        {
            k = other.k;
            arr = new T[other.k];
            for(int i = 0; i < k; i++)
            {
                arr[i] = other->arr[i];
            }
        }

    public:
        Sequence(T a0, size_t k, T(*next)(T))
        {
            arr = new T[k];
            this->k = k;
            arr[0] = a0;
            for(int i = 1; i < k; i++)
            {
                arr[i] = next(arr[i - 1]);
            }
        }
        Sequence(const Sequence& other)
        {
            copy(other);
        }
        Sequence& operator=(const Sequence& other)
        {
            if(this != &other)
            {
                delete[] arr;
                copy(other);
            }
            return *this;
        }
        ~Sequence()
        {
            delete[] arr;
        }
        T operator[](size_t idx)
        {
            return arr[idx];
        }

        class Iterator
        {
            private:
                T* ptr;

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
                    ptr++;
                    return *this;
                }
                Iterator& operator+=(size_t num)
                {
                    ptr += num;
                    return *this;
                }
                T operator*()
                {
                    return *ptr;
                }

            friend class Sequence;
        };

        Iterator begin()
        {
            Iterator res;
            res.ptr = arr;
            return res;
        }

        Iterator end()
        {
            Iterator res;
            res.ptr = arr + k;
            return res;
        }

};

int plus2(int i )
{
    return i + 2;
}
int main()
{
    Sequence<int> seq(0, 10, plus2);
    /*for(int i = 0; i < 10; i++)
    {
        std::cout << seq[i] << " ";
    }*/
    for(int i : seq)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}