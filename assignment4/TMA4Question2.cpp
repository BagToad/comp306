/* 
 Title: TMA4Question2.cpp
 Description:
  
 Date: Nov 18, 2021
 Author: Kynan Ware
 Student ID: 3431123
 Compile: g++ TMA4Question2.cpp -o TMA4Question2.exe
 Execution: ./TMA4Question2.exe
 
 Variables:


 Constants:


*/

/*
 TEST PLAN
 
 Discussion:
	
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