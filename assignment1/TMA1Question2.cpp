//: TMA1Question2.cpp

/* 
 Title: TMA1Question2.cpp
 Description: 
    Open TMA1Question2.txt and print the lines to the console. Print one line initially, 
    then only print the next line when the user presses enter.
 Date: August 13, 2021
 Author: Kynan Ware
 Student ID: 3431123
 Execution: ./TMA1Question2.exe
  
 Classes: none

 Variables:
 in - fstream - stream to read the TMA1Question2.txt input file.
 line - string - sring to store the current line of the input file. 

*/

/*
 TEST PLAN

 All test plans, unless noted, require the creation of an input file. 

 Normal case 1:
    Input file (input1.txt) contents:
        This is line 1
        This is line 2
        This is line 3

    >Filename to open: input1.txt
    >This is line 1
    >Press ENTER to continue...
    >This is line 2
    >Press ENTER to continue...
    >This is line 3
    >Press ENTER to continue...

 Normal case 2 (file with newlines and special characters)
    Input file (input3.txt) contents:
        This is line 1
        This is line 2
        This is line 3 followed by blank lines
        
        
        
        This is line 7 with !?@$%^+=&*();

    >Filename to open: input3.txt
    >This is line 1
    >Press ENTER to continue...
    >This is line 2
    >Press ENTER to continue...
    >This is line 3 followed by blank lines
    >Press ENTER to continue...
    >
    >Press ENTER to continue...
    >
    >Press ENTER to continue...
    >
    >Press ENTER to continue...
    >This is line 7 with !?@$%^+=&*();
    >Press ENTER to continue...

Normal case 3:
    Input file (input6.txt) contents:
     The quick brown fox jumped over the lazy dog.
     The quick brown fox jumped over the lazy dog.
     The quick brown fox jumped over the lazy dog.
     The quick brown fox jumped over the lazy dog.
    
    >Filename to open: input6.txt
    TODO

 Normal case 4 (long input line):
    Input file (input7.txt) contents:
    This is a very long line of text. This is a very long line of text. This is a very long line of text. This is a very long line of text. This is a very long line of text. This is a very long line of text. This is a very long line of text. This is a very long line of text. This is a very long line of text. This is a very long line of text. This is a very long line of text.
    
    >Filename to open: input7.txt
    TODO

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
    (No output)
 
 Discussion:
 	The program open the input file and read the file line by line as the user presses enter. If opening the input
    file fails (file does not exists), the program will print an error. 

    The ">>" operator is not used to retrieve data from cin because it excludes newline characters. Instead the 
    cin.get() function is used. This 
 
*/

#include <iostream> // Stream declarations
#include <fstream> // I/O stream declarations
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
		cout << "Press ENTER to continue...";
		cin.get();
    }

    return 0;
}

