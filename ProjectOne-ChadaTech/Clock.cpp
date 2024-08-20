/*
* Developer : Thomas Davis
*
* Date: 7/18/2024
*
* CS-210-11787 - SNHU
* 
* Professor Foutlz
*
* Chada Tech - 12 & 24 Clock
*/
 
// Includes the Header file for use
#include "Header.h"

void displayMenu() {  //Function to display menu
    
    const size_t borderLength = 25; // Length of the border line

    // Creates the top and bottom border
    string border = nCharString(borderLength, '*');

    // Displays the menu options to the user, formatted with nCharString
    cout << "\n" << border << endl;  // Top border
    cout << "* 1 - Add One Hour" << nCharString(borderLength - 19, ' ') << "*" << endl;     // First line of menu
    cout << "* 2 - Add One Minute" << nCharString(borderLength - 21, ' ') << "*" << endl;   // Second line of menu 
    cout << "* 3 - Add One Second" << nCharString(borderLength - 21, ' ') << "*" << endl;   // Third line of menu
    cout << "* 4 - Exit Program" << nCharString(borderLength - 19, ' ') << "*" << endl;     // Fourth line of menu
    cout << border << endl;  // Bottom border
}

// Displays the menu and accepts input from the user
void mainMenu() {
	unsigned int choice;

	do {
        displayMenu();
		displayClocks(getHour(), getMinute(), getSecond());  // Display the clocks with the current time
		  // Display the menu

		choice = getMenuChoice(4); // Gets choice from getMenuChoice

        // Uses case to determine action based on user input
		switch (choice) {
		    case 1:             // Increases the hours by 1
			    addOneHour();
			    break;
		    case 2:             // Increases the minutes by 1
			    addOneMinute(); 
			    break;
		    case 3:             // Increases the seconds by 1
			    addOneSecond(); 
			    break;
		    case 4:             // Exits the program
			    break;
		}

	} while (choice != 4);

}

// Gets input from user for hour between 0 and 23
unsigned int getValidHour() {
    unsigned int h;

    // Loop to validate the user input
    while (true) {
        cout << "Enter the current hour (0-23): " << endl;
        cin >> h;
       
        if (h < 0 || h > 23) {      // Executes if user input in invalid
            cout << "Invalid input. Please enter a number between 0 and 23." << endl;
            
            continue;   // Resets the loop
        }
        else {          // Executes if user input is valid
              return h; // Returns the hour
        }
    }
}

// Gets input from user for minutes between 0 and 59
unsigned int getValidMinute() {
    unsigned int m;

    // Loop to validate the user input
    while (true) {
        cout << "Enter the current minute (0-59): " << endl;;
        cin >> m;

        if (m < 0 || m > 59) {      // Executes if user input in invalid
            cout << "Invalid input. Please enter a number between 0 and 59." << endl;
            
            continue;   // Resets the loop
        }
        else {          // Executes if user input is valid
            return m;   // Returns the minutes
        }
    }
}

// Get use input from user for seconds between 0 and 59
unsigned int getValidSecond() {
    unsigned int s;

    // Loop to validate the user input
    while (true) {
        cout << "Enter the current second (0-59): " << endl;
        cin >> s;

        if (s < 0 || s > 59 ) {     // Executes if user input in invalid
            cout << "Invalid input. Please enter a number between 0 and 59." << endl;
            continue;   // Resets the loop
        }
        else {          // Executes if user input is valid
            return s;   // Returns the seconds
        }
    }
}



// Main function for the program
int main() {
	unsigned int h, m, s;

    h = getValidHour();     // Gets the validated hour
    setHour(h);             // Sets the hour

    m = getValidMinute();   // Gets the validated minute
    setMinute(m);           // Sets the minute
        
    s = getValidSecond();   // Gets the validated second
    setSecond(s);           // Sets the second

	mainMenu();             // Calls and starts the main menu

}




