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
#include <string>
#include <vector>
#include <sstream>

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
double sumCategoryPercentages(vector<int> &studentScores, vector<int> &maxScores, int startIndex, int count)
{

    double PercentSum = 0;
    for (int i = startIndex; i < startIndex + count; i++)
    {
        PercentSum = PercentSum + (((double)studentScores[i] / maxScores[i]) * 100); // converts the answer to be in a double(with dcimal)
    }
    return PercentSum;
}

// Computes one student's average percentage in each of the 6 weighted categories.
void computeCategoryAverages(vector<int> &studentScores, vector<int> &maxScores,
                             int numLabs, int numQuizzes, int numExams, int numProjects, int numFinal,
                             double &avgLab, double &avgQuiz, double &avgExam1, double &avgExam2,
                             double &avgProject, double &avgFinal)
{
    // start index of each category = sum of the counts before it
    int examStart = numLabs + numQuizzes;
    int projectStart = examStart + numExams;
    int finalStart = projectStart + numProjects;

    // exam split into 2 separate 20% categories instead of 1 merged 40%
    double labSum = sumCategoryPercentages(studentScores, maxScores, 0, numLabs);
    double quizSum = sumCategoryPercentages(studentScores, maxScores, numLabs, numQuizzes);
    double exam1Sum = sumCategoryPercentages(studentScores, maxScores, examStart, 1);
    double exam2Sum = sumCategoryPercentages(studentScores, maxScores, examStart + 1, 1);
    double projectSum = sumCategoryPercentages(studentScores, maxScores, projectStart, numProjects);
    double finalexamSum = sumCategoryPercentages(studentScores, maxScores, finalStart, numFinal);

    // sum / count = average percentage for the category
    avgLab = labSum / numLabs;
    avgQuiz = quizSum / numQuizzes;
    avgExam1 = exam1Sum / 1;
    avgExam2 = exam2Sum / 1;
    avgProject = projectSum / numProjects;
    avgFinal = finalexamSum / numFinal;
}

void computeClassAverages(string scoresFile, double &classLab, double &classQuiz, double &classExam1,
                          double &classExam2, double &classProject, double &classFinal)
{
    int numLabs;
    int numQuizzes;
    int numExams;
    int numProjects;
    int numFinal;
    ifstream in;
    in.open(scoresFile);

    in >> numLabs >> numQuizzes >> numExams >> numProjects >> numFinal;
    int total = numLabs + numQuizzes + numExams + numProjects + numFinal;

    vector<int> maxScores(total);
    for (int i = 0; i < total; i++)
    {
        in >> maxScores[i];
    }

    string line;
    getline(in, line); // eat teh leftover newline, same as the last function

    double labTotal = 0;
    double quizTotal = 0;
    double exam1Total = 0;
    double exam2Total = 0;
    double projectTotal = 0;
    double finalTotal = 0;
    int studentsCounted = 0;

    while (getline(in, line))
    {
        stringstream ss(line);
        vector<int> studentScores(total);
        bool hasScores = true;

        for (int j = 0; j < total; j++)
        {
            if (!(ss >> studentScores[j]))
            {
                hasScores = false;
                break;
            }
        }
        if (!hasScores)
        {
            continue;
        }

        double avgLab;
        double avgQuiz;
        double avgExam1;
        double avgExam2;
        double avgProject;
        double avgFinal;
        computeCategoryAverages(studentScores, maxScores, numLabs, numQuizzes, numExams, numProjects, numFinal,
                                avgLab, avgQuiz, avgExam1, avgExam2, avgProject, avgFinal);

        labTotal += avgLab;
        quizTotal += avgQuiz;
        exam1Total += avgExam1;
        exam2Total += avgExam2;
        projectTotal += avgProject;
        finalTotal += avgFinal;
        studentsCounted++;
    }

    in.close();

    classLab = labTotal / studentsCounted;
    classQuiz = quizTotal / studentsCounted;
    classExam1 = exam1Total / studentsCounted;
    classExam2 = exam2Total / studentsCounted;
    classProject = projectTotal / studentsCounted;
    classFinal = finalTotal / studentsCounted;
}

