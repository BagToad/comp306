/* 
 Title: TMA2Question3.cpp
 Description:
    Create three classes, a hen, nest and egg. Nest the classes within each other.
    Instantiate each class and print them by calling the display function.
 Date: October 4, 2021
 Author: Kynan Ware
 Student ID: 3431123 
 Compile: g++ TMA2Question3.cpp -o TMA2Question3.exe
 Execution: ./TMA2Question3.exe
 
 Classes:
 Hen - Contains the display member function to describe what this class is. Holds the Nest class. 
 Nest - Contains the display member function to describe what this class is. Holds the Egg class.
 Egg - Contains the display member function to describe what this class is. 

 Variables:
 h - Hen - an instance of Hen.
 n - Nest - an instance of Nest.
 e - Egg - an instance of Egg. 
*/

/*
 TEST PLAN
 
 Normal case:
	>=== Creating Objects ===
	>Created Hen!
	>Created Nest!
	>Created Egg!
	>=== Displaying Objects ===
	>This is a Hen!
	>This is a Nest!
	>This is an Egg!
	>=== Deleting Objects ===
	>Destroyed Hen!
	>Destroyed Nest!
	>Destroyed Egg!
   
 Discussion:
 	The program doesn't take any input, and so test plans are limited. The program should execute the same every time.
 	The program will instantiate a Hen, Nest, and Egg object, then call each class's display function.

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

