/*
 * This program
 * @author John Pilli
 * @author Oswaldo Castaneda
 * @version 0.0.0
 *
 * Last updated: 09/08/26
 *
 */

#include <iostream>
#include "utilities.h"
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "1. Generate Username" << endl;
        cout << "2. Generate Phone Number" << endl;
        cout << "3. Generate Email" << endl;
        cout << "4. Generate Address" << endl;
        cout << "5. Generate Test Credit Card" << endl;
        cout << "6. Generate Test CVV" << endl;
        cout << "7. Generate Test Expiration Date" << endl;
        cout << "8. Generate Complete Profile" << endl;
        cout << "9. Exit" << endl;
        cout << "Choice: " << endl;

        cin >> choice;

        switch (choice)
        {
        case 1: // Username
        {
            cout << "How long would you like your username to be?" << endl;

            int length;
            cin >> length; // take user input

            if (length > 10)
            {
                cout << "You entered an invalid length" << endl;
                length = 10;
            }
            else
            {
                length = length;
            }

            if (length < 1)
            {
                cout << "You entered an invalid length";
                length = 1;
            }
            else
            {
                length = length;
            }

            cout << "Username: " << randomName(length) << endl;

            // need to include generate Username

            break;
        }
        case 2: // Phone Number
        {
            cout << "What format would you like?" << endl; // prompt the user for what phone#format

            int phoneFormatType;
            cin >> phoneFormatType; // take user input

            if (phoneFormatType == 0)
            {
                cout << "Phone: " << generatePhoneNumber(0) << endl;
            }
            else if (phoneFormatType == 1)
            {
                cout << "Phone: " << generatePhoneNumber(1) << endl;
            }
            else if (phoneFormatType == 2)
            {
                cout << "Phone: " << generatePhoneNumber(2) << endl;
            }
            else
            {
                cout << "Invalid choice" << endl;
            }

            break;
        }
        case 3: // Email
        {
            cout << "Email: " << generateEmail() << endl;
            break;
        }
        case 4: // Addresss
        {
            cout << "Address: " << generateAddress() << endl;
            break;
        }
        case 5: // Credit Card
        {
            cout << "Credit Card: " << generateCreditCard() << endl;
            break;
        }
        case 6: // CVV
        {
            cout << "CVV: " << generateCVV() << endl;
            break;
        }
        case 7: // Expiration date
        {
            cout << "Expiration Date: " << generateDate() << endl;
            break;
        }
        case 8: // Complete profile
        {

            // code for the username generation (need to format still!!!!)

            cout << "How many profiles would you like to generate?" << endl;

            int numProfiles;
            cin >> numProfiles;

            srand(time(NULL)); // seed random number generator with the current time

            ofstream out;
            out.open("database.txt"); // open database.txt to input these into

            out << setw(15) << "Username" << setw(18) << "Phone" << setw(25) << "Email"
                << setw(45) << "Address" << setw(25) << "Credit Card" << setw(8) << "CVV"
                << setw(12) << "Expiration" << endl;

            for (int i = 0; i < numProfiles; i++)
            {
                out << setw(15) << randomName(8)
                    << setw(18) << generatePhoneNumber(rand() % 3)
                    << setw(25) << generateEmail()
                    << setw(45) << generateAddress()
                    << setw(25) << generateCreditCard()
                    << setw(8) << generateCVV()
                    << setw(12) << generateDate()
                    << endl;
            }
            out.close();
            break;
        }
        case 9: // Exit
        {
            cout << "Exit" << endl;
            break;
        }
        default: // Invalid choice
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }

    } while (choice != 9);

    return 0;
}

/*
 * For cases 1-7, program should output on the console window
 * for case 8, the user should be prompted on how many profiles are needed and
 * then output it onto a database text file, shoudl be a table where each row represents a
 * profile and the columns are different information of that profile
 *
 *
 *
 */