// Prints the logged-in student's category averages next to the whole class's averages.
void printClassComparison(string scoresFile, double avgLab, double avgQuiz, double avgExam1,
                          double avgExam2, double avgProject, double avgFinal)
{
    double classLab, classQuiz, classExam1, classExam2, classProject, classFinal;
    computeClassAverages(scoresFile, classLab, classQuiz, classExam1, classExam2, classProject, classFinal);

    cout << fixed << setprecision(2);
    cout << endl;
    cout << "Class Average Comparison:" << endl;
    cout << "Labs:    You " << avgLab << "%  |  Class " << classLab << "%" << endl;
    cout << "Quiz:    You " << avgQuiz << "%  |  Class " << classQuiz << "%" << endl;
    cout << "Exam 1:  You " << avgExam1 << "%  |  Class " << classExam1 << "%" << endl;
    cout << "Exam 2:  You " << avgExam2 << "%  |  Class " << classExam2 << "%" << endl;
    cout << "Project: You " << avgProject << "%  |  Class " << classProject << "%" << endl;
    cout << "Final:   You " << avgFinal << "%  |  Class " << classFinal << "%" << endl;
}

// Converts a final percentage to a letter grade (A/B/C/D/F).
string lettergrade(double totalPercentage) //  this should be good enoguh
{
    if (totalPercentage >= 97)
    {
        return "A+";
    }
    else if (totalPercentage >= 93 && totalPercentage <= 96)
    {
        return "A";
    }
    else if (totalPercentage >= 90 && totalPercentage <= 92)
    {
        return "A-";
    }
    else if (totalPercentage >= 87 && totalPercentage <= 89)
    {
        return "B+";
    }
    else if (totalPercentage >= 83 && totalPercentage <= 86)
    {
        return "B";
    }
    else if (totalPercentage >= 80 && totalPercentage <= 82)
    {
        return "B-";
    }
    else if (totalPercentage >= 77 && totalPercentage <= 79)
    {
        return "C+";
    }
    else if (totalPercentage >= 73 && totalPercentage <= 76)
    {
        return "C";
    }
    else if (totalPercentage >= 70 && totalPercentage <= 72)
    {
        return "C-";
    }
    else if (totalPercentage >= 67 && totalPercentage <= 69)
    {
        return "D+";
    }
    else if (totalPercentage >= 63 && totalPercentage <= 66)
    {
        return "D";
    }
    else if (totalPercentage >= 60 && totalPercentage <= 62)
    {
        return "D-";
    }
    else
    {
        return "F";
    }
}

// Prints each score in a category on its own numbered label, e.g. "Lab 1: 5  Lab 2: 1".
void printCategoryScores(string label, vector<int> &scores, int startIndex, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << label << " " << (i + 1) << ": " << scores[startIndex + i] << "  ";
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

    int numLabs = stoi(randomNumberInRange(15, 25)); // non-hardcoded num of labs and quizzes
    int numQuizzes = stoi(randomNumberInRange(5, 10));
    int numExams = 2;
    int numProjects = 1;
    int numFinal = 1;
    int total = numLabs + numQuizzes + numExams + numProjects + numFinal;

    vector<int> maxScores(total);

    out << setw(5) << numLabs << setw(5) << numQuizzes << setw(5) << numExams
        << setw(5) << numProjects << setw(5) << numFinal << endl;

    for (int i = 0; i < numLabs; i++) // labs
    {
        string randomMaxLab = generateRandomScores(5, 20);
        maxScores[i] = stoi(randomMaxLab);
        out << setw(5) << randomMaxLab;
    }

    for (int i = 0; i < numQuizzes; i++) // quizzes
    {
        string randomMaxQuiz = generateRandomScores(10, 15);
        maxScores[numLabs + i] = stoi(randomMaxQuiz);
        out << setw(5) << randomMaxQuiz;
    }

    for (int i = 0; i < numExams; i++) // exams
    {
        string randomMaxExam = generateRandomScores(40, 60);
        maxScores[numLabs + numQuizzes + i] = stoi(randomMaxExam);
        out << setw(5) << randomMaxExam;
    }

    string randomMaxProject = generateRandomScores(80, 100); // project
    maxScores[numLabs + numQuizzes + numExams] = stoi(randomMaxProject);
    out << setw(5) << randomMaxProject;

    string randomMaxFinalExam = generateRandomScores(90, 110); // final exam
    maxScores[numLabs + numQuizzes + numExams + numProjects] = stoi(randomMaxFinalExam);
    out << setw(5) << randomMaxFinalExam << endl;

    // Rows 3+: each student's scores, from 0 up to that assignment's maximum
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < total; j++)
        {
            out << setw(5) << generateRandomScores(0, maxScores[j]);
        }
        out << endl;
    }
    out.close();
}

