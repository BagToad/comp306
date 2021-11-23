/* 
 Title: TMA4Question3.cpp
 Description:
  Implement and test a custom set template class, which includes iterators.
 Date: Nov 18, 2021
 Author: Kynan Ware
 Student ID: 3431123
 Compile: g++ TMA4Question3.cpp -o TMA4Question3.exe
 Execution: ./TMA4Question3.exe
 
 Variables:
 int - Set<T>.eos - An integer reprenting the "end of set". Used to create the end sentinel interator.
 vector - Set<T>.storage_vector - A vector used as the underlying implementation for Set.
 Set& - Set<T>::iterator.s - A reference to the set for which the iterator operates on.
 int - Set<T>::iterator.index - An integer representing the current index of the iterator. 

 Classes:
 Set<T> - A custom implementation of std::set.
 Set<T>::iterator - A custom implementation of std::set::iterator.

*/

/*
 TEST PLAN

 
This program compares custom implementations of insert(), erase(),
size(), and find() in Set to standard implementations in std::set.

The following tests are performed, by type, on both implementations:
	- Add three elements to set.
	- Insert the same element twice (sets should no contain duplicates).
	- Add, then subsequently delete an element.
	- Attempt to delete an element that does not exist.
	- Loop through the Set/set using iterators and print the values.
	- Print the output of size() (show set/Set size).

====START TEST STRING STORAGE IN CUSTOM SET====
duplicate
test1
test2
test3
Set size: 4
====END TEST STRING STORAGE IN CUSTOM SET====

====START TEST STRING STORAGE IN STD SET====
duplicate
test1
test2
test3
Set size: 4
====END TEST STRING STORAGE IN STD SET====

====START TEST INT STORAGE IN CUSTOM SET====
1
1000
2468
565656
Set size: 4
====END TEST INT STORAGE IN CUSTOM SET====

====START TEST INT STORAGE IN STD SET====
1
1000
2468
565656
Set size: 4
====END TEST INT STORAGE IN STD SET====

====START TEST DOUBLE STORAGE IN CUSTOM SET====
1.101
5.05
5565.22
65215.1
Set size: 4
====END TEST double STORAGE IN CUSTOM SET====

====START TEST double STORAGE IN STD SET====
1
1000
2468
565656
Set size: 4
====END TEST DOUBLE STORAGE IN STD SET====

 
 Discussion:
 	This program implements a custom set that mimics the behaviour of the std set. 
 	However, the standard set includes many class members and functions; not all of 
 	these members and functions were implemented in the custom set.

 	The custom set implementation includes: find(x), insert(x), erase(x), size()
 	begin(), and end().

 	The underlying implementation of Set is using a vector to store and retrieve
 	objects. Naturally, some functionality is different between a vector and a set.
 	For example, a set is sorted and a vector is not, therefore, the Set must sort 
 	the objects each time one is added during insert(x).

 	I tried to use native implementations as little as possible to demonstrate that the
 	custom Set class is capable of functioning properly. For example, the erase(x) function
 	calls Set::find(), which is a custom function. This returns a Set::Iterator, but a
 	vector::iterator is required to execute vector.erase(x). So, if the element is found
 	in the set using Set::find(), the erase() function iterates again - this time 
 	through the the vector using vector::iterator to find the vector::iterator
 	required for a call to vector::erase(). Again, this is mainly to prove that the find(x)
 	implementation and iterator implementation works properly to iterate through the set. If
 	there was a concern for efficiency I would remove the call to Set::find(x), and only have
 	iterate through the vector. I also considered whether there was a way to convert my
 	Set::iterator to a vector::iterator, but I did not find a way to do that. Perhaps that would
 	have been the optimal solution.
	
	The program returns an int as per the C++ standard.
	All testing performed in a Linux environment with g++ version 7.5.0.
*/

#include <iostream> //iostream provides io.
#include <vector>   //provides vector.
#include <set>      //provides set.
#include <algorithm>//provides sorting.

using namespace std;

/*
	Template class to implement a generic Set class.
	Behaves similarly to the standard C++ library set. 

	Template class & iterator implementation derived from:

	Eckel, Bruce. Thinking in C++: Introduction to Standard C++, 
	Volume 1. Available from: VitalSource Bookshelf,
	(2nd Edition). Pearson Learning Solutions, 2000.
*/
template <class T>
class Set {
private:	
	vector<T> storage_vector;
	int eos;
public:
	//Create an instance of Set.
	Set() : eos(0) {}

	//Declare iterator as friend class.
	friend class iterator;

	//Implement an iterator.
	class iterator {
	private:
		Set& s; 
		int index;
	public:
		//Create an instance of iterator pointing to first element in Set.
		iterator(Set& s) : s(s), index(0) {}

		//Create an instance of iterator pointing to last element in Set. 
		iterator(Set& s, bool b) : s(s), index(s.eos) {}

