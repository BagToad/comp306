/* 
 Title: TMA2Question1.cpp
 Description:
    Track DVD information. Import DVD data from a text file.
 Date: October 4, 2021
 Author: Kynan Ware
 Student ID: 3431123 
 Compile: g++ TMA2Question1.cpp -o TMA2Question1.exe
 Execution: ./TMA2Question1.exe
 
 Classes:
 DVD - A representation of a DVD in a video rental store. 

 Variables:
 in - fstream - a stream to read the text file. 
 filename - string - a string to hold the text file's filename. 
 inventory - DVD - an array of DVDs.
 count - int - the DVDs read from the input text file.

 Constants:
 NUM_DVD - int - The number of DVDs to read from input text file.



*/

/*
 TEST PLAN
 
 All test plans, unless noted, require an input file. 


 Normal case 1 (< 10 DVDS):
 	Input file (input1.txt) contents:
 	The Dark Night
2008
12 Angry Men
1957
Schindler's List
1993
The Lord of the Rings: The Return of the King
2003
Pulp Fiction
1994
The Good, the Bad, and the Ugly
1966
The Lord of the Rings: The Fellowship of the Ring
2001

	>Filename to open: input1.txt
	>=== Printing DVD information ===
title: The Dark Night
year: 2008
available: Yes
last rent date: none

=== Printing DVD information ===
title: 12 Angry Men
year: 1957
available: Yes
last rent date: none

=== Printing DVD information ===
title: Schindler's List
year: 1993
available: Yes
last rent date: none

=== Printing DVD information ===
title: The Lord of the Rings: The Return of the King
year: 2003
available: Yes
last rent date: none

=== Printing DVD information ===
title: Pulp Fiction
year: 1994
available: Yes
last rent date: none

=== Printing DVD information ===
title: The Good, the Bad, and the Ugly
year: 1966
available: Yes
last rent date: none



 Normal case 2 (exactly 10 DVDs):
	Input file (input2.txt) contents:
		The Shawshank Redemption
		1994
		The Godfather
		1972
		The Godfather: Part II
		1974
		The Dark Night
		2008
		12 Angry Men
		1957
		Schindler's List
		1993
		The Lord of the Rings: The Return of the King
		2003
		Pulp Fiction
		1994
		The Good, the Bad, and the Ugly
		1966
		The Lord of the Rings: The Fellowship of the Ring
		2001

	>Filename to open: input2.txt
	>=== Printing DVD information ===
	title: The Shawshank Redemption
	year: 1994
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: The Godfather
	year: 1972
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: The Godfather: Part II
	year: 1974
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: The Dark Night
	year: 2008
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: 12 Angry Men
	year: 1957
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: Schindler's List
	year: 1993
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: The Lord of the Rings: The Return of the King
	year: 2003
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: Pulp Fiction
	year: 1994
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: The Good, the Bad, and the Ugly
	year: 1966
	available: Yes
	last rent date: none

	>


 Normal case 3 (> 10 DVDs):
	Input file (input4.txt) contents:
		The Shawshank Redemption
		1994
		The Godfather
		1972
		The Godfather: Part II
		1974
		The Dark Night
		2008
		12 Angry Men
		1957
		Schindler's List
		1993
		The Lord of the Rings: The Return of the King
		2003
		Pulp Fiction
		1994
		The Good, the Bad, and the Ugly
		1966
		The Lord of the Rings: The Fellowship of the Ring
		2001
		Fight Club
		1999
		Forrest Gump
		1994
	
	>Filename to open: input4.txt
	=== Printing DVD information ===
	title: The Shawshank Redemption
	year: 1994
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: The Godfather
	year: 1972
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: The Godfather: Part II
	year: 1974
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: The Dark Night
	year: 2008
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: 12 Angry Men
	year: 1957
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: Schindler's List
	year: 1993
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: The Lord of the Rings: The Return of the King
	year: 2003
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: Pulp Fiction
	year: 1994
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: The Good, the Bad, and the Ugly
	year: 1966
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: The Lord of the Rings: The Fellowship of the Ring
	year: 2001
	available: Yes
	last rent date: none



 Bad Data case 1 (only newlines in input file):
	Input file (input3.txt) contents:

		
		
		
		
		
		
		
		
		
		
		
		

	>Filename to open: input3.txt
	>No lines with information to read.


 Bad Data case 2 (Non-integer data in some years in input file)
	Input file (input5.txt) contents:
		The Shawshank Redemption
		1994
		The Godfather
		1972
		The Godfather: Part II
		1974
		The Dark Night
		2008
		12 Angry Men
		!@#%!%!@#!#@
		Schindler's List
		1993
		The Lord of the Rings: The Return of the King
		2003
		Pulp Fiction
		1994
		The Good, the Bad, and the Ugly
		1966
		The Lord of the Rings: The Fellowship of the Ring
		ALPHA INVALID DATA
		
	>Filename to open: input5.txt
	=== Printing DVD information ===
	title: The Shawshank Redemption
	year: 1994
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: The Godfather
	year: 1972
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: The Godfather: Part II
	year: 1974
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: The Dark Night
	year: 2008
	available: Yes
	last rent date: none




 Bad Data case 3 (A couple newlines in between valid entries)
 	Input file (input6.txt) contents:
		The Shawshank Redemption
		1994
		The Godfather
		1972
		The Godfather: Part II

		1974
		The Dark Night
		2008

		12 Angry Men
		1957
		Schindler's List
		1993
		The Lord of the Rings: The Return of the King
		2003
		Pulp Fiction
		1994
		The Good, the Bad, and the Ugly
		1966
		The Lord of the Rings: The Fellowship of the Ring
		2001

 	>Filename to open: input6.txt
	=== Printing DVD information ===
	title: The Shawshank Redemption
	year: 1994
	available: Yes
	last rent date: none

	=== Printing DVD information ===
	title: The Godfather
	year: 1972
	available: Yes
	last rent date: none


 Discussion:
 	The program opens a text input file and reads it into up to 10 DVD object instances. If more than 10 DVDs are
 	provided in the input file, they are ignored. If zero DVDs are found in the input file, then a message is printed.  

 	The input file format is: the title on one line immediately followed by the year on a separate line. 

 	The title can be any combination of characters, but the year must be an integer. If the year is not an integer,
 	the offending DVD and all subsequent DVDs are not imported.
	
    The program returns an int as per the C++ standard.

    All testing performed in a Linux environment with g++ version 7.5.0.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;


/*
	A DVD object to track DVD information and availability.
*/
class DVD {
private:
	bool available;
	string last_rent_date;
	int year;
	string title;

public:
	DVD() {
		available = true;
		last_rent_date = "none";
		year = -1;
		title = "unavailable";

	};

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
		cout << endl;
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

    const int NUM_DVD = 10;
	DVD inventory[NUM_DVD];
	int count = 0;

	//Read up to 10 DVDs from input file.
	for (int i = 0; i < NUM_DVD; i++) {
		string title;
		int year;

		//Stop reading on blank lines or EOF. 
		if (in.peek() == '\n' || in.peek() == EOF) {break;};
		
		//Get title from first line.
		if (! getline(in, title)) {break;};
		
		//Stop reading at EOF or blank lines
		if (in.peek() == '\n' || in.peek() == EOF) {break;};

		//Get year from next line.
		in >> year;

		//Stop reading if next character is not newline. This means that reading the year failed.
		if (in.peek() != '\n') {break;};
		in.ignore();

		//Commit data to inventory.
		count++;
		inventory[i] = DVD(title, year);
	}

	//Did not read any valid line pairs from input file.
	if (count <= 0) {
		cout << "No lines with information to read." << endl;
	}

	//Print inventory out. 
	for (int i = 0; i < count; i++) {
		inventory[i].print();
	}

    return 0;
}

