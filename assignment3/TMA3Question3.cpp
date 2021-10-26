/* 
 Title: TMA3Question3.cpp
 Description:
    Track DVD information. Import DVD data from a text file.
 Date: October 4, 2021
 Author: Kynan Ware
 Student ID: 3431123 
 Compile: g++ TMA3Question3.cpp -o TMA3Question3.exe
 Execution: ./TMA3Question3.exe
 
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
#include <string>

using namespace std;

class DoStuff {
	int value;
public:

	DoStuff(int x) {
		value = x;
	}

	void print(ostream& os) {
		os << "value: " << value << endl;
	}

	const DoStuff operator+(const DoStuff& x) const {
		return DoStuff(value + x.value);
	}

	const DoStuff operator-(const DoStuff& x) const {
		return DoStuff(value - x.value);
	}

	const DoStuff operator++(int) {
		DoStuff beforeValue(value);
		value++;
		return beforeValue;
	}

	const DoStuff operator++() {
		value++;
		return *this;
	}

	const DoStuff operator--(int) {
		DoStuff beforeValue(value);
		value--;
		return beforeValue;
	}

	const DoStuff operator--() {
		value--;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const DoStuff& s) {
		return os << to_string(s.value);
	}
};

int main(void) {
	DoStuff thing1(1);
	DoStuff thing2(2);
	DoStuff thing3(3);
	thing1 = thing1 - thing2 + thing3;
	thing1.print(cout);

	thing2++;
	++thing2;
	thing2.print(cout);

	cout << "printing value of thing1: " << thing1 << endl;
	return 0;
}