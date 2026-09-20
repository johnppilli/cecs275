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
    const string mainMenu[MAIN_MENU_SIZE] = {"Generate Fake Data", "Select Data Sets", "Register", "Forget Password", "Log In", "Exit"};
    const string subMenu[] = {"Generate Score Report", "Display Overall Letter Grade", "Sign out"};
    bool isLoggedIn = false;
    bool isProgramOpen = true;
    bool isSignedOut = false;
    while (isProgramOpen)
    {
        displayMenu(mainMenu, MAIN_MENU_SIZE);
        int choice;
        cout << "Select: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // TODO:
            // generate fake usernames + passwords

            cout << "Generating profiles" << endl;

            ofstream out;
            out.open("userdatabase.txt"); // open database

            out << setw(15) << "Username" << setw(15) << "Password" << endl; // formatting
            out << setw(15) << "JohnDoe123" << setw(15) << "John123" << endl;

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
            int maxScores[31];

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
        case 2:
        {
            // TODO:
            // Ask user to select a data set either the fake data or the given data
            // the user will input
            // fake_users.txt
            // fake_score.txt
            // OR
            // users.txt
            // scores.txt
            break;
        }
        case 3:
        {
            string username;
            string password;

            // Ask the user for username and password
            cout << "Enter your username: " << endl;
            cin >> username;
            cout << "Enter your password: " << endl;
            cin >> password;

            break;
        }
        case 4:
        {
            // ask for registration info
            // username and password only
            // NOT REQUIRED
            break;
        }
        case 5:
        {
            // password reset
            break;
        }
        case 6:
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
                cout << "\nWelcome, " << "username" << endl;
                displayMenu(subMenu, 3);
                cout << "Select: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    break;
                }
                }
            }
        }
    }

    return 0;
}
