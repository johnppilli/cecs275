#include "car.h"
#include <string>
#include <iostream>

using namespace std;

Car::Car() // default constructor
{
    color = "white";
    engineType = "V10";
    year = 2027;
    make = "Nissan";
    model = "Xterra";
}
Car::Car(std::string mColor, std::string mEngineType, int mYear, std::string mMake, std::string mModel)
{
    color = mColor;
    engineType = mEngineType;
    year = mYear;
    make = mMake;
    model = mModel;
} // Overloaded constructor

Car::~Car()
{
    cout << "Destorying a car" << endl;
}

// Setters
void Car::setColor(std::string mColor)
{
    color = mColor;
}
void Car::setEngineType(std::string mEngineType)
{
    engineType = mEngineType;
}
void Car::setYear(int mYear)
{
    year = mYear;
}
void Car::setMake(std::string mMake)
{
    make = mMake;
}
void Car::setModel(std::string mModel)
{
    model = mModel;
}

// Getters
std::string Car::getColor() const
{
    return color;
}
std::string Car::getEngineType() const
{
    return engineType;
}
int Car::getYear() const
{
    return year;
}
std::string Car::getMake() const
{
    return make;
}
std::string Car::getMode() const
{
    return model;
}

// Functionality
void Car::drive()
{
    cout << "Gear in Drive mode" << endl;
}
void Car::reverse()
{
    cout << "Reversing..." << endl;
}
void Car::left()
{
    cout << "Turn left..." << endl;
}
void Car::right()
{
    cout << "Turn right..." << endl;
}

ostream &operator<<(ostream &out, const Car &aCar)
{
    out << "Color: " << aCar.color << endl;
    out << "Year: " << aCar.year << endl;
    out << "Engine Type: " << aCar.engineType << endl;
    out << "Make: " << aCar.make << endl;
    out << "Model: " << aCar.model << endl;
    return out;
}
