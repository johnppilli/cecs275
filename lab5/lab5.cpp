/*
 * This program generates fake user and score data, lets a user log in (with up to 5 attempts),
 * and then displays their score report with percentages, weighted contributions and final letter grade.
 * @author John Pilli
 * @author Oswaldo Castaneda
 * @version 0.0.0
 *
 * Last updated: 09/21/26
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

    const int MAIN_MENU_SIZE = 4;
    const string mainMenu[MAIN_MENU_SIZE] = {"Generate Fake Data", "Select Data Sets", "Log In", "Exit"};
    const string subMenu[] = {"Generate Score Report", "Sign out"};
    bool isLoggedIn = false;
    string loggedInUsername = "";
    bool isProgramOpen = true;
    bool isSignedOut = false;
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
            generateFakeData();
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
                loginFile = "fake_users.txt";
                scoresFile = "fake_scores.txt";
                break;
            }
            case 2:
            {
                // given data
                cout << "Enter the users file name: " << endl;
                cin >> loginFile;
                while (!fileExists(loginFile))
                {
                    cout << "File not found. Enter the users file name: " << endl;
                    cin >> loginFile;
                }

                cout << "Enter the scores file name: " << endl;
                cin >> scoresFile;
                while (!fileExists(scoresFile))
                {
                    cout << "File not found. Enter the scores file name: " << endl;
                    cin >> scoresFile;
                }
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
        case 4: // done
        {
            // close the program
            isProgramOpen = false;
            break;
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
                    generateScoreReport(scoresFile, loggedInRowIndex, loggedInUsername);

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
