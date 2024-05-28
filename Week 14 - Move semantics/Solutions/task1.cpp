#include <iostream>
#include <cstring>

const int DEFAULT_CAPACITY = 10;
class Processor
{
    //тактова честота, брой ядра и размер на КЕШ паметта

    private:
        int speed;
        int cores;
        int cacheSize;

    public:
        int getSpeed() {return speed;};
        void setSpeed(int speed) {this->speed = speed;};     
        int getCores() {return cores;};
        void setCores(int cores) {this->cores = cores;};     
        int getCacheSize() {return cacheSize;};
        void setCacheSize(int cacheSize) {this->cacheSize = cacheSize;};
        Processor() = default;
        Processor(int speed, int cores, int cacheSize)
        {
            this->speed = speed;
            this->cores = cores;
            this->cacheSize = cacheSize;
        }
        void upgrade(int speedDelta, int coresDelta, int cacheSizeDelta)
        {
            speed += speedDelta;
            cores += coresDelta;
            cacheSize += cacheSizeDelta;
        }
};
class Laptop
{
    private:
        char* brand;
        char* model;
        size_t brand_capacity, model_capacity;
        int price;
        int screenSize;
        Processor processor;
        int ram;
        int batteryCapacity;
        void copy(const Laptop& other)
        {
            brand_capacity = other.brand_capacity;
            model_capacity = other.model_capacity;
            brand = new char[brand_capacity];
            model = new char[model_capacity];
            strcpy(brand, other.brand);
            strcpy(model, other.model);
            price = other.price;
            screenSize = other.screenSize;
            processor = other.processor;
            ram = other.ram;
            batteryCapacity = other.batteryCapacity;
        }
        void move(Laptop&& other)
        {

            brand_capacity = other.brand_capacity;
            model_capacity = other.model_capacity;
            brand = other.brand;
            model = other.model;
            price = other.price;
            screenSize = other.screenSize;
            processor = other.processor;
            ram = other.ram;
            batteryCapacity = other.batteryCapacity;
        }
        void free()
        {
            delete[] brand;
            delete[] model;
        }

    public:
        Laptop(char* brand, char* model, int price, int screenSize, Processor&& processor, int ram, int batteryCapacity)
        {
            this->brand_capacity = strlen(brand) + 1;
            this->brand = new char[brand_capacity];
            strcpy(this->brand, brand);
            this->model_capacity = strlen(model) + 1;
            this->model = new char[model_capacity];
            strcpy(this->model, model);
            this->price = price;
            this->screenSize = screenSize;
            this->processor = std::move(processor);
            this->ram = ram;
            this->batteryCapacity = batteryCapacity;
        }
        Laptop()
        {
            brand_capacity = DEFAULT_CAPACITY;
            model_capacity = DEFAULT_CAPACITY;
            brand = new char[brand_capacity];
            model = new char[model_capacity];
        }
        Laptop(const Laptop& other)
        {
            copy(other);
        }
        Laptop& operator=(const Laptop& other)
        {
            if(this != &other)
            {
                free();
                copy(other);
            }
            return *this;
        }
        ~Laptop()
        {
            free();
        }
        Laptop(Laptop&& other)
        {
            move(std::move(other));
        }
        Laptop& operator=(Laptop&& other)
        {
            if(this != &other)
            {
                free();
                move(std::move(other));
            }
            return *this;
        }
        void ramUpgrade(int ramDelta)
        {
            ram += ramDelta;
        }
        void processorUpgrade(int speedDelta, int coresDelta, int cacheSizeDelta)
        {
            processor.upgrade(speedDelta, coresDelta, cacheSizeDelta);
        }
        void printInformation(std::ostream& stream)
        {
            stream << "Laptop Information"                                 << std::endl
                   << "Brand: "                << brand                    << std::endl
                   << "Model: "                << model                    << std::endl
                   << "Price: "                << price                    << std::endl
                   << "Screen size: "          << screenSize               << std::endl
                   << "Processor Information:"                             << std::endl
                   << "Processor speed: "      << processor.getSpeed()     << std::endl
                   << "Processor cores: "      << processor.getCores()     << std::endl
                   << "Processor cache: "      << processor.getCacheSize() << std::endl
                   << "==========================="                        << std::endl
                   << "Ram: "                  << ram                      << std::endl
                   << "Battery capacity: "     << batteryCapacity          << std::endl;

        }
};

int main()
{
    Processor pr(4, 4, 5);
    Laptop i("Lenovo", "ThinkPad T570", 1300, 15, std::move(pr) , 8, 5400);
    i.printInformation(std::cout);
    i.processorUpgrade(1,0,0);
    i.ramUpgrade(24);
    i.printInformation(std::cout);

}