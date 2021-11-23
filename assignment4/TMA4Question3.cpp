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

		//Create an instance of iterator pointing to last element in set. 
		iterator(Set& s, bool b) : s(s), index(s.eos) {}

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

	iterator begin() {
		return iterator(*this);
	}

	iterator end() {
		return iterator(*this, true);
	}

	iterator insert(T thing) {
		//Determine if duplicate value as required by the set interface.
		iterator start(this->begin());
		iterator end(this->end());
		if (start != end) {
			--end;
		}
		bool dupe = false;
		while (start != end) {
			if (*start == *end) {
				dupe = true;
				break;
			}
			start++;
		}
		// if (dupe == true) {
		// 	return start;
		// }
		storage_vector.push_back(thing);
		eos++;
	} 
};


int main(void) {
	Set<string> s1;

	s1.insert("Test");
	s1.insert("test2");
	s1.insert("test3");

	Set<string>::iterator start(s1.begin());
	Set<string>::iterator end(s1.end());

	while (start != end) {
		cout << *start << endl;
		start++;
	}

	return 0;
}