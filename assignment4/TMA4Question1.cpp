/* 
 Title: TMA4Question1.cpp
 Description:
  
 Date: Nov 18, 2021
 Author: Kynan Ware
 Student ID: 3431123
 Compile: g++ TMA4Question1.cpp -o TMA4Question1.exe
 Execution: ./TMA4Question1.exe
 
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
#include <string>   //string provides string methods.
using namespace std;

class Point {
private:
	int x;
	int y; 
public: 
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	//Print the point values of a point in x, y form.
	friend ostream& operator<<(ostream& os, const Point& p) {
		return os << to_string(p.x) << ", " << to_string(p.y);
	}

	//Add two Points, return a new temporary Point.
	const Point operator+(const Point& p) const {
		return Point(x + p.x, y + p.y);
	}

	//Subtract two Points, return a new temporary Point. 
	const Point operator-(const Point& p) const {
		return Point(x - p.x, y - p.y);
	}
};



int main(void) {
	Point p1 = Point(10, 20);
	Point p2 = Point(10, 20);
	cout << p1 + p2 - p2 << endl;
	return 0;
}