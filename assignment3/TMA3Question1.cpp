/* 
 Title: TMA3Question1.cpp
 Description:
    Track DVD information. Import DVD data from a text file.
 Date: October 4, 2021
 Author: Kynan Ware
 Student ID: 3431123 
 Compile: g++ TMA3Question1.cpp -o TMA3Question1.exe
 Execution: ./TMA3Question1.exe
 
 Classes:

 Variables:
 in - fstream - a stream to read the text file. 

 Constants:


*/

/*
 TEST PLAN
 
 All test plans, unless noted, require an input file. 


 Normal case 1 ():
 

 Normal case 2 ():
	

 Normal case 3 ():
	
	
 Bad Data case 1 (only newlines in input file):
	

 Bad Data case 2 (Non-integer data in some years in input file)
	

 Bad Data case 3 (A couple newlines in between valid entries)
 	

 Discussion:

	
    The program returns an int as per the C++ standard.

    All testing performed in a Linux environment with g++ version 7.5.0.
*/

#include <iostream>

using namespace std;

int main(void) {
	ifstream in;
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

	return 0;
}

