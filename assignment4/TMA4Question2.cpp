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
// private:
// 	//Create an intance of Rodent (abstract, does nothing)
// 	Rodent();
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
	//Make an array of Rodents.
	// Rodent rodents[10];
	// for (int i = 0; i < 10; i++) {
	// 	if (i % 3 == 1) {
	// 		cout << "made mouse" << endl;
	// 		rodents[i] = Mouse();
	// 	} else if (i % 3 == 2) {
	// 		rodents[i] = Gerbil();
	// 		cout << "made Gerbil" << endl;
	// 	} else {
	// 		rodents[i] = Hamster();
	// 		cout << "made ham" << endl;
	// 	}
	// }
	// cout << rodents[0].getSpecies() << endl;


	Rodent r = Mouse();
	cout << r.getSpecies() << endl;

	//Describe each rodent in array of rodents.
	// for (int i = 0; i < 10; i++) {
	// 	cout << "===Rodent #" << i + 1 << " Characteristics===" << endl;
	// 	cout << "Species: " << rodents[i]->getSpecies() << endl;
	// 	cout << "Tail length: " << rodents[i]->getTailLength() << endl;
	// }
	return 0;
}