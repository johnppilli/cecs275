#include "date.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

static const string MONTH_NAMES[12] = {"January", "February", "March", "April", "May", "June",
                                       "July", "August", "September", "October", "November", "December"};

// Helpers
bool Date::isLeap(int mYear)
{
    return (mYear % 4 == 0 && mYear % 100 != 0) || mYear % 400 == 0; 
}
int Date::daysInMonth(int mMonth, int mYear)
{
    switch (mMonth)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isLeap(mYear) ? 29 : 28;
    default:
        return 31;
    }
}
bool Date::isValid(int mMonth, int mDay, int mYear)
{
    if (mYear < 1 || mMonth < 1 || mMonth > 12)
        return false;
    return mDay >= 1 && mDay <= daysInMonth(mMonth, mYear);
}
int Date::toDays() const
{
    int y = year - 1;
    int days = y * 365 + y / 4 - y / 100 + y / 400; // all full years before this one
    for (int m = 1; m < month; m++)
        days += daysInMonth(m, year);
    return days + day;
}
Date Date::fromDays(int n)
{
    int y = 1;
    while (n > (isLeap(y) ? 366 : 365))
    {
        n -= isLeap(y) ? 366 : 365;
        y++;
    }
    int m = 1;
    while (n > daysInMonth(m, y))
    {
        n -= daysInMonth(m, y);
        m++;
    }
    return Date(m, n, y);
}

// Constructors
Date::Date() // default constructor
{
    month = 0;
    day = 0;
    year = 0;
}
Date::Date(int mMonth, int mDay, int mYear)
{
    if (isValid(mMonth, mDay, mYear))
    {
        month = mMonth;
        day = mDay;
        year = mYear;
    }
    else
    {
        cout << "Invalid date " << mMonth << "/" << mDay << "/" << mYear << ", set to 0/0/0" << endl;
        month = 0;
        day = 0;
        year = 0;
    }
}

// Setters
void Date::setMonth(int mMonth)
{
    if (isValid(mMonth, day, year))
        month = mMonth;
    else
        cout << "Invalid month " << mMonth << ", not changed" << endl;
}
void Date::setDay(int mDay)
{
    if (isValid(month, mDay, year))
        day = mDay;
    else
        cout << "Invalid day " << mDay << ", not changed" << endl;
}
void Date::setYear(int mYear)
{
    if (isValid(month, day, mYear))
        year = mYear;
    else
        cout << "Invalid year " << mYear << ", not changed" << endl;
}

// Getters
int Date::getMonth() const
{
    return month;
}
int Date::getDay() const
{
    return day;
}
int Date::getYear() const
{
    return year;
}

// Display
void Date::displayNumeric() const
{
    cout << setfill('0') << setw(2) << month << "/" << setw(2) << day << "/" << setw(4) << year << setfill(' ') << endl;
}
void Date::displayLong() const
{
    if (month < 1)
    {
        cout << "(no date set)" << endl;
        return;
    }
    cout << MONTH_NAMES[month - 1] << " " << day << ", " << year << endl;
}
void Date::displayEuro() const
{
    if (month < 1)
    {
        cout << "(no date set)" << endl;
        return;
    }
    cout << day << " " << MONTH_NAMES[month - 1] << " " << year << endl;
}

// Functionality
bool Date::isLeapYear() const
{
    return isLeap(year);
}
int Date::daysBetween(const Date &other) const
{
    int diff = toDays() - other.toDays();
    return diff < 0 ? -diff : diff;
}
void Date::increment()
{
    if (year < 1) // unset date, nothing to increment
        return;
    *this = fromDays(toDays() + 1);
}
void Date::decrement()
{
    if (year < 1 || toDays() <= 1) // unset date, or already 01/01/0001
        return;
    *this = fromDays(toDays() - 1);
}
int Date::compare(const Date &other) const
{
    if (year != other.year)
        return year > other.year ? 1 : -1;
    if (month != other.month)
        return month > other.month ? 1 : -1;
    if (day != other.day)
        return day > other.day ? 1 : -1;
    return 0;
}

bool Date::operator==(const Date &other) const
{
    return (compare(other) == 0); //0 is equal
}

bool Date::operator>(const Date &other) const
{
    return (compare(other) == 1); //1 is later
}

bool Date::operator<(const Date &other) const
{
    return (compare(other) == -1); //-1 is earlier
}
