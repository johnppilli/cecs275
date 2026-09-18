/*
*This program is to demo if-else statements and loops 
* @author John Pilli
* @author
* @version 0.0.0
*
* Last updated: 09/01/26
*
*/

#include <iostream> 

using namespace std; 
const int MAX_INVALID_CHOICE = 3;




int main()
{ 
     int num_InvalidChoice = 0; 
     while(num_InvalidChoice < MAX_INVALID_CHOICE)
     {
     // Display menu for the demo 
     cout << "CECS 275 Demo Option" << endl; 
     cout << "1. If-else Demo" << endl;
     cout << "2. Loops Demo" << endl; 
     cout<< "Choice: ";
     
     // Prompt the user for a choice 
     int choice; 
     cin >> choice; 
     
     if(choice == 1) 
     {
          cout << "Choice 1 is selected" << endl;
     } 
     else if (choice == 2) 
     {
          cout << "Choice 2 is selected" << endl;
     } 
     else 
     {
          num_InvalidChoice++;
          cout << "Invalid is selected" << endl; 
     }

     }
     
     //Display error message
     if(num_InvalidChoice >= MAX_INVALID_CHOICE) {
        cout << "Too many invalid choices" << endl; 
        cout << "System shuts down." << endl;
         

     }
     return 0;
}







