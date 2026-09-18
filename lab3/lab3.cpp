/*
 * This program calculates mortgage for a given income, rate, loan years
 * @author John Pilli
 * @author Oswaldo Castaneda
 * @version 0.0.0
 *
 * Last updated: 09/03/26
 *
 */

#include <iostream>
#include <iomanip> //formatting
#include <cmath>   //math functions/operations
#include <fstream>

using namespace std;

// start of main function
int main()
{

    // Display menu for this calculator
    cout << "MORTGAGE CALCULATOR" << endl;
    cout << "1. User Input" << endl;
    cout << "2. Automated testing" << endl;
    cout << "Choice: ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1: // import the code i have below into case 1
    {
        double P, R;
        unsigned int N;
        cout << "Enter your loan amount: " << endl;
        cin >> P;
        cout << "Enter your annual interest rate: " << endl;
        cin >> R;
        cout << "Enter your loan term in years: " << endl;
        cin >> N;

        cout << endl;

        // Monthly mortgage calc
        double r = (R / 100) / 12; // convert to dec monthly interest
        unsigned int n = N * 12;   // total number of payments (loan term in years * 12)
        double oneplusr = pow(1 + r, n);
        double M = (P * ((r * oneplusr) / ((oneplusr)-1)));
        long double total_interest = (M * n) - P; //(Monthly mortgage * total number of payments) - loan amount

        cout << fixed << showpoint << setprecision(2); // set format with two decimal places for all values
        cout << "Your loan amount is: " << "$" << P << endl;
        cout << "Your interest rate is: " << R << "%" << endl;
        cout << "Your loan term is: " << N << " years" << endl;
        cout << "Your total interest paid is: " << total_interest << endl;
        cout << "Your total number of payments is: " << n << endl;
        cout << "Your monthly payment is: " << "$" << M << endl;

        break;
    }
    case 2: // automated case
    {
        double P, R;
        unsigned int N;
        // Open a text file to read
        ifstream in;
        in.open("data.txt");

        // Open a text file to write
        ofstream out;
        out.open("result.txt"); // it will be overwritten if already exists

        // Check if the text file exists
        if (!in)
        {
            cerr << "File does not exist." << endl;
            exit(1);
        }
        // Read from the text file until the end then close
        out << setw(15) << "Income($)" << setw(15) << "Rate(%)" << setw(15) << "Years" << setw(20) << "Total Interest($)" << setw(20) << "Total Payment($)" << setw(20) << "Monthly Payment($)" << endl;
        out << fixed << showpoint << setprecision(2);
        while (in >> P >> R >> N)
        {
            // math from case 1
            double r = (R / 100) / 12; // convert to dec monthly interest
            unsigned int n = N * 12;   // total number of payments (loan term in years * 12)
            double oneplusr = pow(1 + r, n);
            double M = (P * ((r * oneplusr) / ((oneplusr)-1)));
            long double total_interest = (M * n) - P; //(Monthly mortgage * total number of payments) - loan amount

            out << setw(15) << P << setw(15) << R << setw(15) << N << setw(20) << total_interest << setw(20) << n << setw(20) << M << endl;
        }
        in.close();
        out.close();
        break;
    }
    default:
    {
        cout << "Invalid choice" << endl;
        break;
    }
    }
}
