/*
 * This program is to demo lab 2
 * @author John Pilli
 * @author Oswaldo Castaneda
 * @version 0.0.0
 *
 * Last updated: 09/01/26
 *
 */

#include <iostream>
#include <iomanip>
using namespace std;

// const assignments
const unsigned long long int MS_PER_SEC = 1000LL;
const unsigned long long int SEC_PER_MIN = 60LL;
const unsigned long long int MIN_PER_HOUR = 60LL;
const unsigned long long int HOUR_PER_DAY = 24LL;
const int NUM_TEST_CASES = 10; // number of test cases for the loop

// calculated variables
unsigned long long int ms_total = 0LL;
unsigned long long int days = 0LL;
unsigned long long int remainingMilliseconds = 0LL;
unsigned long long int hours = 0LL;
unsigned long long int minutes = 0LL;
unsigned long long int seconds = 0LL;

int main()
{
    for (int x = 0; x < NUM_TEST_CASES; x++) // time validation
    {

        unsigned long long int MILLISECONDS;
        unsigned long long int milliseconds1;

        // Prompt user for their number
        std::cout << "Enter a number of milliseconds: ";
        unsigned long long int choice;
        std::cin >> choice;

        // Calculate # of days
        days = choice / (HOUR_PER_DAY * MIN_PER_HOUR * SEC_PER_MIN * MS_PER_SEC);
        remainingMilliseconds = choice % (HOUR_PER_DAY * MIN_PER_HOUR * SEC_PER_MIN * MS_PER_SEC);

        // Caluclate # of hours
        hours = remainingMilliseconds / (MIN_PER_HOUR * SEC_PER_MIN * MS_PER_SEC);
        remainingMilliseconds %= (MIN_PER_HOUR * SEC_PER_MIN * MS_PER_SEC);

        // Calculate # of minutes
        minutes = remainingMilliseconds / (SEC_PER_MIN * MS_PER_SEC);
        remainingMilliseconds %= (SEC_PER_MIN * MS_PER_SEC);

        // Calculate # of seconds
        seconds = remainingMilliseconds / MS_PER_SEC;
        remainingMilliseconds %= MS_PER_SEC;

        // Calculate # of milliseconds
        milliseconds1 = remainingMilliseconds;

        // Display output
        std::cout << choice << " ms = " << days << "d " << setfill(0) << setw(2) << hours << ":" << setfill(0) << setw(2) << minutes << ":" << setfill(0) << setw(2) << seconds << "." << setfill(0) << setw(3) << milliseconds1 << std::endl;
    }
    return 0;
}
