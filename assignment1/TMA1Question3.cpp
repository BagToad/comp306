/* 
 Title: TMA1Question3.cpp
 Description:
 	Fill three vectors. First vector is filled with values between 0 and 24.
 	Second vector is filled with the first vector squared.
 	Third vector is filled with the sum of the first and second vectors. 
 Date: August 14, 2021
 Author: Kynan Ware
 Student ID: 3431123
 Compile: g++ TMA1Question3.cpp -o TMA1Question3.exe
 Execution: ./TMA1Question3.exe
 
 Classes: none

 Variables:
 vec1, vec2, vec3 - vector<float> - vectors to hold floating point numbers for the program's operation.
*/

/*
 TEST PLAN
 
 Normal case:
 	>for 0; 0 + 0 = 0
	>for 1; 1 + 1 = 2
	>for 2; 2 + 4 = 6
	>for 3; 3 + 9 = 12
	>for 4; 4 + 16 = 20
	>for 5; 5 + 25 = 30
	>for 6; 6 + 36 = 42
	>for 7; 7 + 49 = 56
	>for 8; 8 + 64 = 72
	>for 9; 9 + 81 = 90
	>for 10; 10 + 100 = 110
	>for 11; 11 + 121 = 132
	>for 12; 12 + 144 = 156
	>for 13; 13 + 169 = 182
	>for 14; 14 + 196 = 210
	>for 15; 15 + 225 = 240
	>for 16; 16 + 256 = 272
	>for 17; 17 + 289 = 306
	>for 18; 18 + 324 = 342
	>for 19; 19 + 361 = 380
	>for 20; 20 + 400 = 420
	>for 21; 21 + 441 = 462
	>for 22; 22 + 484 = 506
	>for 23; 23 + 529 = 552
	>for 24; 24 + 576 = 600

 
 Discussion:
 	The program doesn't take any input, and so test plans are limited. The program should execute the same every time.
 	The program will fill 3 vectors in the following way: the first vector
 	is filled with the loop counter. The second vector is filled with the first vector squared. The third vector
 	is filled with the sum of the first two vectors. 

 	The first and second vectors are fill in a different for loop than the third vector. This is an implementation detail
 	required by the assignment, but it could be eliminated by writing all three vector assignments in one loop.
 
 	The program returns an int as per the C++ standard. The retun value is always 0.

 	All testing performed in a Linux environment with g++ version 7.5.0.
*/

#include <vector> // Vector declarations
#include <iostream> // Stream declarations 
#include <cmath> // Math declarations
using namespace std;

int main(void) {
	vector<float> vec1, vec2, vec3;

	//Fill first two vectors with the current value and the current value squared, respectively.
	for (int i = 0; i < 25; i++) {
		vec1.push_back(i);
		vec2.push_back(pow(vec1[i], 2));
	}

	//Fille the third vector with the sum of the first and second vectors. 
	for (int i = 0; i < vec1.size(); i++){
		vec3.push_back(vec1[i] + vec2[i]);
		cout << "for " << i << "; " << vec1[i] << " + " << vec2[i] << " = " << vec3[i] << endl;
	}
	
    return 0;
}

