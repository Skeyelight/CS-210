#pragma once
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

#include <string>
#include <iostream>
using namespace std;

// Variables to store the current time
unsigned int currentHour;
unsigned int currentMinute;
unsigned int currentSecond;

// Converts time to a string and adds a 0 to single digit numbers in the time 
string twoDigitString(unsigned int n) {

	if (n < 10) {				// Checks if the number is less than 10
		return "0" + to_string(n);  // Adds 0 to front of number is less than 10
	}
	else {					// Doesn't modify number is greater than 10
		return to_string(n); 
	}
}

// Creates a string of repeating characters (c) based on n 
string nCharString(size_t n, char c) {
	string result(n, c);	// Generates "n" number of "c" characters
	
	return result; 
}


// Formats the 24 clock based
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {

	// Converts hours, minutes, and seconds to string
	string hours = twoDigitString(h);	
	string minutes = twoDigitString(m); 
	string seconds = twoDigitString(s); 

	string formatedTime = hours + ":" + minutes + ":" + seconds;	// Combines hour, minutes, seconds to single string

	return formatedTime;	// Returns the formatted time

}


// Formats the 12 hour clock using the 24 hour clock as a base
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {

	string timePeriod = (h < 12) ? "A M" : "P M"; // Determines AM or PM based on the hour

	unsigned int clock12 = h % 12; // Converts 24 hour time to 12 hour time

	if (clock12 == 0) { // Sets to 12 if clock12 is 0
		clock12 = 12;
	}

	// Converts hours, minutes, and seconds to string
	string hours = twoDigitString(clock12);
	string minutes = twoDigitString(m);
	string seconds = twoDigitString(s);

	string formatedTime = hours + ":" + minutes + ":" + seconds + " " + timePeriod;	// Combines hour, minutes, seconds to single string

	return formatedTime;	// Returns the formatted time

}

// Displays the 12 and 24 hour clocks to the user, formatted with nCharString
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {

	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;	// Top border

	cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << nCharString(3, ' ');	// 12 hour clock label

	cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl; // 24 hour clock label

	cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*" << nCharString(3, ' ');	// Prints formatted 12 hour clock

	cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;	// Prints formatted 24 clock

	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;	// Bottom border
}

// Displays the menu to add time to the user, formatted with nCharString
void printMenu(char* strings[], unsigned int numStrings, unsigned char width) {

	// Top border of menu
	cout << nCharString(width, '*') << endl;

	// Loop to get the menu options
	for (unsigned int i = 0; i < numStrings; ++i) {	
		string str = strings[i];	// Gets menu option text
		unsigned int index = i + 1;	// Assigns index with menu option text
		unsigned int strLength = str.length(); // Gets length of menu option text

		
		cout << "* " << index << " - " << str;	// Displays the menu options to the user

		unsigned int numSpaces = width - (7 + strLength); // Gets spaces for formatting
		cout << nCharString(numSpaces, ' '); // Uses spaces to properly format menu

		cout << "*" << endl;

		if (i < numStrings - 1) {		// Places a blank line between the menu options
			cout << endl;
		}
	}

	// Border border of menu
	cout << nCharString(width, '*') << endl;

}

// Accepts the user input for the menu choices
unsigned int getMenuChoice(unsigned int maxChoice) {
	unsigned int choice = 0;

	while (true) { // Asks for input until valid
		cin >> choice; // Asks for input for choice

		if (choice < 1 || choice > maxChoice) { // Check if choice is within valid range
			cout << "Invalid input. Please enter a number between 1 and 4" << endl;
			continue; // Repeats loop if input was invalid
		}
		else {
			return choice; // if choice is valid returns choice
		}
	}

}



// Gets the current hour
unsigned int getHour() {
	return currentHour;
}

// Sets the current hour
void setHour(unsigned int h) {
	currentHour = h;
}

// Gets the current minute
unsigned int getMinute() {
	return currentMinute;
}

// Set the current minute
void setMinute(unsigned int m) {
	currentMinute = m;
}

// Gets the current second
unsigned int getSecond() {
	return currentSecond;
}

// Sets the current second
void setSecond(unsigned int s) {
	currentSecond = s;
}

// Adds one hour to the current time
void addOneHour() {

	unsigned int currentHour = getHour();	// Gets current hour

	if (currentHour < 23) {			// If hour is less than 23
		setHour(currentHour + 1);	// adds 1 to hour
	}
	else {				// If hour is 24
		setHour(0);		// Set equal to 0
	}

}

// Adds one minute to the current time
void addOneMinute() {

	unsigned int currentMinute = getMinute();	// Gets current minute

	if (currentMinute < 59) {			// If minute is less than 59
		setMinute(currentMinute + 1);	// adds 1 to minute
	}
	else {				// If minute is 59
		setMinute(0);	// set minute to 0
		addOneHour();	// adds 1 to hour
	}

}

// Adds one second to the current time
void addOneSecond() {

	unsigned int currentSecond = getSecond(); // Gets current second

	if (currentSecond < 59) {			// If second if less then 59
		setSecond(currentSecond + 1);	// adds 1 to second
	}
	else {				// If second is 59
		setSecond(0);	// set second to 0
		addOneMinute();	// adds 1 to minute

	}

}