// Reads the logged-in student's row from the scores file, then prints the formatted score report.
void generateScoreReport(string scoresFile, int loggedInRowIndex, string loggedInUsername, bool isFullReport)
{
    int numLabs;
    int numQuizzes;
    int numExams;
    int numProjects;
    int numFinal;
    ifstream in;
    in.open(scoresFile);

    in >> numLabs >> numQuizzes >> numExams >> numProjects >> numFinal;
    int total = numLabs + numQuizzes + numExams + numProjects + numFinal;

    vector<int> maxScores(total);
    for (int i = 0; i < total; i++)
    {
        in >> maxScores[i];
    }

    string line;
    vector<int> studentScores(total);

    getline(in, line); // go through the rest of the max scores line

    for (int i = 0; i < loggedInRowIndex; i++) // navigation, this just gets to whatever specific line you need
    {
        getline(in, line); // advances by one line each time,
    }

    stringstream ss(line); // chekcs if the specific line has any values or not, if no values that it returns 0 for everything
    for (int j = 0; j < total; j++)
    {
        if (!(ss >> studentScores[j]))
        {
            studentScores[j] = 0; // line was blank
        }
    }

    in.close();

    // start index of each category = sum of the counts before it (still needed for printCategoryScores below)
    int examStart = numLabs + numQuizzes;
    int projectStart = examStart + numExams;
    int finalStart = projectStart + numProjects;

    double avglab, avgquiz, avgexam1, avgexam2, avgproject, avgfinalexam;
    computeCategoryAverages(studentScores, maxScores, numLabs, numQuizzes, numExams, numProjects, numFinal,
                            avglab, avgquiz, avgexam1, avgexam2, avgproject, avgfinalexam);

    // apply each category's weight
    double labpercentage = avglab * 0.15;
    double quizpercentage = avgquiz * 0.15;
    double exam1percentage = avgexam1 * 0.20;
    double exam2percentage = avgexam2 * 0.20;
    double projectpercentage = avgproject * 0.10;
    double finalexampercentage = avgfinalexam * 0.20;

    // add up all weighted contributions = final grade percentage
    double totalPercentage = labpercentage + quizpercentage + exam1percentage + exam2percentage + projectpercentage + finalexampercentage;

    string finallettergrade = lettergrade(totalPercentage);

    // if else statement for print full report and short report
    if (isFullReport)
    {
        printFullReport(loggedInUsername, scoresFile, studentScores, numLabs, numQuizzes, examStart, projectStart, numProjects, finalStart, numFinal,
                        avglab, avgquiz, avgexam1, avgexam2, avgproject, avgfinalexam, labpercentage, quizpercentage, exam1percentage,
                        exam2percentage, projectpercentage, finalexampercentage, totalPercentage, finallettergrade);
    }
    else
    {
        printShortReport(loggedInUsername, avglab, avgquiz, avgexam1, avgexam2, avgproject, avgfinalexam, labpercentage, quizpercentage,
                         exam1percentage, exam2percentage, projectpercentage, finalexampercentage, totalPercentage, finallettergrade);
    }
}

