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
#include <iomanip>

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

// Writes fake_users.txt (100 users) and fake_scores.txt (counts row, max-scores row, 100 students' scores).
void generateFakeData()
{
    cout << "Generating profiles" << endl;

    ofstream out;
    out.open("fake_users.txt");

    for (int i = 0; i < 100; i++)
    {
        out << setw(15) << generateRandomUsername()
            << setw(15) << generateRandomPassword()
            << endl;
    }
    out.close();

    cout << "Generating Scores" << endl;

    out.open("fake_scores.txt");

    int maxScores[31];

    // Row 1: number of items in each category
    out << setw(5) << "20" << setw(5) << "7" << setw(5) << "2"
        << setw(5) << "1" << setw(5) << "1" << endl;

    // Row 2: maximum possible score of each assignment
    for (int i = 0; i < 20; i++) // labs
    {
        string randomMaxLab = generateRandomScores(5, 20);
        maxScores[i] = stoi(randomMaxLab);
        out << setw(5) << randomMaxLab;
    }

    for (int i = 0; i < 7; i++) // quizzes
    {
        string randomMaxQuiz = generateRandomScores(10, 15);
        maxScores[20 + i] = stoi(randomMaxQuiz);
        out << setw(5) << randomMaxQuiz;
    }

    for (int i = 0; i < 2; i++) // exams
    {
        string randomMaxExam = generateRandomScores(40, 60);
        maxScores[27 + i] = stoi(randomMaxExam);
        out << setw(5) << randomMaxExam;
    }

    string randomMaxProject = generateRandomScores(80, 100); // project
    maxScores[29] = stoi(randomMaxProject);
    out << setw(5) << randomMaxProject;

    string randomMaxFinalExam = generateRandomScores(90, 110); // final exam
    maxScores[30] = stoi(randomMaxFinalExam);
    out << setw(5) << randomMaxFinalExam << endl;

    // Rows 3+: each student's scores, from 0 up to that assignment's maximum
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            out << setw(5) << generateRandomScores(0, maxScores[j]);
        }
        out << endl;
    }
    out.close();
}

// Reads the logged-in student's row from the scores file, then prints the formatted score report.
void generateScoreReport(string scoresFile, int loggedInRowIndex, string loggedInUsername)
{
    int maxScores[31];
    ifstream in;
    in.open(scoresFile);

    int throwaway;

    // throwaway first 5 values (the assignments)
    for (int i = 0; i < 5; i++)
    {
        in >> throwaway;
    }

    // read the values from scoresFile into maxScores array
    for (int i = 0; i < 31; i++)
    {
        in >> maxScores[i];
    }

    // skip loop, throws away loggedInRowIndex - 1 full rows
    // this navigates past all the rows that come before the target row
    for (int i = 0; i < loggedInRowIndex - 1; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            in >> throwaway;
        }
    }

    // capture loop (reads the actual target row into a new array)
    // takes the actual row you need and reads them into the studentscores
    int studentScores[31];
    for (int j = 0; j < 31; j++)
    {
        in >> studentScores[j];
    }

    in.close();

    // call sumcategorypercentags 5 idff times for each assignmnets

    double labSum = sumCategoryPercentages(studentScores, maxScores, 0, 20);
    double quizSum = sumCategoryPercentages(studentScores, maxScores, 20, 7);
    double examSum = sumCategoryPercentages(studentScores, maxScores, 27, 2);
    double projectSum = sumCategoryPercentages(studentScores, maxScores, 29, 1);
    double finalexamSum = sumCategoryPercentages(studentScores, maxScores, 30, 1);

    double avglab = labSum / 20;
    double avgquiz = quizSum / 7;
    double avgexam = examSum / 2;
    double avgproject = projectSum / 1;
    double avgfinalexam = finalexamSum / 1;

    double labpercentage = avglab * 0.15;
    double quizpercentage = avgquiz * 0.15;
    double exampercentage = avgexam * 0.40;
    double projectpercentage = avgproject * 0.10;
    double finalexampercentage = avgfinalexam * 0.20;

    double totalPercentage = labpercentage + quizpercentage + exampercentage + projectpercentage + finalexampercentage;

    // cout everythign

    char finallettergrade = lettergrade(totalPercentage);

    cout << "Username: " << loggedInUsername << endl;
    cout << "These are your scores: " << endl;

    printCategoryScores("Labs", studentScores, 0, 20);
    printCategoryScores("Quizzes", studentScores, 20, 7);
    printCategoryScores("Exams", studentScores, 27, 2);
    printCategoryScores("Project", studentScores, 29, 1);
    printCategoryScores("Final Exam", studentScores, 30, 1);

    cout << endl;

    cout << fixed << setprecision(2);
    cout << "This is your percentage earned for each category: " << avglab << " " << avgquiz << " " << avgexam << " " << avgproject << " " << avgfinalexam << endl;
    cout << "This is your weighted percentage for each category: " << labpercentage << " " << quizpercentage << " " << exampercentage << " " << projectpercentage << " " << finalexampercentage << endl;
    cout << "This your total final percentage: " << totalPercentage << endl;
    cout << "This is your final letter grade: " << finallettergrade << endl;
}
