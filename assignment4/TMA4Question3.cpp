/* 
 Title: TMA4Question3.cpp
 Description:
  
 Date: Nov 18, 2021
 Author: Kynan Ware
 Student ID: 3431123
 Compile: g++ TMA4Question3.cpp -o TMA4Question3.exe
 Execution: ./TMA4Question3.exe
 
 Variables:


 Constants:


*/

/*
 TEST PLAN
 
 Discussion:
	The program loads two double arrays with 10,000 values. The values 
	are multiplied by eachother, then printed. The execution time of 
	the program is printed, then the program exits.
	
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

	cout << "====TEST STRING STORAGE IN CUSTOM SET====" << endl;
	Set<string> s1;

	//Test inserting multiple strings.
	s1.insert("test1");
	s1.insert("test2");
	s1.insert("test3");

	//Duplicate should only be added once. 
	s1.insert("duplicate");
	s1.insert("duplicate"); 

	Set<string>::iterator found(s1.find("duplicate"));

	cout << "Dupe: " << *found << endl;

	Set<string>::iterator start(s1.begin());
	Set<string>::iterator end(s1.end());

	while (start != end) {
		cout << *start << endl;
		start++;
	}


	cout << "====TEST STRING STORAGE IN STD SET====" << endl;
	set<string> s2;

	//Test inserting multiple strings.
	s2.insert("test1");
	s2.insert("test2");
	s2.insert("test3");

	//Duplicate should only be added once. 
	s2.insert("duplicate");
	s2.insert("duplicate"); 

	// set<string>::iterator found2(s2.find("duplicate"));

	// cout << "Dupe: " << *found2 << endl;

	set<string>::iterator start2(s2.begin());
	set<string>::iterator end2(s2.end());

	while (start2 != end2) {
		cout << *start2 << endl;
		start2++;
	}

	return 0;
}