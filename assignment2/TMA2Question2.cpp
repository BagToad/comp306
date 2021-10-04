/* 
 Title: TMA2Question2.cpp
 Description:
    Create a char array, a float array, a single int, and a single long using "new".
    Print the types and memory addresses of all variables.
    Delete the variables using "delete".
 Date: October 4, 2021
 Author: Kynan Ware
 Student ID: 3431123 
 Compile: g++ TMA2Question2.cpp -o TMA2Question2.exe
 Execution: ./TMA2Question2.exe
 
 Classes: none

 Variables:
 number - int - a number stored as int.
 long_number - long - a number stored as long.
 chars - char - an array of chars.
 floats - float - an array of floats.

 Constants:
 ARRAY_NUM - int - the number of items in either array. 

*/

/*
 TEST PLAN
 
 All test plans, unless noted, require an input file. 


 Normal case:

   

 
 Discussion:
 	

    The program returns an int as per the C++ standard.

    All testing performed in a Linux environment with g++ version 7.5.0.
*/

#include <iostream>

using namespace std;

int main(void) {
	const int ARRAY_NUM = 100;
	const char input_alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV";

	int* number = new int(1);
	long* long_number = new long(10000);

	char* chars = new char[ARRAY_NUM]();
	float* floats = new float[ARRAY_NUM]();

	//Fill char array with alphabet
	for (int i = 0; i < ARRAY_NUM; i++) {
		chars[i] = input_alphabet[i];
	}

	//Fill float array with values between 101 and 201.
	for (int i = 101; i <= 201; i++) {
		floats[i - 101] = (float) i;
	}

	cout << "int @ " << &number << " = " << *number << endl;
	cout << "long @ " << &long_number << " = " << *long_number << endl;

	for (int i = 0; i < ARRAY_NUM; i++) {
		cout << "char @ " << &chars << " = " << chars[i] << endl;
	}

	for (int i = 101; i <= 201; i++) {
		cout << "float @ " << &floats << " = " << floats[i - 101] << endl;
	}

	delete number;
	delete long_number;
	delete[] chars;
	delete[] floats;

    return 0;
}

