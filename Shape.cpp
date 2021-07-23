Shape.txt
0 3 4 5
1 2 3
2 5
3 2
4 1 3
Shape.h
#pragma once
#include<iostream>
#include<fstream>
#include<string>
constexpr double pi = 3.1415927;
using namespace std;
class Shape {
public:
	static Shape* findAndClone(int);
	virtual double Area(void) const = 0;
	virtual double Perimeter(void) const = 0;
	virtual istream& read(istream&) = 0;
	virtual ostream& write(ostream&) const = 0;
};



class Rectangle : public Shape {
	double a;
	double b;
public:
	virtual double Area(void) const;
	virtual double Perimeter(void) const;
	virtual istream& read(istream&);
	virtual ostream& write(ostream&) const;
};


class Square : public Rectangle {
	double c;
public:
	virtual double Area(void) const;
	virtual double Perimeter(void) const;
	virtual istream& read(istream&);
	virtual ostream& write(ostream&) const;
};


class Ellipse : public Shape {
	double d;
	double e;
public:
	virtual double Area(void) const;
	virtual double Perimeter(void) const;
	virtual istream& read(istream&);
	virtual ostream& write(ostream&) const;
};


class Circle : public Ellipse {
	double r;
public:
	virtual double Area(void) const;
	virtual double Perimeter(void) const;
	virtual istream& read(istream&);
	virtual ostream& write(ostream&) const;
};


class Triangle : public Shape {
	double x;
	double y;
	double z;
public:
	virtual double Area(void) const;
	virtual double Perimeter(void) const;
	virtual istream& read(istream&);
	virtual ostream& write(ostream&) const;
};

Shape.cpp
#include "Shape.h"
#include<iomanip>

Shape* Shape::findAndClone(int num)
{
	if (num == 0)
	{
		return new Triangle;
	}
	else if (num == 1)
	{
		return new Rectangle;
	}
	else  if (num == 2)
	{
		return new Square;
	}
	else if (num == 3)
	{
		return new Circle;
	}
	else if (num == 4)
	{
		return new Ellipse;
	}
	else
	{
		cout << "Your instruction is wrong." << endl;
		return nullptr;
	}
}



double Rectangle::Area(void) const {
	return (a*b);
}

double Rectangle::Perimeter(void) const {
	return (2.0*a + 2.0*b);
}

istream & Rectangle::read(istream &is) {
	is >> a >> b;
	return is;
}

ostream & Rectangle::write(ostream &os) const {
	ofstream out("CoutRstult.dat", ios::out | ios::app);
	out << "Rectangle:" << a << ',' << b << ',' << Area() << ',' << Perimeter() << endl;
	os << "Rectangle:" << a << setw(2) << b;
	return os;
}
double Square::Area(void) const {
	return (c*c);
}

double Square::Perimeter(void) const {
	return (c*4.0);
}

istream & Square::read(istream &is) {
	is >> c;
	return is;
}

ostream & Square::write(ostream &os) const {
	ofstream out("CoutRstult.dat", ios::out | ios::app);
	out << "Square:" << c << ',' << Area() << ',' << Perimeter() << endl;
	os << "Square:" << c;
	return os;
}



double Ellipse::Area(void) const
{
	return (pi*d*e);
}

double Ellipse::Perimeter(void) const {
	return (2.0*d*e + 4 * abs(d - e));
}

istream & Ellipse::read(istream &is) {
	is >> d >> e;
	return is;
}

ostream & Ellipse::write(ostream &os) const {
	ofstream out("CoutRstult.dat", ios::out | ios::app);
	out << "Ellipse:" << d << ',' << e << ',' << Area() << ',' << Perimeter() << endl;
	os << "Ellipse:" << d << ' ' << e;
	return os;
}
double Circle::Area(void) const {
	return (pi*r*r);
}

double Circle::Perimeter(void) const {
	return (2.0*pi*r);
}

istream & Circle::read(istream &is) {
	is >> r;
	return is;
}

ostream & Circle::write(ostream &os) const {
	ofstream out("CoutRstult.dat", ios::out | ios::app);
	out << "Circle:" << r << ',' << Area() << ',' << Perimeter() << endl;
	os << "Circle:" << r;
	return os;
}

double Triangle::Perimeter(void) const
{
	return (x + y + z);
}

double Triangle::Area(void) const {
	double p = Perimeter() / 2;
	return sqrt(p*(p - x)*(p - y)*(p - z));
}

istream & Triangle::read(istream &is)
{
	is >> x >> y >> z;
	return is;
}
ostream & Triangle::write(ostream &os) const
{
	ofstream out("CoutRstult.dat", ios::out | ios::app);
	out << "Triangle:" << x << ',' << y << ',' << z << ',' << Area() << ',' << Perimeter() << endl;
	os << "Triangle:" << x << ' ' << y << ' ' << z;
	return os;
}

main.cpp
#include<fstream>
#include "Shape.h"
#include <list>
#include<iostream>
using namespace std;



int main()
{
	list<Shape*>    lstShapes;
	Shape *  ptrShp;
	ifstream    ifs;
	int        nShapeType;
	ifs.open("Shape.txt");

	while (!ifs.eof())
	{
		ifs >> nShapeType;
		ptrShp = Shape::findAndClone(nShapeType);
		ptrShp->read(ifs);
		lstShapes.push_back(ptrShp);
	}

	for (auto shp : lstShapes)
	{
		shp->write(cout) << ", ";
		cout << shp->Area() << ", ";
		cout << shp->Perimeter() << ", ";
		cout << endl;
	}

	for (auto shp : lstShapes)
	{
		delete shp;
	}
	return 0;
}


