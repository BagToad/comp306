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
#include <math.h>   //math provides math methods.

using namespace std;

//Implement a point on a catersian plane. 
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

	//Instantiate a Point object with no coordinates.
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

	//Return distance between two points.
	int distance(Point p) {
		//Use Pythagorean theorem to calculate distance between points. 
		int a = x - p.getX();
		int b = y - p.getY();
		int c = sqrt(pow(a, 2) + pow(b, 2));
		return c;
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

//Implement a pure abstract shape class. 
class Shape {
private:
	Point bounds [4];
	string name; 
protected:
	const double PI = 3.141592;

	//Set the shape's bounding box.
	bool setBounds(Point points[4]) {
		for (int i = 0; i <= 3; i++) {
			bounds[i] = points[i];
		}
	}

	//Create an instance of Shape. 
	Shape(string name) {
		this->name = name;
	}

public:
	//Get a Point array depicting the four corners of the bounding box. 
	Point* getBounds() {
		return bounds;
	}

	//Get the area of the shape.
	virtual double area() { return 0; }

	//Get the circumference of the shape.
	virtual double circumference() { return 0; }

	//Display the shape's characteristics. 
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
	bool valid = true;
public:
	//Create an instance of square. 
	Square(Point corners[4]) : Shape("Square"), corners() {
		//Identify bounding box - can be same as square dimensions.
		Shape::setBounds(corners);

		//Initialize corners.
		for (int i = 0; i <= 3; i++) {
			this->corners[i] = corners[i];
		}

		//Determine the validity of the square.
		//All sides should equal the square root of the sum of all sides.
		int sqrt_area = sqrt(area());
		if (sqrt_area != corners[0].distance(corners[1]) ||
			sqrt_area != corners[1].distance(corners[2]) ||
			sqrt_area != corners[2].distance(corners[3]) ||
			sqrt_area != corners[3].distance(corners[0])){
			valid = false;
		} 
	}

	//Return the square's area. 
	double area() {
		return pow(corners[0].distance(corners[1]), 2);
	}

	//Print the square's characteristics. 
	void display() {
		Shape::display();
		cout << "Valid square?: ";
		if (valid == true) {
			cout << "true";
		} else {
			cout << "false";
		}
		cout << endl;
		cout << "Square vertice points (x, y): " << endl;
		for (int i = 0; i <= 3; i++) {
			cout << "p" << i + 1 << ": " << corners[i] << endl;
		}
	}
};

//Implement a triangle shape.
class Triangle : Shape {
private:
	Point corners[3];
	bool valid = true;
public:
	//Create an instance of Triangle.
	Triangle(Point corners[3]) : Shape("Triangle"), corners() {
		//Identify bounding box.
		Point points[4] = {
			Point(corners[2].getX(), corners[0].getY()),
			Point(corners[1].getX(), corners[0].getY()),
			Point(corners[1]),
			Point(corners[2])
		};
		Shape::setBounds(points);

		//Initialize corners.
		for (int i = 0; i <= 2; i++) {
			this->corners[i] = corners[i];
		}

		//Determine the validity of the triangle.
		//The sum of any two sides must be greater than the remaining side. 
		int a = corners[0].distance(corners[2]);
		int b = corners[0].distance(corners[1]);
		int c = corners[2].distance(corners[1]);
		if (a + b < c || a + c < b || b + c < a) {
			valid = false;
		}

	}

	//Return the triangle's area. 
	double area() {
		//Use Heron's Formula to determine triangle area from 3 side lengths.
		int a = corners[0].distance(corners[2]);
		int b = corners[0].distance(corners[1]);
		int c = corners[1].distance(corners[2]);
		int s = (a + b + c) / 2;
		int area = sqrt(s * (s - a) * (s - b) * (s - c));
		return area;
	}

	//Display the triangle's characteristics.
	void display() {
		Shape::display();
		cout << "Valid triangle?: ";
		if (valid == true) {
			cout << "true";
		} else {
			cout << "false";
		}
		cout << endl;
		cout << "Triangle vertice points (x, y): " << endl;
		for (int i = 0; i <= 2; i++) {
			cout << "p" << i + 1 << ": " << corners[i] << endl;
		}
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
	Circle c(Point(10, -5), 23);
	c.circumference();
	c.display();

	cout << "\n====TEST INVALID SQUARE SHAPE====" << endl;
	Point s_points[4] = {
		Point(5, -5),
		Point(-10, 7),
		Point(4, 23),
		Point(-6, 12)
	};
	Square s(s_points);
	s.display();


	cout << "\n====TEST VALID SQUARE SHAPE====" << endl;
	Point s2_points[4] = {
		Point(-5, 5),
		Point(5, 5),
		Point(5, -5),
		Point(-5, -5)
	};
	Square s2(s2_points);
	s2.display();

	cout << "\n====TEST VALID TRIANGLE SHAPE====" << endl;
	Point t_points[3] = {
		Point(0, 0),
		Point(10, 10),
		Point(-15, 15)
	};
	Triangle t(t_points);
	t.display();
	return 0;
}