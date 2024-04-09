#include "Car.hpp"
#include <cstring>
#include <iostream>

int Car::drive(int distance)
{
    int result =  distance / std::max((avgSpeed - (this->distance/ 100) - (distance/100) / 2), avgSpeed / 2);
    this->distance += distance;
    return result;
}
bool Car::operator==(const Car& other)
{
    return strcmp(brand, other.brand) == 0 && strcmp(model, other.model) == 0;
}

Car::Car(char brand[], char model[], int avgSpeed)
{
    strcpy(this->brand, brand);
    strcpy(this->model, model);
    this->avgSpeed = avgSpeed;
    this->id = 5;
    this->distance = 0;
}

