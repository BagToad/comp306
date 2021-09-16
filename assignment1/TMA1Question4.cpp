//: TMA1Question4.cpp

/* 
 Title: TMA1Question4.cpp
 Description: Detect prime numbers from 1 to 10,000
 Date: August 15, 2021
 Author: Kynan Ware
 Student ID: 3431123
 Execution: ./TMA1Question4.exe
 
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

#include <iostream>
using namespace std;

int main(void) {
	//Loop through all numbers between 0 and 10,000.
	for (int i = 0; i < 10000; i++) {
		bool prime = true;

		//0 and 1 are prime numbers.
		if (i <= 1) {
			continue;
		}

		//Loop through all numbers lower than current number. 
		for (int k = 2; k < i; k++) {
			//If i is divisible by k, not a prime number. 
			if (i % k == 0) {
				prime = false;
				break;
			}
		}

		//Print if the value is a prime number.
		if (prime == true) {
			cout << i << " is a prime number." << endl;
		}
	}
    return 0;
    return 0;
}

