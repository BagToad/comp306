/* 
 Title: TMA3Question3.cpp
 Description:
    Demonstrate and test operator overloading.
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
	The program overloads the following operators: +, -, ++, --, and <<. The program implements the postfix/prefix variants
	of the increment and decrement operators.

	The program initializes and defines 3 sets of alphanumerically named DoStuff instances to test with. These instances are named a alpha 
	character followed by a numeric character. The numeric portion of the variable names are incremented
	depending on the test being performed. However, the output to the console to narrate the tests only refers to these variables by
	the alpha character - this is to keep the output simple.   

	The + and - operators were fairly easy to implement. The biggest revelation for me was understanding the impact of an operator being
	a member function or not. My understanding is that a non-member function gets both operands as the arguements, while a member function
	assumes that 'this' is the left operand.

	The postfix and prefix operator variants were relatively straightforward. Saving the existing value before performing the prefix
	operation is very natural. 

	The "<<" operator was the most difficult for me to wrap my head around. I believe it must be defined as a friend function because
	the ostream class needs access to it; when the left operand is an ostream and the right operand is a DoStuff instance, the <<
	operator is used to convert to an ostream&. 
	
	The program returns an int as per the C++ standard.
	
	All testing performed in a Linux environment with g++ version 7.5.0.
*/

#include <iostream>
#include <string>

using namespace std;

class DoStuff {
	int value;
	//Disable default constructor.
	DoStuff() {};

public:
	//Create an instance of DoStuff.
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
	cout << "\n=== Testing overloaded << operator ===" << endl;
	cout << "Values: a = 5" << endl;
	cout << "\nExpression: cout << \"a = \" << a << \", b = \" << b << endl;" << endl;
	cout << "Result: a = " << a3 << ", b = " << b3 << endl;

	//Create test instances
	DoStuff a4(5);
	DoStuff b4(10);
	DoStuff c4(1);
	DoStuff d4(15);

	//Test complex expressions
	cout << "\n=== Testing a complex expression ===" << endl;
	cout << "Values: a = 5, b = 10, c = 1, d = 15" << endl;
	cout << "\nExpression: cout << a + b + c - d << c++ << d-- << --a << --b" << endl;
	cout << "Result: " << a + b + c - d << c++ << d-- << --a << --b << endl;

	return 0;
}