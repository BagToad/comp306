/* 
 Title: TMA1Question1.cpp
 Description:
    Open a text file and count whitespace separated words.
 Date: August 13, 2021
 Author: Kynan Ware
 Student ID: 3431123 
 Compile: g++ TMA1Question1.cpp -o TMA1Question1.exe
 Execution: ./TMA1Question1.exe
 
 Classes: none

 Variables:
 in - fstream - a stream to read the text file. 
 word - string - a string variable to hold the next word. 
 count - int - a counter integer to count how many words have been seen.
 filename - strong - a string to hold the text file's filename. 
*/

/*
 TEST PLAN
 
 All test plans, unless noted, require an input file. 


 Normal case 1:
    Input file (input1.txt) contents:
        This is line 1
        This is line 2
        This is line 3
    
    >Filename to open: input1.txt
    >There are 12 whitespace delimited words in input1.txt.

 Normal case 2:
    Input file (input6.txt) contents:
     The quick brown fox jumped over the lazy dog.
     The quick brown fox jumped over the lazy dog.
     The quick brown fox jumped over the lazy dog.
     The quick brown fox jumped over the lazy dog.
    
    >Filename to open: input6.txt
    >There are 36 whitespace delimited words in input6.txt.

 Normal case 3 (long input line):
    Input file (input7.txt) contents:
    This is a very long line of text. This is a very long line of text. This is a very long line of text. This is a very long line of text. This is a very long line of text. This is a very long line of text. This is a very long line of text. This is a very long line of text. This is a very long line of text. This is a very long line of text. This is a very long line of text.
    
    >Filename to open: input7.txt
    >There are 88 whitespace delimited words in input7.txt.

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

    The program returns an int as per the C++ standard. The retun value is 0 unless the input file cannot be opened. 

    All testing performed in a Linux environment with g++ version 7.5.0.
*/

#include <iostream> // Stream declarations
#include <fstream> // I/O stream declarations
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

