//: TMA1Question5.cpp

/* 
 Title: TMA1Question5.cpp
 Description: 
 	Create 100 string objects and fill them with lines from an input file.
 	Print the lines to the terminal prefixed by the line number.
 Date: August 15, 2021
 Author: Kynan Ware
 Student ID: 3431123
 Execution: ./TMA1Question5.exe
 
 Classes: none

 Variables:
 

*/

/*
 TEST PLAN

 All test plans, unless noted, require the creation of an input file. 

 Normal case:
    Input file (input1.txt) contents:
        This is line 1
        This is line 2
        This is line 3

    >

 Normal case 2 (file with newlines and special characters)
    Input file (input3.txt) contents:
        This is line 1
        This is line 2
        This is line 3 followed by blank lines
        
        
        
        This is line 7 with !?@$%^+=&*();

    >Filename to open: input3.txt
    >

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
 	The program will load 100 lines from the input file into an array of 100 string objects. If the input file exceeds 100 lines, the rest 
 	are ignored; only the first 100 are read. If the input file contains less than 100 lines, all available lines are read. 

 	The test input files input4.txt and input5.txt were generated with unix command lines:

 	input4.txt:
 	while [ $i -lt 100 ]; do i=$(($i + 1)); echo "this is line # $i" >> input4.txt; done

	input5.txt
	while [ $i -lt 200 ]; do i=$(($i + 1)); echo "this is line # $i" >> input5.txt; done
 
*/

#include <iostream> // Stream declarations
#include <fstream> // I/O stream declarations
using namespace std;

int main(void) {
	string string_store[99];
	fstream in;
	string line;
	string filename;

	//Get filename to open from user.
	cout << "Filename to open: ";
	cin >> filename;
	in.open(filename);

    //Check if input file exists.
    if (! in) {
    	cout << "File does not exist!" << endl;
    	return 1;
    }

    for (int i = 1; i < 101; i++) {
    	
    	//If at eof, then break;
    	if (! getline(in, line)) {
    		break;
    	}
    	string_store[i] = line;
    	cout << "line " << i << ": " << string_store[i] << endl;
    }

    return 0;
}