// Prints the full, detailed score report (per-assignment scores, percentages, weighted
// contributions, total, letter grade, and the class comparison).
void printFullReport(string loggedInUsername, string scoresFile, vector<int> &studentScores,
                     int numLabs, int numQuizzes, int examStart, int projectStart, int numProjects, int finalStart, int numFinal,
                     double avglab, double avgquiz, double avgexam1, double avgexam2, double avgproject, double avgfinalexam,
                     double labpercentage, double quizpercentage, double exam1percentage, double exam2percentage,
                     double projectpercentage, double finalexampercentage,
                     double totalPercentage, string finallettergrade)
{
    cout << "Username: " << loggedInUsername << endl;
    cout << "These are your scores: " << endl;

    printCategoryScores("Lab", studentScores, 0, numLabs);
    printCategoryScores("Quiz", studentScores, numLabs, numQuizzes);
    printCategoryScores("Exam 1", studentScores, examStart, 1);
    printCategoryScores("Exam 2", studentScores, examStart + 1, 1);
    printCategoryScores("Project", studentScores, projectStart, numProjects);
    printCategoryScores("Final Exam", studentScores, finalStart, numFinal);

    cout << endl;

    cout << fixed << setprecision(2);
    cout << "This is your percentage earned for each category: " << "Labs: " << avglab << "% " << "Quiz: " << avgquiz << "% " << "Exam 1: " << avgexam1 << "% " << "Exam 2: " << avgexam2 << "% " << "Project: " << avgproject << "% " << "Final: " << avgfinalexam << "%" << endl;
    cout << "This is your weighted percentage for each category: " << "Labs: " << labpercentage << "% " << "Quiz: " << quizpercentage << "% " << "Exam 1: " << exam1percentage << "% " << "Exam 2: " << exam2percentage << "% " << "Project: " << projectpercentage << "% " << "Final: " << finalexampercentage << "%" << endl;
    cout << "This your total final percentage: " << totalPercentage << "%" << endl;
    cout << "This is your final letter grade: " << finallettergrade << endl;

    printClassComparison(scoresFile, avglab, avgquiz, avgexam1, avgexam2, avgproject, avgfinalexam);
}

// Prints a condensed score summary (one line per category, total, and letter grade).
void printShortReport(string loggedInUsername,
                      double avglab, double avgquiz, double avgexam1, double avgexam2, double avgproject, double avgfinalexam,
                      double labpercentage, double quizpercentage, double exam1percentage, double exam2percentage,
                      double projectpercentage, double finalexampercentage,
                      double totalPercentage, string finallettergrade)
{
    cout << fixed << setprecision(2);

    cout << "Username: " << loggedInUsername << endl;

    cout << "Labs: " << avglab << "%" << " " << "(15%)" << " -> " << labpercentage << "%" << endl;
    cout << "Quiz: " << avgquiz << "%" << " " << "(15%)" << " -> " << quizpercentage << "%" << endl;
    cout << "Exam 1: " << avgexam1 << "%" << " " << "(20%)" << " -> " << exam1percentage << "%" << endl;
    cout << "Exam 2: " << avgexam2 << "%" << " " << "(20%)" << " -> " << exam2percentage << "%" << endl;
    cout << "Project: " << avgproject << "%" << " " << "(10%)" << " -> " << projectpercentage << "%" << endl;
    cout << "Final Exam: " << avgfinalexam << "%" << " " << "(20%)" << " -> " << finalexampercentage << "%" << endl;

    cout << endl;

    cout << "Final Percentage: " << totalPercentage << "%" << endl;
    cout << "Letter Grade: " << finallettergrade << endl;
}
