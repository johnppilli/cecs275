/*
 *
 *
 *
 *
 *
 *
 */

#include "utilities.h"
#include <string>
#include <random>
#include <cctype>

using namespace std;

string randomWord(int length)
{
    string word = "";
    for (int i = 0; i < length; i++)
    {
        word = word + (char)('a' + rand() % 26);
    }
    return word;
}

string randomNumberInRange(int lowerBound, int upperBound)
{
    return to_string(lowerBound + rand() % (upperBound - lowerBound + 1));
}

/*
 *
 *
 */
string generateRandomUsername()
{
    string randomLength = randomNumberInRange(6, 12); // random length between 6-12 for username
    int length = stoi(randomLength);                  // convert it from a string to an int

    string username = randomWord(length);           // put that length parameter into the randomWord function
    string numberPart = randomNumberInRange(1, 99); // generate numbers at the end of the username

    return username + numberPart;
}

string generateRandomPassword()
{

    // generate one by one: lowercase, uppercase number
    // length = 12
    string firstnumber1 = randomNumberInRange(0, 9);

    string firstnumber2 = randomNumberInRange(0, 9);

    string firstnumber3 = randomNumberInRange(0, 9);

    string firstnumber4 = randomNumberInRange(0, 9);

    return "";
}

string randomLowercaseLetter()
{
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string lowercaseletter = ""; // intialize with empty string
    lowercaseletter += alphabet[rand() % 26]; //append the string with random letter from laphabet

    return lowercaseletter;
}

string randomCapitalLetter(int length)
{
}

/*
 *
 * Used for both an assignment's max scores and the students max score;
 * you would just keep the max same for the both uses but change the minimum to whatever the
 * the assignment is worth, (assignment can't be worth 0 points)
 *
 *
string generateRandomScores(int min, int max)
{
}
*/