		//Return the object stored in vector storage. Act like 
		//dereferencing a pointer. 
		T operator*() {
			return s.storage_vector[index];
		}

		//Prefix ++ operator for incrementing interator. 
		T operator++() {
			return s.storage_vector[++index];
		}

		//Postfix ++ operator for incrementing iterator.
		T operator++(int) {
			return s.storage_vector[index++];
		}

		//Prefix -- operator for decrementing iterator. 
		T operator--() {
			return s.storage_vector[--index];
		}

		//Postfix -- operator for decrementing iterator. 
		T operator--(int) {
			return s.storage_vector[index--];
		}

		//Comparison != operator for comparing two iterators.
		bool operator!=(iterator& iter) {
			return iter.index != index; 
		}

		//Comparison == operator for comparing two iterators.
		bool operator==(iterator& iter) {
			return iter.index == index;
		}
	};

	//Return an iterator pointing to the first object in Set.
	iterator begin() {
		return iterator(*this);
	}

	//Return an iterator pointing to the last object in Set.
	iterator end() {
		return iterator(*this, true);
	}

	//Return the number of objects in the set.
	int size() {
		return eos;
	}

	//Insert element into storage if element doesn't already exist.
	iterator insert(T thing) {
		//Determine if duplicate value as required by the set interface.
		iterator e(this->end());
		iterator found(this->find(thing));
		if (found != e) {
			return found;
		}
		//If not duplicate, then push to storage.
		storage_vector.push_back(thing);
		eos++;

		//Sort the storage because a set is sorted. 
		sort(storage_vector.begin(), storage_vector.end());
	}

	//Find element, then erase it from storage.
	void erase(T thing) {
		//Determine if value is in set.
		//(This is redundant, could just use std vector iterator. This
		// demonstrates that the custom build iterator works as well).
		iterator e(this->end());
		iterator found(this->find(thing));
		if (found == e) {
			return;
		}

		//Remove from vector.
		typename vector<T>::iterator v_start(storage_vector.begin());
		typename vector<T>::iterator v_end(storage_vector.end());
		while (v_start != v_end) {
			if (*v_start == thing) {
				break;
			}
			v_start++;
		}
		storage_vector.erase(v_start);
		eos--;

	}

	//Find element in storage. 
	//Return iterator pointing to element in storage.
	iterator find(T thing) {
		if (eos == 0) {
			return this->end();
		}
		iterator start(this->begin());
		iterator end(this->end());
		bool dupe = false;
		while (start != end) {
			if (thing == *start) {
				dupe = true;
				break;
			}
			start++;
		}
		if (dupe == true) {
			return start;
		}
		return end;
	}
};


