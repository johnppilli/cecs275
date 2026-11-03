#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
private:
    int month;
    int day;
    int year;

    // Helpers (only used inside the class)
    static bool isLeap(int mYear);
    static bool isValid(int mMonth, int mDay, int mYear);
    static int daysInMonth(int mMonth, int mYear);
    // Number of days since 01/01/0001 (day 1). Lab 14's +, -, ++, -- can reuse these.
    int toDays() const;
    static Date fromDays(int n);

public:
    Date(); // default constructor, sets everything to 0
    /*
     * Overloaded constructor, rejects invalid dates (sets 0/0/0)
     * @param mMonth 1-12
     * @param mDay 1 to number of days in that month
     * @param mYear year greater than 0
     */
    Date(int mMonth, int mDay, int mYear);
    Date(const Date &other);              // copy constructor
    Date &operator=(const Date &other);   // assignment operator

    // Setters (ignore invalid values)
    void setMonth(int mMonth);
    void setDay(int mDay);
    void setYear(int mYear);

    // Getters
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    // Display
    void displayNumeric() const; // 08/25/2025
    void displayLong() const;    // August 25, 2025
    void displayEuro() const;    // 25 August 2025

    // Functionality
    bool isLeapYear() const;
    int daysBetween(const Date &other) const;
    void increment();
    void decrement();
    int compare(const Date &other) const; // 1, 0, or -1
    bool operator==(const Date &other) const;
    bool operator>(const Date &other) const;
    bool operator<(const Date &other) const;
    Date operator+(int n) const; // date n days in the future
    Date operator-(int n) const; // date n days in the past

    friend std::ostream &operator<<(std::ostream &out, const Date &d);

    int operator-(const Date &other) const;

};

#endif
