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
#include <chrono>

using namespace std;
using namespace std::chrono;

int output (double first_double, double second_double) {
	// int out = first_double * second_double;
	// cout << first_double << " * " << second_double << " = " << out << endl;
	return first_double * second_double;
}

int main(void) {
	const int num_doubles = 10000;
	const high_resolution_clock::time_point start_time = high_resolution_clock::now();

	double first_doubles[num_doubles];
	double second_doubles[num_doubles];

	for (int i = 0; i <= num_doubles; i++) {
		first_doubles[i] = i + 100;
		second_doubles[i] = 10100 - i;
	}
	int out;
	// for (int i = 0; i <= 100; i++){
		for (int i = 0; i <= 10000; i++) {
			out = output(first_doubles[i], second_doubles[i]);
			cout << "output: " << out << endl;
		}
	// }
	
	//Adapted from http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/
	const high_resolution_clock::time_point stop_time = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(stop_time - start_time);

	cout << "\n DURATION: "	<< time_span.count() << endl;
	return 0;
}

