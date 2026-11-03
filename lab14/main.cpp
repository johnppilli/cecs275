#include <iostream>
#include "date.h"

using namespace std;

int main()
{
    cout << "=== Constructors ===" << endl;
    Date empty;
    cout << "Default: ";
    empty.displayNumeric();
    Date d1(8, 25, 2025);
    cout << "8/25/2025: ";
    d1.displayNumeric();
    cout << "Invalid tests:" << endl;
    Date bad1(13, 1, 2025);
    Date bad2(2, 30, 2025);
    Date bad3(2, 29, 2023);
    Date bad4(4, 0, 2025);
    Date bad5(1, 1, 0);
    Date leapOk(2, 29, 2024);
    cout << "2/29/2024 (valid): ";
    leapOk.displayNumeric();

    cout << "\n=== Getters / Setters ===" << endl;
    Date d2;
    d2.setYear(2025); // fails, month/day are 0 so the date isn't valid yet
    Date d3(1, 15, 2024);
    cout << "Month " << d3.getMonth() << ", Day " << d3.getDay() << ", Year " << d3.getYear() << endl;
    d3.setMonth(3);
    d3.setDay(31);
    d3.setYear(2025);
    cout << "After sets: ";
    d3.displayNumeric();
    d3.setMonth(4); // 4/31 doesn't exist, rejected
    d3.setDay(32);  // rejected
    d3.setYear(0);  // rejected
    cout << "After bad sets (unchanged): ";
    d3.displayNumeric();

    cout << "\n=== Display formats ===" << endl;
    d1.displayNumeric();
    d1.displayLong();
    d1.displayEuro();
    Date d4(1, 5, 2026);
    d4.displayNumeric();
    d4.displayLong();
    d4.displayEuro();

    cout << "\n=== Leap years ===" << endl;
    int years[] = {2000, 1900, 2024, 2025};
    for (int i = 0; i < 4; i++)
    {
        Date d(1, 1, years[i]);
        cout << years[i] << (d.isLeapYear() ? " is" : " is not") << " a leap year" << endl;
    }

    cout << "\n=== Days between ===" << endl;
    cout << "Same date: " << d1.daysBetween(d1) << " (expect 0)" << endl;
    cout << "8/25/2025 to 8/26/2025: " << d1.daysBetween(Date(8, 26, 2025)) << " (expect 1)" << endl;
    cout << "1/1/2025 to 3/1/2025: " << Date(1, 1, 2025).daysBetween(Date(3, 1, 2025)) << " (expect 59)" << endl;
    cout << "1/1/2024 to 3/1/2024: " << Date(1, 1, 2024).daysBetween(Date(3, 1, 2024)) << " (expect 60)" << endl;
    cout << "12/31/2024 to 1/1/2025: " << Date(12, 31, 2024).daysBetween(Date(1, 1, 2025)) << " (expect 1)" << endl;
    cout << "1/1/2000 to 1/1/2025: " << Date(1, 1, 2000).daysBetween(Date(1, 1, 2025)) << " (expect 9132)" << endl;
    cout << "Reversed order: " << Date(1, 1, 2025).daysBetween(Date(1, 1, 2000)) << " (expect 9132)" << endl;

    cout << "\n=== Increment ===" << endl;
    Date inc1(12, 31, 2025);
    inc1.increment();
    cout << "12/31/2025 + 1 = ";
    inc1.displayNumeric();
    Date inc2(2, 28, 2024);
    inc2.increment();
    cout << "2/28/2024 + 1 = ";
    inc2.displayNumeric();
    Date inc3(2, 28, 2025);
    inc3.increment();
    cout << "2/28/2025 + 1 = ";
    inc3.displayNumeric();
    Date inc4(4, 30, 2025);
    inc4.increment();
    cout << "4/30/2025 + 1 = ";
    inc4.displayNumeric();
    Date inc5(8, 25, 2025);
    inc5.increment();
    cout << "8/25/2025 + 1 = ";
    inc5.displayNumeric();

    cout << "\n=== Decrement ===" << endl;
    Date dec1(1, 1, 2026);
    dec1.decrement();
    cout << "1/1/2026 - 1 = ";
    dec1.displayNumeric();
    Date dec2(3, 1, 2024);
    dec2.decrement();
    cout << "3/1/2024 - 1 = ";
    dec2.displayNumeric();
    Date dec3(3, 1, 2025);
    dec3.decrement();
    cout << "3/1/2025 - 1 = ";
    dec3.displayNumeric();
    Date dec4(5, 1, 2025);
    dec4.decrement();
    cout << "5/1/2025 - 1 = ";
    dec4.displayNumeric();
    Date dec5(8, 25, 2025);
    dec5.decrement();
    cout << "8/25/2025 - 1 = ";
    dec5.displayNumeric();

    cout << "\n=== Compare ===" << endl;
    cout << "8/25/2025 vs 8/24/2025: " << Date(8, 25, 2025).compare(Date(8, 24, 2025)) << " (expect 1)" << endl;
    cout << "8/25/2025 vs 8/25/2025: " << Date(8, 25, 2025).compare(Date(8, 25, 2025)) << " (expect 0)" << endl;
    cout << "8/25/2025 vs 9/1/2025: " << Date(8, 25, 2025).compare(Date(9, 1, 2025)) << " (expect -1)" << endl;
    cout << "8/25/2025 vs 1/1/2026: " << Date(8, 25, 2025).compare(Date(1, 1, 2026)) << " (expect -1)" << endl;
    cout << "8/25/2025 vs 12/31/2024: " << Date(8, 25, 2025).compare(Date(12, 31, 2024)) << " (expect 1)" << endl;

    cout << "\n=== Comparison operators ===" << endl;
    Date a(1, 1, 2025);
    Date b(6, 15, 2025);
    cout << "a == b: " << (a == b) << " (expect 0)" << endl;
    cout << "a < b: " << (a < b) << " (expect 1)" << endl;
    cout << "a > b: " << (a > b) << " (expect 0)" << endl;
    cout << "a == a: " << (a == a) << " (expect 1)" << endl;

    cout << "\n=== Date + n and Date - n ===" << endl;
    cout << "12/31/2025 + 1 = ";
    (Date(12, 31, 2025) + 1).displayLong(); // expect January 1, 2026
    cout << "2/28/2024 + 1 = ";
    (Date(2, 28, 2024) + 1).displayLong(); // expect February 29, 2024
    cout << "1/1/2025 + 365 = ";
    (Date(1, 1, 2025) + 365).displayLong(); // expect January 1, 2026
    cout << "1/1/2026 - 1 = ";
    (Date(1, 1, 2026) - 1).displayLong(); // expect December 31, 2025
    cout << "3/1/2024 - 1 = ";
    (Date(3, 1, 2024) - 1).displayLong(); // expect February 29, 2024
    cout << "8/25/2025 - 0 = ";
    (Date(8, 25, 2025) - 0).displayLong(); // expect August 25, 2025
    Date orig(8, 25, 2025);
    Date later = orig + 10;
    cout << "orig after orig + 10 (unchanged): ";
    orig.displayLong(); // expect August 25, 2025
    cout << "later = orig + 10: ";
    later.displayLong(); // expect September 4, 2025

    return 0;
}
