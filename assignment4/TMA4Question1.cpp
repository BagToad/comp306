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
#include <math.h>     //math provides math methods.

using namespace std;

class Point {
private:
	int x;
	int y; 
public: 
	//Instantiate a Point object.
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	Point() {
		this->x = 0;
		this->y = 0;
	}

	//Return x coordinate.
	int getX() {
		return this->x;
	}

	//Return y coordinate.
	int getY() {
		return this->y;
	}

	int distance(Point p) {
		Point diff = *this - p;
		return diff.getY() + diff.getX(); 
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

class Shape {
private:
	Point bounds [4] = { Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0) };
	string name; 
protected:

	const double PI = 3.141592;

	bool setBounds(Point points[4]) {
		// cout << sizeof(points) << " / " << sizeof(points[0]) << endl;
		// if ((sizeof(*points)/sizeof(points[0])) != 4) {
		// 	cout << "Invalid bounding box!" << endl;
		// 	return false;
		// }
		for (int i = 0; i <= 3; i++) {
			bounds[i] = points[i];
		}
	}
public:
	//Create an instance of Shape. 
	Shape(string name) {
		this->name = name;
	}

	//Get a Point array depicting the four corners of the bounding box. 
	Point* getBounds() {
		return bounds;
	}

	//Get the area of the shape.
	virtual double area() { return 0; }

	//Get the circumference of the shape.
	virtual double circumference() { return 0; }

	virtual void display() {
		cout << "Name: " << name << endl;
		cout << "Bounding box points (x, y): " << endl;
		for (int i = 0; i <= 3; i++) {
			cout << "p" << i + 1 << ": " << bounds[i] << endl;
		}
		cout << "Shape area: " << area() << endl;
	}
};

//Implement a Circle Shape.
class Circle : public Shape {
private: 
	Point center;
	double radius;
	bool valid = true;
public:
	//Create an instance of Circle.
	Circle(Point center, double radius) : Shape("Circle"), center(center), radius(radius) {
		//Identify the bounding box.
		Point points[4] = {
			Point(center.getX() - radius, center.getY() + radius),
			Point(center.getX() + radius, center.getY() + radius),
			Point(center.getX() - radius, center.getY() - radius),
			Point(center.getX() + radius, center.getY() - radius)
		};
		Shape::setBounds(points);


	}

	//Return the area of the Circle.
	double area() {
		return PI * pow(radius, 2);
	}

	//Return the circumference of the circle.
	double circumference() {
		return 2 * PI * radius;
	}
	void display() {
		Shape::display();
		cout << "Circumference: " << circumference() << endl;
		cout << "Center point (x, y): " << center << endl;
		cout << "Radius: " << radius << endl;
	}
};

//Implement a square shape.
class Square : public Shape {
private: 
	Point corners[4];
public:
	Square(Point corners[4]) : Shape("Square"), corners(){
		//Identify bounding box.
		Shape::setBounds(corners);
	}
};

int main(void) {

	cout << "====TEST POINT OPERATORS====" << endl;
	cout << "Setting values: " << "p1 = Point(10, 20), p2 = Point(10, 20)" << endl;
	Point p1 = Point(10, 20);
	Point p2 = Point(10, 20);
	cout << "Expression: " << "cout << p1 + p2 - p2" << endl;
	cout << p1 + p2 - p2 << endl;

	cout << "\n====TEST CIRCLE SHAPE====" << endl;
	Circle c(Point(10, 20), 5);
	c.circumference();
	c.display();

	cout << "\n====TEST SQUARE SHAPE====" << endl;
	Point s_points[4] = { Point(5, -5), Point(-10, 7), Point(4, 23), Point(-6, 12) };
	Square s(s_points);
	s.display();
	return 0;
}