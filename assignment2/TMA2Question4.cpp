/* 
 Title: TMA2Question4.cpp
 Description:
    Open a text file and count whitespace separated words.
 Date: August 13, 2021
 Author: Kynan Ware
 Student ID: 3431123 
 Compile: g++ TMA2Question4.cpp -o TMA2Question4.exe
 Execution: ./TMA2Question4.exe
 
 Classes: none

 Variables:

*/

/*
 TEST PLAN
 
 All test plans, unless noted, require an input file. 


 Normal case 1:
 

 Normal case 2:
   

 Normal case 3:
  

 Bad Data case 1:
 

 Bad Data case 2 (illegal characters in filename input)


 Bad Data case 3 (empty file)
  
 
 Bad Data case 4 (file with newlines and special characters)
   

 
 Discussion:
 	

    The program returns an int as per the C++ standard.

    All testing performed in a Linux environment with g++ version 7.5.0.
*/

#include <fstream>
#include <iostream>

using namespace std;

class Text {
	string input_text;
	string line;
public:
	Text() {
	}

	Text(string f) {
		ifstream in;
		in.open(f);

		//Check if input file exists.
	    if (! in) {
	    	cout << "File does not exist!" << endl;
	    	return;
	    }

		while (getline(in, line)) {
			input_text = input_text + line + "\n";
		}
	}

	void contents() {
		cout << endl << input_text << endl;
	}
};

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

    Text t = Text(filename);
    t.contents();

    return 0;
}

