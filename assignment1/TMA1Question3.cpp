//: TMA1Question3.cpp

/* 
 Title: TMA1Question3.cpp
 Description: 
 Date: August 14, 2021
 Author: Kynan Ware
 Student ID: 3431123
 Execution: ./TMA1Question3.exe
 
 Classes: none

 Variables:
 

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

#include <vector> // Vector declarations
#include <iostream> // Stream declarations 
using namespace std;

int main(void) {
	vector<float> vec1, vec2, vec3;
	
	for (int i = 0; i < 25; i++) {
		vec1.push_back( (float) i);
		vec2.push_back( (float) (i ^ 2));
	}

	for (int i = 0; i < 25; i++){
		vec3.push_back(vec1[i] + vec2[i]);
		cout << "for " << i << "; " << vec1[i] << " + " << vec2[i] << " = " << vec3[i] << endl;
	}
	
    return 0;
}

