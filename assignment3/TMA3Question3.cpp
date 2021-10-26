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
	DoStuff - A class to demonstrate operator overloading.
	
 Variables:
	DoStuff.value - int - A class member variable used to test operator overloading.

	a1, b1, c1 - DoStuff - Instances to test overloaded + and - operators using the DoStuff class. 
	a2, b2, c2, d2 - DoStuff - Instances to test overloaded prefix/postfix ++ and -- operators using the DoStuff class.
	a3, b3 - DoStuff - Instances to test overloaded << operator using the DoStuff class. 
 Constants:
 	None.
*/

/*
 TEST PLAN
 
 Normal case 1 (static program, no input):
	>=== Testing overloaded + and - operators ===
	>Values: a = 5, b = 10, c = 15
	>
	>Expression: a + b - c + a
	>Result: 5
	>
	>=== Testing postfix/prefix overloaded ++ and -- operators ===
	>Values: a = 5, b = 5, c = 5, d = 5
	>
	>Expression: a++
	>Result: 5
	>
	>Expression: ++b
	>Result: 6
	>
	>Expression: c--
	>Result: 5
	>
	>Expression: --d
	>Result: 4
	>
	>===Testing overloaded << operator ===
	>Values: a = 5
	>
	>Expression: cout "a = " << a << ", b = " << b << endl;
	>Result: a = 5, b = 15


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

	//Print value to ostream.
	void print(ostream& os) {
		os << value;
	}

	//Binary addition operator.
	const DoStuff operator+(const DoStuff& x) const {
		return DoStuff(value + x.value);
	}

	//Binary subtraction operator.
	const DoStuff operator-(const DoStuff& x) const {
		return DoStuff(value - x.value);
	}

	//Prefix increment operator. 
	const DoStuff operator++(int) {
		DoStuff beforeValue(value);
		value++;
		return beforeValue;
	}

	//Postfix increment operator.
	const DoStuff operator++() {
		value++;
		return *this;
	}

	//Prefix decrement operator. 
	const DoStuff operator--(int) {
		DoStuff beforeValue(value);
		value--;
		return beforeValue;
	}

	//Postfix decrement operator. 
	const DoStuff operator--() {
		value--;
		return *this;
	}

	//ostream output operator.
	friend ostream& operator<<(ostream& os, const DoStuff& s) {
		return os << to_string(s.value);
	}
};

int main(void) {

	//Create test instances. 
	DoStuff a1(5);
	DoStuff b1(10);
	DoStuff c1(15);

	//Test + and - operators. 
	cout << "=== Testing overloaded + and - operators ===" << endl;
	cout << "Values: a = 5, b = 10, c = 15" << endl;
	cout << "\nExpression: a + b - c + a" << endl;
	cout << "Result: " << (a1 + b1 - c1 + a1) << endl;

	//Create test instances. 
	DoStuff a2(5);
	DoStuff b2(5);
	DoStuff c2(5);
	DoStuff d2(5);

	//Test prefix/postfix ++ and -- operators. 
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

	//Create test instances.
	DoStuff a3(5);
	DoStuff b3(15);

	//Test << operator. 
	cout << "\n===Testing overloaded << operator ===" << endl;
	cout << "Values: a = 5" << endl;
	cout << "\nExpression: cout \"a = \" << a << \", b = \" << b << endl;" << endl;
	cout << "Result: a = " << a3 << ", b = " << b3 << endl;

	return 0;
}