/* 
 Title: TMA3Question2.cpp
 Description:
    Build two arrays of 10,000 doubles, multiply them, and print the result.
    Also prints the program duration.
 Date: October 21, 2021
 Author: Kynan Ware
 Student ID: 3431123 
 Compile: g++ TMA3Question2.cpp -o TMA3Question2.exe
 Execution: ./TMA3Question2.exe
 
 Variables:
 	double - first_doubles[num_doubles] - The first array of doubles.
	double - second_doubles[num_doubles] - The first array of doubles.

 Constants:
	 int - num_doubles - The number of doubles in each double array.
	 high_resolution_clock::time_point - start_time - The time the program started in milliseconds.
	 high_resolution_clock::time_point - stop_time - The time the program completed multiplication in milliseconds.

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

#include <iostream> //iostream provides io.
#include <chrono> //chrono provides accurate time tracking.

using namespace std;
using namespace std::chrono;

//Multiply two doubles then return the result.
int calc (double first_double, double second_double) {
	return first_double * second_double;
}

int main(void) {
	const int num_doubles = 10000;
	const high_resolution_clock::time_point start_time = high_resolution_clock::now();

	double first_doubles[num_doubles];
	double second_doubles[num_doubles];

	//Build the double arrays.
	for (int i = 0; i <= num_doubles; i++) {
		first_doubles[i] = i + 100;
		second_doubles[i] = 10100 - i;
	}

	//Execute function to sum and print result. 
	for (int i = 0; i <= num_doubles; i++) {
		cout << first_doubles[i] << " * " << second_doubles[i] << " = " << calc(first_doubles[i], second_doubles[i]) << endl;
	}

	//Adapted from http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/
	const high_resolution_clock::time_point stop_time = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(stop_time - start_time);

	cout << "\n DURATION: "	<< time_span.count() << endl;
	return 0;
}