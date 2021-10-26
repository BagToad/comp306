/* 
 Title: TMA3Question3.cpp
 Description:
    Track DVD information. Import DVD data from a text file.
 Date: October 26, 2021
 Author: Kynan Ware
 Student ID: 3431123 
 Compile: g++ TMA3Question3.cpp -o TMA3Question3.exe
 Execution: ./TMA3Question3.exe
 
 Classes:
	
 Variables:
	
 Constants:
*/

/*
 TEST PLAN
 
 All test plans, unless noted, require an input file. 


 Normal case 1 (static program, no input):



 
 	

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
	DoStuff a1(5);
	DoStuff b1(10);
	DoStuff c1(15);

	cout << "=== Testing overloaded + and - operators ===" << endl;
	cout << "Values: a = 5, b = 10, c = 15" << endl;
	cout << "\nExpression: a + b - c + a" << endl;
	cout << "Result: " << (a1 + b1 - c1 + a1) << endl;

	DoStuff a2(5);
	DoStuff b2(5);
	DoStuff c2(5);
	DoStuff d2(5);

	//Test prefix and postfix operators. 
	cout << "\n=== Testing postfix/prefix overloaded ++ and -- operators ===" << endl;
	cout << "Values: a = 5, b = 5, c = 5, d = 5" << endl;
	cout << "\nExpression: a++" << endl;
	cout << "Result: " << a2++ << endl;
	cout << "\nExpression: ++b" << endl;
	cout << "Result: " << ++b2 << endl;
	cout << "\nExpression: c--" << endl;
	cout << "Result: " << c2-- << endl;
	cout << "\nExpression: --d" << endl;
	cout << "Result: " << --d2 << endl;


	DoStuff a3(5);
	DoStuff b3(15);

	cout << "\n===Testing overloaded << operator ===" << endl;
	cout << "Values: a = 5" << endl;
	cout << "\nExpression: cout \"a = \" << a << \", b = \" << b << endl;" << endl;
	cout << "Result: a = " << a3 << ", b = " << b3 << endl;

	return 0;
}