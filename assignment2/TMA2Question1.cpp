/* 
 Title: TMA2Question1.cpp
 Description:
    Open a text file and count whitespace separated words.
 Date: August 13, 2021
 Author: Kynan Ware
 Student ID: 3431123 
 Compile: g++ TMA2Question1.cpp -o TMA2Question1.exe
 Execution: ./TMA2Question1.exe
 
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
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class DVD {
	bool available;
	string last_rent_date;
	int year;
	string title;

public:
	DVD() {};

	DVD(string t, int y) {
		available = true;
		last_rent_date = "none";
		year = y;
		title = t;
	};

	/*
		Get the DVD availability.
		
		Returns:
		bool - false if DVD unavailable, true if DVD available.

		Arguments:
		none.
	*/
	bool get_available() {
		return available;
	};

	/*
		Set the DVD availability. Effectively checkout or return DVDs to the store.
		
		Returns:
		void

		Arguments:
		a - bool - true if DVD is returned, false if DVD is being checked out. 
	*/
	void set_available(bool a) {
		if (! a) {
			time_t now = time(0);
			last_rent_date = ctime(&now);
		}
		available = a;
	};

	/*
		Get the last time the DVD was rented out.

		Returns:
		string - A string with the last time the DVD was checked out. 
	*/
	string get_last_rent_date() {
		return last_rent_date;
	}

	/*
		Display the DVD's properties to the terminal.

		Returns:
		void.
	*/
	void print() {
		cout << "=== Printing DVD information ===" << endl;
		cout << "title: " << title << endl;
		cout << "year: " << year << endl;
		cout << "available: ";
		if (available) {
			cout << "Yes";
		} else {
			cout << "No";
		}
		cout << endl;
		cout << "last rent date: " << last_rent_date << endl;
	}

};



int main(void) {
	ifstream in;
    string filename;

	//Get the filename to open from the user.
	cout << "Filename to open: ";
	cin >> filename;
	in.open(filename);

    //Check if input file exists.
    if (! in) {
    	cout << "File does not exist!" << endl;
    	return 1;
    }


	DVD inventory[10];
	int count = 0;
	for (int i = 0; i < 9; i++) {
		string title;
		int year;
		cout << "LOADING DVD!" << endl;


		if (in.peek() == EOF) {break;}
		if (! getline(in, title)) {break;};
		if (in.peek() == EOF) {break;};
		in >> year;
		if (in.peek() == EOF) {break;};
		in.ignore();
		count++;

		inventory[i] = DVD(title, year);
	}

	for (int i = 0; i < count; i++) {
		inventory[i].print();
	}

    return 0;
}

