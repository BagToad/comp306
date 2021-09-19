//: TMA1Question2.cpp

/* 
 Title: TMA1Question2.cpp
 Description: Open TMA1Question2.txt and print the lines to the console. Print lines as the user presses enter. 
 Date: August 13, 2021
 Author: Kynan Ware
 Student ID: 3431123
 Execution (assuming Cygwin is running): ./TMA1Question2.exe
  
 Classes: none

 Variables:
 in - fstream - stream to read the TMA1Question2.txt input file.
 line - string - sring to store the current line of the input file. 

*/

/*
 TEST PLAN
 
 Normal case:
 	>What is your name? Richard
 	>What is your age? 21
 	>Hello! My name is Richard, and I am 21 years old!
 	>In 10 years, I will be 31 years old!

 Bad Data case 1 (more than one name)
 	>What is your name? Richard Huntrods
 	>What is your age? 21
 	>Hello! My name is Richard, and I am 21 years old!
 	>In 10 years, I will be 31 years old!
 
 Bad Data case 2 (nonsense or non-alpha name)
 	>What is your name? zb23xx!
 	>What is your age? 21
 	>Hello! My name is zb23xx!, and I am 21 years old!
 	>In 10 years, I will be 31 years old!
 
 Bad Data case 3 (negative age)
 	>What is your name? Richard
 	>What is your age? -1
 	>Hello! My name is Richard, and I am -1 years old!
 	>In 10 years, I will be 9 years old!
 
 Bad Data case 4 (floating point age)
 	>What is your name? Richard
 	>What is your age? 12.5
 	>Hello! My name is Richard, and I am 12 years old!
 	>In 10 years, I will be 22 years old!
 
 Discussion:
 	The program accepts only a single word for the name input (whitespace delimits the word - comma, space, period, etc.)
 	The program also attempts to convert the age input into an integer, even if this produces a nonsense result (i.e. 'five').
 	Negative numbers are allowed and processed as if legitimate, and floating point numbers are truncated.
 
*/

#include <iostream> // Stream declarations
#include <fstream> // Stream declarations
#include <string> // String declarations
using namespace std;

int main(void) {
	fstream in;
	string line;
	string filename;

	//Get filename to open from user.
	cout << "Filename to open: ";
	cin >> filename;
	in.open(filename);

    //Ignore the enter key in cin following filename input. 
    cin.ignore();

    //Check if input file exists.
    if (! in) {
    	cout << "File does not exist!" << endl;
    	return 1;
    }

    //Read lines from the file, continue when user presses enter. 
    while (getline(in, line)) {
    	cout << line << endl;
		cout << "Press ENTER to continue..." << endl;
		cin.get();
    }

    return 0;
}

