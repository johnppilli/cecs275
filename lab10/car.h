#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
private:
    std::string color;
    std::string engineType;
    int year;
    std::string make;
    std::string model;

public:
    Car(); // default constructor
    /*
     *
     * Overloaded constructor to intialize a car with provided attributes
     * @param
     * @param
     * @param
     *
     *
     */
    Car(std::string mColor, std::string mEngineType, int mYear, std::string mMake, std::string mModel);

    // Setters
    void setColor(std::string mColor);
    void setEngineType(std::string mEngineType);
    void setYear(int mYear);
    void setMake(std::string mMake);
    /*
     * Set the model value
     * @param mModel a car model
     *
     */
    void setModel(std::string mModel);

    // Getters
    std::string getColor() const;
    std::string getEngineType() const;
    int getYear() const;
    std::string getMake() const;
    std::string getMode() const;

    // Functionality
    void drive();
    void reverse();
    void left();
    void right();
    friend ostream& operator<<(ostream&out, const Car& aCar) //?????
}
