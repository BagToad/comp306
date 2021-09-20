//: TMA1Question1.cpp

/* 
 Title: TMA1Question1.cpp
 Description: Open a text file and count whitespace separated words.
 Date: August 13, 2021
 Author: Kynan Ware
 Student ID: 3431123 
 Execution (assuming Cygwin is running): ./TMA1Question1.exe
 
 Classes: none

 Variables:
 in - fstream - a stream to read the TMA1Question1.txt input file. 
 word - string - a string variable to hold the next word. 
 count - int - a counter integer to count how many words have been seen.

*/

/*
 TEST PLAN
 
 All test plans, unless noted, require the creation of an input file. 


 Normal case:
    Input file (input1.txt) contents:
        This is line 1
        This is line 2
        This is line 3
    >Filename to open: input1.txt
    >There are 12 whitespace delimited words in input1.txt.

 Bad Data case 1 (no file exists):
    Input file does not exist.
    >Filename to open: input1000.txt
    >File does not exist!
 
 Bad Data case 2 (illegal characters in filename input)
    Input file does not exist because it is an illegal filename.
    >Filename to open: !?@$%^+=&*();
    >File does not exist!
 
 Bad Data case 3 (empty file)
    Input file (input2.txt) contents should be none. In unix, execute "> input2.txt" without quotations. 
    >Filename to open: input2.txt
    >There are 0 whitespace delimited words in input2.txt.
 
 Bad Data case 4 (file with newlines and special characters)
    Input file (input3.txt) contents:
        This is line 1
        This is line 2
        This is line 3 followed by blank lines
        
        
        
        This is line 7 with !?@$%^+=&*();
    >Filename to open: input3.txt
    >There are 22 whitespace delimited words in input3.txt.

 
 Discussion:
 	The program will count whitespace separated words in the input file. If opening the input
    file fails (file does not exists), the program will print an error. If there is no whitespace in the file,
    begginning and ending of the file are treated as whitespace (one word without whitespace on either
    side is still one word).
 
*/

#include <iostream> // Stream declarations
#include <fstream> // Stream declarations
#include <string> // String declarations
using namespace std;

int main(void) {
	string word;
	ifstream in;
    int count;
    string filename;

	//Get the filename to open from the user.
	cout << "Filename to open: ";
	cin >> filename;
	in.open(filename);

    //Check if input file exists.
    if (! in) {
    	cout << "File does not exist!" << endl;
    	return 1;
    }

    //Loop through the text file and count words. 
    while (in >> word) {
    	count++;
    }

    //Print the result. 
    cout << "There are " << count << " whitespace delimited words in " << filename << "." << endl;

    //Return 0 for portability. 
    return 0;
}

