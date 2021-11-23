/* 
 Title: TMA4Question2.cpp
 Description:
 	Create an inheritance hieararchy for different rodent types.
 Date: Nov 18, 2021
 Author: Kynan Ware
 Student ID: 3431123
 Compile: g++ TMA4Question2.cpp -o TMA4Question2.exe
 Execution: ./TMA4Question2.exe
 
 Variables:
 Rodent* - rodents[10] - an array of rodents. 
*/

/*
 TEST PLAN (static program, no input)
	>===Rodent #1 Characteristics===
	>Species: Hamster
	>Tail length: Stubby
	>===Rodent #2 Characteristics===
	>Species: Mouse
	>Tail length: long
	>===Rodent #3 Characteristics===
	>Species: Gerbil
	>Tail length: long
	>===Rodent #4 Characteristics===
	>Species: Hamster
	>Tail length: Stubby
	>===Rodent #5 Characteristics===
	>Species: Mouse
	>Tail length: long
	>===Rodent #6 Characteristics===
	>Species: Gerbil
	>Tail length: long
	>===Rodent #7 Characteristics===
	>Species: Hamster
	>Tail length: Stubby
	>===Rodent #8 Characteristics===
	>Species: Mouse
	>Tail length: long
	>===Rodent #9 Characteristics===
	>Species: Gerbil
	>Tail length: long
	>===Rodent #10 Characteristics===
	>Species: Hamster
	>Tail length: Stubby

 
 Discussion:
	This program implements an inheritance hierarchy for the parent class Rodent, and
	the subclasses Mouse, Gerbil, and Hamster. 

	An array of 10 Rodents is create and filled with different Rodent types. The types 
	of Rodents are cycled as they are put into the array to ensure variety. 

	By having the Rodents in an array, the different Rodent subclasses are upcast
	into Rodents. This is demonstrated by the fact that, for example, Hamster fits
	into an array of Rodents.

	Additionally, the Rodent class is purely abstract. The class features only virtual
	functions.
	
	The program returns an int as per the C++ standard.
	All testing performed in a Linux environment with g++ version 7.5.0.
*/

#include <iostream> //iostream provides io.

using namespace std;

class Rodent {
public:
	//Return the rodent species.
	virtual string getSpecies() {return "";}

	//Return the rodent's tail length.
	virtual string getTailLength() {return "";}
};

class Mouse : public Rodent {
public:
	// Mouse() : Rodent() {};

	string getSpecies() override {
		return "Mouse";
	}

	string getTailLength() {
		return "long";
	}
};

class Gerbil : public Rodent {
	string getSpecies() {
		return "Gerbil";
	}

	string getTailLength() {
		return "long";
	}
};

class Hamster : public Rodent {
	string getSpecies() {
		return "Hamster";
	}

	string getTailLength() {
		return "Stubby";
	}
};


int main(void) {
	// Make an array of Rodents.
	Rodent *rodents[10];
	for (int i = 0; i < 10; i++) {
		if (i % 3 == 1) {
			rodents[i] = new Mouse();
		} else if (i % 3 == 2) {
			rodents[i] = new Gerbil();
		} else {
			rodents[i] = new Hamster();
		}
	}

	//Describe each rodent in array of rodents.
	for (int i = 0; i < 10; i++) {
		cout << "===Rodent #" << i + 1 << " Characteristics===" << endl;
		cout << "Species: " << rodents[i]->getSpecies() << endl;
		cout << "Tail length: " << rodents[i]->getTailLength() << endl;
	}
	return 0;
}