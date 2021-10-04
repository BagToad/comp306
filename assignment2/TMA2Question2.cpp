/* 
 Title: TMA2Question2.cpp
 Description:
    Open a text file and count whitespace separated words.
 Date: August 13, 2021
 Author: Kynan Ware
 Student ID: 3431123 
 Compile: g++ TMA2Question2.cpp -o TMA2Question2.exe
 Execution: ./TMA2Question2.exe
 
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

#include <iostream>

using namespace std;

int main(void) {
	 char input_alphabet[101] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV";


	int* number = new int(1);
	long* long_number = new long(10000);

	char* chars = new char[100]();
	float* floats = new float[100]();

	for (int i = 0; i < 100; i++) {
		chars[i] = input_alphabet[i];
	}

	for (int i = 101; i <= 201; i++) {
		floats[i - 101] = (float) i;
	}


	cout << "int @ " << &number << " = " << *number << endl;
	cout << "long @ " << &long_number << " = " << *long_number << endl;

	for (int i = 0; i < 100; i++) {
		cout << "char @ " << &chars << " = " << chars[i] << endl;
	}

	for (int i = 101; i <= 201; i++) {
		cout << "float @ " << &floats << " = " << floats[i - 101] << endl;
	}


	delete number;
	delete long_number;
	delete[] chars;
	delete[] floats;

	
	// long long_number = 100;
	// char chars[100];
	// float floats[100];


    return 0;
}

