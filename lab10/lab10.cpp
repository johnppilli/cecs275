#include <iostream>
#include "car.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Car nissan;
    Car bmw("black", "V6", 2026, "BMW", "X7");
    bmw.setColor("white");
    cout << nissan.getYear() << endl;

    bmw.reverse();
    bmw.drive();
    bmw.left();
    bmw.right();

    Car *toyota = new Car("green", "V8", 2027, "Toyota", "Tundra");
    toyota->drive();
    cout << bmw << nissan << *toyota << endl;
    return 0;
}
