/* 
 Title: TMA4Question1.cpp
 Description:
 	Implement a class hierarchy of shapes using a abstract base shape class. 
  
 Date: Nov 20, 2021
 Author: Kynan Ware
 Student ID: 3431123
 Compile: g++ TMA4Question1.cpp -o TMA4Question1.exe
 Execution: ./TMA4Question1.exe
 
 Variables:


 Constants:


*/

/*
 TEST PLAN
(No input, static program)

====TEST POINT OPERATORS====
Setting values: p1 = Point(10, 20), p2 = Point(10, 20)
Expression: cout << p1 + p2 - p2
10, 20

====TEST CIRCLE SHAPE====
Name: Circle
Bounding box points (x, y): 
p1: -13, 18
p2: 33, 18
p3: -13, -28
p4: 33, -28
Shape area: 1661.9
Circumference: 144.513
Center point (x, y): 10, -5
Radius: 23

====TEST INVALID SQUARE SHAPE====
Name: Square
Bounding box points (x, y): 
p1: 5, -5
p2: -10, 7
p3: 4, 23
p4: -6, 12
Shape area: 361
Valid square?: false
Square vertice points (x, y): 
p1: 5, -5
p2: -10, 7
p3: 4, 23
p4: -6, 12

====TEST VALID SQUARE SHAPE====
Name: Square
Bounding box points (x, y): 
p1: -5, 5
p2: 5, 5
p3: 5, -5
p4: -5, -5
Shape area: 100
Valid square?: true
Square vertice points (x, y): 
p1: -5, 5
p2: 5, 5
p3: 5, -5
p4: -5, -5

====TEST VALID TRIANGLE SHAPE====
Name: Triangle
Bounding box points (x, y): 
p1: -15, 0
p2: 10, 0
p3: 10, 10
p4: -15, 15
Shape area: 146
Valid triangle?: true
Triangle vertice points (x, y): 
p1: 0, 0
p2: 10, 10
p3: -15, 15

====TEST TRIANGLE SHAPE VALIDATION LIMITS====
Name: Triangle
Bounding box points (x, y): 
p1: -15, -120
p2: 77, -120
p3: 77, 24
p4: -15, -100
Shape area: 24559
Valid triangle?: true
Triangle vertice points (x, y): 
p1: 56880, -120
p2: 77, 24
p3: -15, -100

 
 Discussion:
	The program implements a class hierarchy for shapes. The base class is Shape, which is
	inherited by the Square, Circle, and Triangle classes.

	I'm not sure if the Shape class counts as a pure abstract base class because
	I have found conflicting defintions about what a pure abstract class is. I believe that a 
	pure abstract class must have all virtual functions, which it does. In addition, to reinforce
	that this class is abstract, I have made the contructor protected. I did this so that the
	inherited shapes can benefit from code reuse for the Shape's name. The idea is that 
	each subclass must list the Shape's constructor in it's initilizer list to initilize the
	Shape's name. The Shape class could be considered less abstract when viewing the display
	and setBounds functions. I put these in the base class so the inherited classes can benefit
	from code reuse. For example, every inherited shape will always print its name, bounding
	box dimensions, and call the area function (area function is overloaded in subclass).

	I'm hoping that my justifcation here describes how the Shape class is abstract enough,
	but that the changes made towards a concrete class are done intentionally to reuse code.

	Like I've seen in some forum postings, I noticed that the square provided by
	the assignment is not a real square. I decided that the program would simply
	attempt to deal with it, regardless of valid dimensions. However, I attempted to 
	include logic for validating the square. I also added this information to the 
	square's display function. I know that this validation is flawed somewhere; all it
	validates is that the distance between each vertice are equal, and that this number
	is equal to the square root of the sum of all distnaces. I have a feeling that
	this validation logic doesn't work in some cases, but since it's not the focus 
	of the assignment, I didn't delve too deep into it. 

	I also added validation for the triangle, even though the triangle dimensions provided 
	are valid. The triangle validation logic is to check if the sum of two sides is ever
	less than the remaining side. If it is, the triangle is invalid. However, in my testing,
	I discovered that it is likely impossible to make this happen if creating a triangle based on
	points on a cartesia plane. Because the program determines the lengths of sides itself,
	the side lengths will always form a triangle as long as the program is correctly determining
	the distance between points. There is also the case of two or more points overlapping, but
	I did not account for that. They still report as valid if that is the case. 

	The bounding box logic also proved to be somewhat complicated. I attempted to look online
	for formulas, but I couldn't find anything straight forward. Instead, I tried to implement
	my own logic. This is also where the Shape class becomes less abstract because it implements
	a function to set a shape's bounding box. So, the responsibility of the subclass is to 
	determine its own bounding box and set the vertices accordingly by calling Shape::setBounds.

	Another implementation detail worth discussing is the use of arrays as function parameters.
	Very often, because C++ passes arrays as references, I contemplated having multiple
	paramters instead of passing an array of points. I contemplated this because I find working
	with pointers and references a bit complicated. However, I'm pleased that I worked through
	it because I think the code is much nicer now. It makes more sense to me to build an array
	of points, then send that as a parameter. However, I recognize that some people may prefer
	having individual parameters. After all, that might make the interfaces more readable. 
	At the end of the day, I think it boils down to style preference and maybe there are some
	concerns about efficiency that I am unaware of.  

	I also implemented an additional distance function in the Point class. This was to make
	all the validation calculations much easier because all validation logic requires
	determining the length of sides.

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
		if ((a + b) < c || (a + c) < b || (b + c) < a) {
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
	Point s1_points[4] = {
		Point(5, -5),
		Point(-10, 7),
		Point(4, 23),
		Point(-6, 12)
	};
	Square s1(s1_points);
	s1.display();


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
	Point t1_points[3] = {
		Point(0, 0),
		Point(10, 10),
		Point(-15, 15)
	};
	Triangle t1(t1_points);
	t1.display();

	cout << "\n====TEST TRIANGLE SHAPE VALIDATION LIMITS====" << endl;
	Point t2_points[3] = {
		Point(56880, -120),
		Point(77, 24),
		Point(-15, -100)
	};
	Triangle t2(t2_points);
	t2.display();
	return 0;
}