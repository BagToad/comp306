/* 
 Title: TMA2Question3.cpp
 Description:
    Open a text file and count whitespace separated words.
 Date: August 13, 2021
 Author: Kynan Ware
 Student ID: 3431123 
 Compile: g++ TMA2Question3.cpp -o TMA2Question3.exe
 Execution: ./TMA2Question3.exe
 
 Classes: none

 Variables:

*/

/*
 TEST PLAN
 
 All test plans, unless noted, require an input file. 


 Normal case 1:
 

 Normal case 2:
   

 Normal case 3:
  

 Bad Data case 1:
 

 Bad Data case 2 (illegal characters in filename input)


 Bad Data case 3 (empty file)
  
 
 Bad Data case 4 (file with newlines and special characters)
   

 
 Discussion:
 	

    The program returns an int as per the C++ standard.

    All testing performed in a Linux environment with g++ version 7.5.0.
*/

#include <iostream>

using namespace std;

class Hen {

public:
	Hen() {
		cout << "Created Hen!" << endl;
	}

	~Hen() {
		cout << "Destroyed Hen!" << endl;
	}

	void display() {
		cout << "This is a Hen!" << endl;
	}

	class Nest {

	public:
		Nest() {
			cout << "Created Nest!" << endl;
		}

		~Nest() {
			cout << "Destroyed Nest!" << endl;
		}

		void display() {
			cout << "This is a Nest!" << endl;
		}

		class Egg {

		public:
			Egg() {
				cout << "Created Egg!" << endl;
			}

			~Egg() {
				cout << "Destroyed Egg!" << endl;
			}

			void display() {
				cout << "This is an Egg!" << endl;
			}
		};
	};
};


int main(void) {
	cout << "=== Creating Objects ===" << endl;
	Hen* h = new Hen();
	Hen::Nest* n = new Hen::Nest();
	Hen::Nest::Egg* e = new Hen::Nest::Egg();

	cout << "=== Displaying Objects ===" << endl;
	h->display();
	n->display();
	e->display();

	cout << "=== Deleting Objects ===" << endl;
	delete h;
	delete n;
	delete e;

    return 0;
}