int main(void) {

	//Describe program and the tests performed.
	cout << "\nThis program compares custom implementations of insert(), erase(),\n";
	cout << "size(), and find() in Set to standard implementations in std::set.\n" << endl;

	cout << "The following tests are performed, by type, on both implementations:\n";
	cout << "	- Add three elements to set.\n";
	cout << "	- Insert the same element twice (sets should no contain duplicates).\n";
	cout << "	- Add, then subsequently delete an element.\n";
	cout << "	- Attempt to delete an element that does not exist.\n";
	cout << "	- Loop through the Set/set using iterators and print the values.\n";
	cout << "	- Print the output of size() (show set/Set size).\n" << endl;

	cout << "====START TEST STRING STORAGE IN CUSTOM SET====" << endl;
	Set<string> custom_string_set;

	//Test inserting multiple strings.
	custom_string_set.insert("test1");
	custom_string_set.insert("test2");
	custom_string_set.insert("test3");

	//Duplicate should only be added once. 
	custom_string_set.insert("duplicate");
	custom_string_set.insert("duplicate"); 

	//Test deleting.
	custom_string_set.insert("Delete this!");
	custom_string_set.erase("Delete this!");

	//Test deleting something that doesn't exist.
	custom_string_set.erase("Does not exist!");

	//Print results using iterator.
	Set<string>::iterator custom_string_start(custom_string_set.begin());
	Set<string>::iterator custom_string_end(custom_string_set.end());

	while (custom_string_start != custom_string_end) {
		cout << *custom_string_start << endl;
		custom_string_start++;
	}

	//Print set size. 
	cout << "Set size: " << custom_string_set.size() << endl;

	cout << "====END TEST STRING STORAGE IN CUSTOM SET====\n" << endl;

	cout << "====START TEST STRING STORAGE IN STD SET====" << endl;
	set<string> standard_string_set;

	//Test inserting multiple strings.
	standard_string_set.insert("test1");
	standard_string_set.insert("test2");
	standard_string_set.insert("test3");

	//Duplicate should only be added once. 
	standard_string_set.insert("duplicate");
	standard_string_set.insert("duplicate"); 

	//Test deleting.
	standard_string_set.insert("Delete this!");
	standard_string_set.erase("Delete this!");

	//Test deleting something that doesn't exist.
	standard_string_set.erase("Does not exist!");


	//Print results using iterator.
	set<string>::iterator standard_string_start(standard_string_set.begin());
	set<string>::iterator standard_string_end(standard_string_set.end());

	while (standard_string_start != standard_string_end) {
		cout << *standard_string_start << endl;
		standard_string_start++;
	}

	//Print size
	cout << "Set size: " << standard_string_set.size() << endl;

	cout << "====END TEST STRING STORAGE IN STD SET====\n" << endl;

	cout << "====START TEST INT STORAGE IN CUSTOM SET====" << endl;
	Set<int> custom_int_set;

	//Test inserting multiple ints.
	custom_int_set.insert(1);
	custom_int_set.insert(1000);
	custom_int_set.insert(565656);

	//Duplicate should only be added once. 
	custom_int_set.insert(2468);
	custom_int_set.insert(2468); 

	//Test deleting.
	custom_int_set.insert(5544);
	custom_int_set.erase(5544);

	//Test deleting something that doesn't exist.
	custom_int_set.erase(7777777);

	//Print results using iterator.
	Set<int>::iterator custom_int_start(custom_int_set.begin());
	Set<int>::iterator custom_int_end(custom_int_set.end());

	while (custom_int_start != custom_int_end) {
		cout << *custom_int_start << endl;
		custom_int_start++;
	}

	//Print set size. 
	cout << "Set size: " << custom_int_set.size() << endl;

	cout << "====END TEST INT STORAGE IN CUSTOM SET====\n" << endl;

	cout << "====START TEST INT STORAGE IN STD SET====" << endl;
	set<int> standard_int_set;

	//Test inserting multiple ints.
	standard_int_set.insert(1);
	standard_int_set.insert(1000);
	standard_int_set.insert(565656);

	//Duplicate should only be added once. 
	standard_int_set.insert(2468);
	standard_int_set.insert(2468); 

	//Test deleting.
	standard_int_set.insert(5544);
	standard_int_set.erase(5544);

	//Test deleting something that doesn't exist.
	standard_int_set.erase(7777777);

	//Print results using iterator.
	set<int>::iterator standard_int_start(standard_int_set.begin());
	set<int>::iterator standard_int_end(standard_int_set.end());

	while (standard_int_start != standard_int_end) {
		cout << *standard_int_start << endl;
		standard_int_start++;
	}

	//Print set size. 
	cout << "Set size: " << standard_int_set.size() << endl;

	cout << "====END TEST INT STORAGE IN STD SET====\n" << endl;

	cout << "====START TEST DOUBLE STORAGE IN CUSTOM SET====" << endl;
	Set<double> custom_double_set;

	//Test inserting multiple doubles.
	custom_double_set.insert(1.101);
	custom_double_set.insert(5.05);
	custom_double_set.insert(65215.05132);

	//Duplicate should only be added once. 
	custom_double_set.insert(5565.22);
	custom_double_set.insert(5565.22); 

	//Test deleting.
	custom_double_set.insert(22.75);
	custom_double_set.erase(22.75);

	//Test deleting something that doesn't exist.
	custom_double_set.erase(88888.888);

	//Print results using iterator.
	Set<double>::iterator custom_double_start(custom_double_set.begin());
	Set<double>::iterator custom_double_end(custom_double_set.end());

	while (custom_double_start != custom_double_end) {
		cout << *custom_double_start << endl;
		custom_double_start++;
	}

	//Print set size. 
	cout << "Set size: " << custom_double_set.size() << endl;

	cout << "====END TEST double STORAGE IN CUSTOM SET====\n" << endl;

	cout << "====START TEST double STORAGE IN STD SET====" << endl;
	set<double> standard_double_set;

	//Test inserting multiple doubles.
	standard_double_set.insert(1);
	standard_double_set.insert(1000);
	standard_double_set.insert(565656);

	//Duplicate should only be added once. 
	standard_double_set.insert(2468);
	standard_double_set.insert(2468); 

	//Test deleting.
	standard_double_set.insert(5544);
	standard_double_set.erase(5544);

	//Test deleting something that doesn't exist.
	standard_double_set.erase(7777777);

	//Print results using iterator.
	set<double>::iterator standard_double_start(standard_double_set.begin());
	set<double>::iterator standard_double_end(standard_double_set.end());

	while (standard_double_start != standard_double_end) {
		cout << *standard_double_start << endl;
		standard_double_start++;
	}

	//Print set size. 
	cout << "Set size: " << standard_double_set.size() << endl;

	cout << "====END TEST DOUBLE STORAGE IN STD SET====\n" << endl;


	return 0;
}