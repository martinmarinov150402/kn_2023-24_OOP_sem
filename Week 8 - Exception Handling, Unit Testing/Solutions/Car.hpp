#include <cstring>
#include <iostream>
class Car
{
    private: 
        char brand[31];
        char model[31];
        int id;
        int avgSpeed;
        int distance;

    public:
        int drive(int distance);
        Car(char brand[], char model[], int avgSpeed);
        bool operator==(const Car& other);
        int getId() { return id; }
        int getAvgSpeed() { return avgSpeed; }
        int getDistance() { return distance; }
        char* getBrand() {return brand;}
        char* getModel() { return model; }
        
        void setBrand(char* brand) { strcmp(this->brand, brand);}
        void setModel(char* model) { strcmp(this->model, model);}
        void setAvgSpeed(int avgSpeed) {this->avgSpeed = avgSpeed;}
        void setDistance(int distance) {this->distance = distance;}
        void setId() {this->id = 5;}

    friend std::istream& operator>>(std::istream& in, Car& other);
};

std::istream& operator>>(std::istream& in, Car& other)
{
    char arr[31];
    in >> arr;
    other.setBrand(arr);
    in >> arr;
    other.setModel(arr);
    int avgSpeed;
    in >> avgSpeed;
    other.setAvgSpeed(avgSpeed);
    other.setDistance(0);
    other.setId();
    return in;
}
std::ostream& operator<<(std::ostream& out, Car& other)
{
    out << "Id: "            << other.getId()       << std::endl
        << "Brand: "         << other.getBrand()    << std::endl
        << "Model: "         << other.getModel()    << std::endl
        << "Average speed: " << other.getAvgSpeed() << std::endl
        << "Distance: "      << other.getDistance() << std::endl;
    
    return out;    
}