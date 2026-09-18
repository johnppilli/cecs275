/*
 * This is implementation file for utilities.h
 *
 *
 *
 *
 *
 *
 */

/*
 * dont provide main in here, u would just copy and paste
 * whatever is in utilities.h into here and then
 * implement the functions in here
 *
 * this contains the actual instructions for how to use the
 *functions from the .h file
 *
 */

#include "utilities.h"
#include <string>
#include <random> //new directive
#include <cctype>

using namespace std;

/*
 * random number generator function that takes lower/upper bounds and
 * returns it as a string
 *
 */

string randomNumberInRange(int lowerBound, int upperBound) // can use this for a lot of different things
{
    return to_string(lowerBound + rand() % (upperBound - lowerBound + 1)); // formula for a random number in any range that you want
}

string generatePhoneNumber(int phoneFormatType)
{
    /*
     * this block replaces what we have down below, shortens the code
     * by creating a function that generates a random number in any range
     * we want
     */

    string areaCode = randomNumberInRange(100, 900);
    string phonePrefix = randomNumberInRange(100, 900);
    string lineNumber = randomNumberInRange(1000, 9000);

    switch (phoneFormatType)
    {
    case 0:
        return areaCode + "-" + phonePrefix + "-" + lineNumber;
    case 1:
        return "(" + areaCode + ")-" + phonePrefix + "-" + lineNumber;
    case 2:
        return "1-" + areaCode + "-" + phonePrefix + "-" + lineNumber;
    default:
        return "000-000-0000";
    }
}

// to_string is a function in string class that allows you to convert an int to a string

bool isVowelLetter(char c) // treats y as a vowel, matches the original vowels set
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'; // checks if letter is a vowel
}

string randomName(int length)
{
    string name = "";

    int random = rand() % 2;
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        if (random < 2 && count < 2) // random = always true, count increments by 1
        {
            char c;
            do
            {
                c = 'a' + rand() % 26;
            } while (isVowelLetter(c)); // keep rolling until it's a consonant
            name = name + c;
            count++;
        }
        else // when consonents are more than 2 in a row, drop to vowels and reset count until length is reached
        {
            char c;
            do
            {
                c = 'a' + rand() % 26;
            } while (!isVowelLetter(c)); // keep rolling until it's a vowel
            name = name + c;
            count = 0;
        }
        random = rand() % 2;
    }

    for (int i = 0; i < 2; i++)
    {
        name = name + (char)('0' + rand() % 10);
        /*
         * same ASCII trick but for digits: '0' = 48, so adding a random 0-9
         * offset gives a random digit character
         */
    }

    return name;
}

string randomWord(int length) // generates a random string of letters, @param length the number of letters in thew ord
{
    string word = "";
    for (int i = 0; i < length; i++)
    {
        word = word + (char)('a' + rand() % 26);
        /*
         * chars are stored as ASCII numbers ('a' = 97, 'z' = 122), so adding
         * a random 0-25 offset to 'a' picks random lowercase letter
         */
    }
    return word;
}

string randomCapitalLetter(int length) // generates a random string of capital letters of a given length, @param length the number of letters in the string
{
    string letter = "";
    for (int i = 0; i < length; i++)
    {
        letter = letter + (char)('A' + rand() % 26);
        /*
         * same ASCII trick
         */
    }
    return letter;
}

string generateEmail() // generates a random fake email address using both random word and number
{
    string username = randomWord(6);
    string numberPart = randomNumberInRange(10, 99);

    return username + numberPart + "@gmail.com";
}

string generateAddress() // generates a random fake street address, city, state, and zip code using random letters instead of real names
{
    string houseNumber = randomNumberInRange(100, 9999);
    string streetName = randomWord(6);
    streetName[0] = toupper(streetName[0]);

    string city = randomWord(7);
    city[0] = toupper(city[0]);

    string state = randomCapitalLetter(2);
    string zipCode = randomNumberInRange(10000, 99999);

    return houseNumber + " " + streetName + " St, " + city + ", " + state + " " + zipCode;
}

string generateCreditCard() // generates a random 16 digit test credit card number formatted in groups of 4
{
    string part1 = randomNumberInRange(1000, 9999);
    string part2 = randomNumberInRange(1000, 9999);
    string part3 = randomNumberInRange(1000, 9999);
    string part4 = randomNumberInRange(1000, 9999);

    return part1 + "-" + part2 + "-" + part3 + "-" + part4;
}

string generateCVV() // generates a random 3 digit cvv
{
    return randomNumberInRange(100, 999);
}

string generateDate() // generates a random expiration date for the credit card in month/year format
{
    string month = randomNumberInRange(1, 12);
    string year = randomNumberInRange(27, 37);

    return month + "/" + year;
}
