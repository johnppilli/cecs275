/*
 * This program
 * @author John Pilli
 * @author Oswaldo Castaneda
 * @version 0.0.0
 *
 * Last updated: 09/17/26
 *
 */

#include <iostream>
#include "utilities.h"
#include <iomanip>
#include <fstream>
#include <ctime>
#include <string>
#define DEBUG

using namespace std;

void displayMenu(const string options[], const int &size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << (i + 1) << ". " << options[i] << endl;
    }
}

int main()
{

    // generate 100 fake data stored in a txt file
    srand(time(NULL)); // seed random number genatoro

    const int MAIN_MENU_SIZE = 6;
    const string mainMenu[MAIN_MENU_SIZE] = {"Generate Fake Data", "Select Data Sets", "Log In", "Forget Password", "Register", "Exit"};
    const string subMenu[] = {"Generate Score Report", "Sign out"};
    bool isLoggedIn = false;
    string loggedInUsername = "";
    bool isProgramOpen = true;
    bool isSignedOut = false;
    int maxScores[31];
    string loginFile;
    string scoresFile;
    int loggedInRowIndex;

    while (isProgramOpen)
    {
        displayMenu(mainMenu, MAIN_MENU_SIZE);
        int choice;
        cout << "Select: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1: // done
        {
            // generate fake usernames + passwords

            cout << "Generating profiles" << endl;

            ofstream out;
            out.open("userdatabase.txt"); // open database

            for (int i = 0; i < 100; i++)
            {
                out << setw(15) << generateRandomUsername()
                    << setw(15) << generateRandomPassword()
                    << endl;
            }
            out.close();

            cout << "Generating Scores" << endl;

            ofstream scoreOut;
            out.open("fakedata.txt");

            // Max Scores Line beginning of code -- 2nd row

            out << setw(5) << "20" << setw(5) << "7" << setw(5) << "2"
                << setw(5) << "1" << setw(5) << "1" << endl;

            for (int i = 0; i < 20; i++) // loosp the max random scores
            {
                // generateRandomScores
                string randomMaxLab = generateRandomScores(5, 20); // gives rnadom number
                int randomMaxLabInt = stoi(randomMaxLab);          // converts

                maxScores[i] = randomMaxLabInt; // stores i
                out << setw(5) << randomMaxLab; // prints
            }

            for (int i = 0; i < 7; i++)
            {
                // generateRandom
                string randomMaxQuiz = generateRandomScores(10, 15);
                int randomMaxQuizInt = stoi(randomMaxQuiz);

                maxScores[20 + i] = randomMaxQuizInt;
                out << setw(5) << randomMaxQuiz;
            }

            for (int i = 0; i < 2; i++)
            {
                string randomMaxExam = generateRandomScores(40, 60);
                int randomMaxExamInt = stoi(randomMaxExam);

                maxScores[27 + i] = randomMaxExamInt;
                out << setw(5) << randomMaxExam;
            }

            // Max Project Scores
            string randomMaxProject = generateRandomScores(80, 100);
            int randomMaxProjectInt = stoi(randomMaxProject);

            maxScores[29] = randomMaxProjectInt;
            out << setw(5) << randomMaxProject;

            // Max Final Exam Scores
            string randomMaxFinalExam = generateRandomScores(90, 110);
            int randomMaxFinalExamInt = stoi(randomMaxFinalExam);

            maxScores[30] = randomMaxFinalExamInt;
            out << setw(5) << randomMaxFinalExam << endl;

            // Max Scores Line done -- 2nd row

            // Start of Code for each students scores
            // for loop running 100 times, inside for loop for each score

            for (int i = 0; i < 100; i++)
            {
                for (int j = 0; j < 31; j++)
                {
                    string studentScores = generateRandomScores(0, maxScores[j]);
                    out << setw(5) << studentScores;
                }
                out << endl;
            }

            scoreOut.close();

            break;
        }
        case 2: // TODO
        {
            // TODO:
            // Ask user to select a data set either the fake data or the given data
            // the user will input
            // fake_users.txt
            // fake_score.txt
            // OR
            // users.txt
            // scores.txt

            int choice;

            cout << "1. Fake Data" << endl;
            cout << "2. Given Data" << endl;

            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                // fake data
                loginFile = "userdatabase.txt";
                scoresFile = "fakedata.txt";
                break;
            }
            case 2:
            {
                // given data
                loginFile = "users.txt";
                scoresFile = "scores.txt";
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case 3: // done
        {
            for (int attempt = 0; attempt < 5; attempt++)
            {
                string username;
                string password;

                int rowCounter = 0; // initialize local counter to keep track of score rows

                cout << "Enter your username: " << endl;
                cin >> username;
                cout << "Enter your password: " << endl;
                cin >> password;

                ifstream in;
                in.open(loginFile);

                string fileUsername;
                string filePassword;

                while (in >> fileUsername >> filePassword)
                {
                    rowCounter++; // count only actual student rows
                    if (fileUsername == username && filePassword == password)
                    {
                        isLoggedIn = true;
                        loggedInUsername = username;
                        loggedInRowIndex = rowCounter; // set equal to the global variable so it keeps track
                        break;
                    }
                }
                if (isLoggedIn == true)
                {
                    break;
                }
                else
                {
                    cout << "Invalid username or password. Attempts remaining: " << (4 - attempt) << endl;
                }
                in.close();
            }
            break;
        }
        case 4: // not required
        {
            // ask for registration info
            // username and password only
            // NOT REQUIRED
            break;
        }
        case 5: // not required
        {
            // password reset
            break;
        }
        case 6: // done
        {
            // close the program
            isProgramOpen = false;
        }
        default:
            break;
        }

        // if logged in successfully, then display submenu
        if (isLoggedIn)
        {
            while (!isSignedOut)
            {
                cout << "\nWelcome, " << loggedInUsername << endl;
                displayMenu(subMenu, 2);
                cout << "Select: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    // generate score report
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

                    break;
                }
                case 2:
                {
                    cout << "Sign Out" << endl;
                    isSignedOut = true;
                    isLoggedIn = false;
                    break;
                }

                default:
                {
                    break;
                }
                }
            }
            isSignedOut = false;
        }
    }

    return 0;
}
