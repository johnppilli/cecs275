/**
 * utilities.cpp
 * Implementation file for utilities.h. Contains the random data generators
 * for the fake users/scores files, the percentage and letter-grade
 * calculations for the score report, and small file/output helpers.
 * See utilities.h for the full description of each function.
 *
 * @author John Pilli
 * @author Oswaldo Castaneda
 * @version 0.0.0
 */

#include "utilities.h"
#include <string>
#include <random>
#include <cctype>
#include <iostream>
#include <fstream>

using namespace std;

// Builds a random lowercase string with the given number of letters.
string randomWord(int length)
{
    string word = "";
    for (int i = 0; i < length; i++)
    {
        word = word + (char)('a' + rand() % 26);
    }
    return word;
}

// Returns a random whole number from lowerBound to upperBound (inclusive) as a string.
string randomNumberInRange(int lowerBound, int upperBound)
{
    return to_string(lowerBound + rand() % (upperBound - lowerBound + 1));
}

// Fake username: random 6-12 letter word plus a random number from 1 to 99.
string generateRandomUsername()
{
    string randomLength = randomNumberInRange(6, 12); // random length between 6-12 for username
    int length = stoi(randomLength);                  // convert it from a string to an int

    string username = randomWord(length);           // put that length parameter into the randomWord function
    string numberPart = randomNumberInRange(1, 99); // generate numbers at the end of the username

    return username + numberPart;
}

// Fake 12-character password: digit + lowercase + uppercase, repeated 4 times.
string generateRandomPassword()
{
    // generate one by one: lowercase, uppercase number
    // length = 12
    string firstnumber1 = randomNumberInRange(0, 9);
    string lowerletter1 = randomLowerCaseLetter();
    string upperletter1 = randomCapitalLetter();

    string firstnumber2 = randomNumberInRange(0, 9);
    string lowerletter2 = randomLowerCaseLetter();
    string upperletter2 = randomCapitalLetter();

    string firstnumber3 = randomNumberInRange(0, 9);
    string lowerletter3 = randomLowerCaseLetter();
    string upperletter3 = randomCapitalLetter();

    string firstnumber4 = randomNumberInRange(0, 9);
    string lowerletter4 = randomLowerCaseLetter();
    string upperletter4 = randomCapitalLetter();

    return firstnumber1 + lowerletter1 + upperletter1 + firstnumber2 + lowerletter2 + upperletter2 + firstnumber3 + lowerletter3 + upperletter3 + firstnumber4 + lowerletter4 + upperletter4;
}

// Returns one random lowercase letter, picked from an alphabet array.
string randomLowerCaseLetter()
{
    char loweralphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string lowercaseletter = "";                   // intialize with empty string
    lowercaseletter += loweralphabet[rand() % 26]; // append the string with random letter from laphabet

    return lowercaseletter;
}

// Returns one random uppercase letter, picked from an alphabet array.
string randomCapitalLetter()
{
    char upperalphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string uppercaseletter = "";
    uppercaseletter += upperalphabet[rand() % 26];

    return uppercaseletter;
}

// Random score between min and max; used for both max scores and student scores.
string generateRandomScores(int min, int max)
{
    string randomScore = randomNumberInRange(min, max);

    return randomScore;
}

// Sums (score / max * 100) for each assignment in one category's index range.
double sumCategoryPercentages(int studentScores[], int maxScores[], int startIndex, int count)
{

    double PercentSum = 0;
    for (int i = startIndex; i < startIndex + count; i++)
    {
        PercentSum = PercentSum + (((double)studentScores[i] / maxScores[i]) * 100); // converts the answer to be in a double(with dcimal)
    }
    return PercentSum;
}

// Converts a final percentage to a letter grade (A/B/C/D/F).
char lettergrade(double totalPercentage)
{
    if (totalPercentage >= 90)
    {
        return 'A';
    }
    else if (totalPercentage >= 80 && totalPercentage <= 89.99)
    {
        return 'B';
    }
    else if (totalPercentage >= 70 && totalPercentage <= 79.99)
    {
        return 'C';
    }
    else if (totalPercentage >= 60 && totalPercentage <= 69.99)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

// Prints a category label followed by that category's scores on one line.
void printCategoryScores(string label, int scores[], int startIndex, int count)
{
    cout << label << ": ";
    for (int i = startIndex; i < startIndex + count; i++)
    {
        cout << scores[i] << " ";
    }
    cout << endl;
}

// Returns true if the named file can be opened for reading.
bool fileExists(string fileName)
{
    ifstream file(fileName);
    return file.is_open();
}
