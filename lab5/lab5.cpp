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
    // srand(time(NULL)); // seed random number genatoro

    // cout << generateRandomUsername() << endl;

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
// generateFakeData
#ifdef DEBUG
            cout << "Main Menu Option 1 is selected" << endl;
#endif
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
            // Ask the user for username and password
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
