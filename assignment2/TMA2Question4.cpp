/* 
 Title: TMA2Question4.cpp
 Description:
    Implement and test a Text class to store the contents of a text file. 
 Date: October 4, 2021
 Author: Kynan Ware
 Student ID: 3431123 
 Compile: g++ TMA2Question4.cpp -o TMA2Question4.exe
 Execution: ./TMA2Question4.exe
 
 Classes:
 Text - Store the contents of a text file 

 Variables:
 filename - string - a string to hold the text file's filename.
 Text.input_text - string - a storage variable for the text read from the text file.
 Text.line - string - a temporary store for the current line being read from the text file.
*/

/*
 TEST PLAN
 
 All test plans, unless noted, require an input file. 

 Normal case 1 (normal text data):
 	Input file (input1.txt) contents:
	 	The Dark Night
		2008
		12 Angry Men
		1957
		Schindler's List
		1993
		The Lord of the Rings: The Return of the King
		2003
		Pulp Fiction
		1994
		The Good, the Bad, and the Ugly
		1966
		The Lord of the Rings: The Fellowship of the Ring
		2001
	
	>Filename to open: input1.txt
	=== PRINTING STORED TEXT ===

	The Dark Night
	2008
	12 Angry Men
	1957
	Schindler's List
	1993
	The Lord of the Rings: The Return of the King
	2003
	Pulp Fiction
	1994
	The Good, the Bad, and the Ugly
	1966
	The Lord of the Rings: The Fellowship of the Ring
	2001


 Normal case 2 (text data with newlines and special characters):
   Input file (input7.txt) contents:
	   The quick brown

		fox jumped

		over the

		lazy



		dog
		.

		!@#$%$^$&^&*^^&$!@#$%^&*(*&^%$#@#$%^&*()(*&^%$#@
	
	>Filename to open: input7.txt
	=== PRINTING STORED TEXT ===

	The quick brown

	fox jumped

	over the

	lazy



	dog
	.

	!@#$%$^$&^&*^^&$!@#$%^&*(*&^%$#@#$%^&*()(*&^%$#@


 Normal case 3 (very long line of input text):
	Input file (input8.txt) contents:
		1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
	
	>Filename to open: input8.txt
	=== PRINTING STORED TEXT ===

	1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111


 Bad Data case 1 (empty file):
 	Input file (input9.txt) is empty.

 	>Filename to open: input9.txt	
	=== PRINTING STORED TEXT ===


 Bad Data case 2 (file does not exist):
	Input file (inputdoesnotexists.txt) does not exist.

	>Filename to open: inputdoesnotexist.txt
	File does not exist!
	=== PRINTING STORED TEXT ===


 Discussion:
 	The program will open an input file and load the contents in a Text class. The program will then print the text it stored.


	If the input file is empty or does not exit, the program will still attept to print out the stored text when the 
	Text.contents() method is called.

    The program returns an int as per the C++ standard.

    All testing performed in a Linux environment with g++ version 7.5.0.
*/

#include <fstream>
#include <iostream>

using namespace std;

class Text {
private:
	string input_text;
	string line;
public:

	//Default constructor for Text object.
	Text() {
	}

	//Create a Text object and load the input_text member variable with the contents of file named f.
	Text(string f) {
		ifstream in;
		in.open(f);

		//Check if input file exists.
	    if (! in) {
	    	cout << "File does not exist!" << endl;
	    	return;
	    }

	    //Load each line into string. 
		while (getline(in, line)) {
			input_text = input_text + line + "\n";
		}
	}

	//Print the stored text.
	void contents() {
		cout << "=== PRINTING STORED TEXT ===" << endl;
		cout << endl << input_text << endl;
	}
};

int main(void) {
    string filename;

	//Get the filename to open from the user.
	cout << "Filename to open: ";
	cin >> filename;

    Text t = Text(filename);
    t.contents();

    return 0;
}

