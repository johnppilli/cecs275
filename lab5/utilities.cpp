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
string randomLowerCaseLetter()
{
    char loweralphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string lowercaseletter = "";                   // intialize with empty string
    lowercaseletter += loweralphabet[rand() % 26]; // append the string with random letter from laphabet

    return lowercaseletter;
}

string randomCapitalLetter()
{
    char upperalphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string uppercaseletter = "";
    uppercaseletter += upperalphabet[rand() % 26];

    return uppercaseletter;
}
/*
 *
 * Used for both an assignment's max scores and the students max score;
 * you would just keep the max same for the both uses but change the minimum to whatever the
 * the assignment is worth, (assignment can't be worth 0 points)
 *
 *
 */
string generateRandomScores(int min, int max)
{
    string randomScore = randomNumberInRange(min, max);

    return randomScore;
}

double sumCategoryPercentages(int studentScores[], int maxScores[], int startIndex, int count)
{

    double PercentSum = 0;
    for (int i = startIndex; i < startIndex + count; i++)
    {
        PercentSum = PercentSum + (((double)studentScores[i] / maxScores[i]) * 100); // converts the answer to be in a double(with dcimal)
    }
    return PercentSum;
}

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
