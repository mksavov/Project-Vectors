#include <iostream>
#include "Vectors.h"
#include <cmath>
#include <exception>

using namespace std;

Point::Point() {
	x, y, z = 0;
}

void Point::setX(double x) {
	this->x = x;
}

void Point::setY(double y) {
	this->y = y;
}

void Point::setZ(double z) {
	this->z = z;
}

double Point::getX() {
	return x;
}
double Point::getY() {
	return y;
}
double Point::getZ() {
	return z;
}

ostream & operator << (ostream &out, Point &p1) {
	out << "x = " << p1.getX() << endl << "y = " << p1.getY() << endl << "z =" << p1.getZ() << endl;
	return out;
}
istream & operator >> (istream &in, Point &p1) {
	double x1, y1, z1;
	cout << "Enter x: ";
	in >> x1;
	cout << "Enter y: ";
	in >> y1;
	cout << "Enter z: ";
	in >> z1;
	p1.setX(x1);
	p1.setY(y1);
	p1.setZ(z1);
	return in;
}

bool operator == (Point &p1, Point &p2) {
	if (p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() == p2.getZ()) {
		return true;
	}
	else {
		return false;
	}
}

Vector::Vector() {
	x = 0;
	y = 0;
	z = 0;
}
Vector::Vector(Point p1, Point p2) {
	x=(p2.getX() - p1.getX());
	y=(p2.getY() - p1.getY());
	z=(p2.getZ() - p1.getZ());
}

Vector::Vector(double x1, double y1, double z1) {
	x = x1;
	y = y1;
	z = z1;
}
double Vector::VectorLength(Vector v1) {
	double len;
	int temp;
	temp = pow(v1.getX(), 2) + pow(v1.getY(), 2) + pow(v1.getZ(), 2);
	len = sqrt(temp);
	return len;
}

Vector Vector::VectorDir(Vector v1) {
	double x1, y1, z1;
	double len;
	double temp;
	temp = pow(v1.getX(), 2) + pow(v1.getY(), 2) + pow(v1.getZ(), 2);
	len = sqrt(temp);
	
	x1 = v1.getX() / len;
	y1 = v1.getY() / len;
	z1 = v1.getZ() / len;
	Vector v2(x1,y1,z1);
	return v2;
}

bool Vector::nullvector(Vector v1) {
	if (v1.getX() == 0 && v1.getY() == 0 && v1.getZ() == 0) {
		return true;
	}
	else {
		return false;
	}
}

Vector operator + (Vector &v1, Vector &v2) {
	Vector v3;

	v3.setX(v1.getX() + v2.getX());
	v3.setY(v1.getY() + v2.getY());
	v3.setZ(v1.getZ() + v2.getZ());
	return v3;
}
Vector operator - (Vector &v1, Vector &v2) {
	Vector v3;

	v3.setX(v1.getX() - v2.getX());
	v3.setY(v1.getY() - v2.getY());
	v3.setZ(v1.getZ() - v2.getZ());
	return v3;
}
Vector operator * (Vector &v1, int a) {
	Vector v2;

	v2.setX(v1.getX()*a);
	v2.setY(v1.getY()*a);
	v2.setZ(v1.getZ()*a);
	return v2;
}

double Vector::ScalarProduct(Vector v1, Vector v2) {
	double res, res1, res2 ,res3;	
	res1 = v1.getX() * v2.getX();
	res2 = v1.getY() * v2.getY();
	res3 = v1.getZ() * v2.getZ();
	res = res1 + res2 + res3;
	return res;
}
Vector Vector::CrossProduct(Vector v1, Vector v2) {
	Vector v3;

	v3.setX((v1.getY()*v2.getZ()) - (v1.getZ()*v2.getY()));
	v3.setY((v1.getX()*v2.getZ()) - (v1.getZ()*v2.getX()));
	v3.setZ((v1.getX()*v2.getY()) - (v1.getY()*v2.getX()));
	return v3;
}
bool Vector::isparallel(Vector v1, Vector v2) {
	Vector nullV(0, 0, 0);
	if (v1.CrossProduct(v1,v2) == nullV) {
		return true;
	}
	else {
		return false;
	}
}
bool Vector::isperpendicular(Vector v1, Vector v2) {
	if (v1.ScalarProduct(v1,v2) == 0) {
		return true;
	}
	else {
		return false;
	}
}
double Vector::TripleProduct(Vector v1, Vector v2, Vector v3) {
	double res = (v1.getX() * v2.getY() * v3.getZ()) + (v1.getY() * v2.getZ() * v3.getX()) + (v1.getZ() * v2.getX() * v3.getY()) - (v1.getZ() * v2.getY() * v3.getX()) - (v1.getY() * v2.getX() * v3.getZ()) - (v1.getX() * v2.getZ() * v3.getY());
	return res;
}
ostream & operator << (ostream &out, Vector &v1) {
	out << "x = " << v1.getX() << endl << "y = " << v1.getY() << endl << "z =" << v1.getZ() << endl;
	return out;
}
istream & operator >> (istream &in, Vector &v1) {
	double x1, y1, z1;
	cout << "Enter x: ";
	in >> x1;
	cout << "Enter y: ";
	in >> y1;
	cout << "Enter z: ";
	in >> z1;
	v1.setX(x1);
	v1.setY(y1);
	v1.setZ(z1);

	return in;
}

Line::Line() {

}
Line::Line(Point p1, Vector v1) {
	x = v1.getX();
	y = v1.getY();
	z = v1.getZ();

	x1 = p1.getX();
	y1 = p1.getY();
	z1 = p1.getZ();
}
Line::Line(Point p1, Point p2) {
	Vector v1(p1, p2);
	x = v1.getX();
	y = v1.getY();
	z = v1.getZ();

	x1 = p1.getX();
	y1 = p1.getY();
	z1 = p1.getZ();

}
double Line::getX1() {
	return x1;
}
double Line::getY1() {
	return y1;
}
double Line::getZ1() {
	return z1;
}
void Line::setX1(double x1) {

	this->x1 = x1;
}
void Line::setY1(double y1) {
	this->y1 = y1;
}
void Line::setZ1(double z1) {
	this->z1 = z1;
}
Vector Line::LineDir(Line l1) {
	Vector v1;
	v1.setX(l1.getX() - l1.getX1());
	v1.setY(l1.getY() - l1.getY1());
	v1.setZ(l1.getZ() - l1.getZ1());
	return v1;
}
Vector Line::LinePerpendicular(Line l1) {
	Vector v1(l1.getX(), l1.getY(), l1.getZ());
	Vector v2(l1.getX1(), l1.getY1(), l1.getZ1());
	return v1.CrossProduct(v1, v2);
}
float Line::FindAngle(Line l1, Line l2) {
	Vector v1(l1.getX(), l1.getY(), l1.getZ());
	Vector v2(l2.getX(), l2.getY(), l2.getZ());
	double dot = v1.ScalarProduct(v1,v2);
	cout << dot << endl;
	double ax1 = v1.VectorLength(v1);
	double ax2 = v2.VectorLength(v2);
	float angle = acos(dot/(ax1 * ax2));
	return angle;
}

bool operator +(Line l1, Point p2) {
	
	Point p1, p3;
	p1.setX(l1.getX());
	p1.setY(l1.getY());
	p1.setZ(l1.getZ());

	p3.setX(l1.getX1());
	p3.setY(l1.getY1());
	p3.setZ(l1.getZ1());

	Vector v1(p1, p2);
	Vector v2(p2, p3);
	Vector v3(p1, p3);

	double len1, len2, len3;
	len1 = v1.VectorLength(v1);
	len2 = v2.VectorLength(v2);
	len3 = v3.VectorLength(v3);

	if (len1 + len2 == len3) {
		return true;
	}
	else {
		return false;
	}
}
bool operator || (Line l1, Line l2) {
	Point p1, p2, p3, p4;
	p1.setX(l1.getX());
	p1.setY(l1.getY());
	p1.setZ(l1.getZ());

	p2.setX(l1.getX1());
	p2.setY(l1.getY1());
	p2.setZ(l1.getZ1());

	p3.setX(l2.getX());
	p3.setY(l2.getY());
	p3.setZ(l2.getZ());

	p4.setX(l2.getX1());
	p4.setY(l2.getY1());
	p4.setZ(l2.getZ1());

	Vector v1(p1, p2);
	Vector v2(p3, p4);

	if (v1.isparallel(v1, v2) == true) {
		return true;
	}
	else {
		return false;
	}
}
bool operator == (Line l1, Line l2) {
	Point p1, p2, p3, p4;
	p1.setX(l1.getX());
	p1.setY(l1.getY());
	p1.setZ(l1.getZ());

	p2.setX(l1.getX1());
	p2.setY(l1.getY1());
	p2.setZ(l1.getZ1());

	p3.setX(l2.getX());
	p3.setY(l2.getY());
	p3.setZ(l2.getZ());

	p4.setX(l2.getX1());
	p4.setY(l2.getY1());
	p4.setZ(l2.getZ1());

	if (p1 == p3 && p2 == p4) {
		return true;
	}
	else {
		return false;
	}
}
bool operator && (Line l1, Line l2) {
	Point p1, p2, p3, p4;
	p1.setX(l1.getX());
	p1.setY(l1.getY());
	p1.setZ(l1.getZ());

	p2.setX(l1.getX1());
	p2.setY(l1.getY1());
	p2.setZ(l1.getZ1());

	p3.setX(l2.getX());
	p3.setY(l2.getY());
	p3.setZ(l2.getZ());

	p4.setX(l2.getX1());
	p4.setY(l2.getY1());
	p4.setZ(l2.getZ1());

	Vector v1(p1.getX(), p1.getY(), p1.getZ());
	Vector v2(p3.getX(), p3.getY(), p3.getZ());
	Vector v3(p4, p2);

	if (v1.ScalarProduct(v1.CrossProduct(v1, v2), v2) == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool operator != (Line l1, Line l2) {
	Point p1, p2;
	p1.setX(l1.getX());
	p1.setY(l1.getY());
	p1.setZ(l1.getZ());


	p2.setX(l2.getX());
	p2.setY(l2.getY());
	p2.setZ(l2.getZ());

	Vector v1(p1.getX(), p1.getY(), p1.getZ());
	Vector v2(p2.getX(), p2.getY(), p2.getZ());

	Vector v3(v1.CrossProduct(v1, v2));

	if (v1.nullvector(v1)) {
		return true;
	}
	else {
		return false;
	}
}
bool operator | (Line l1, Line l2) {
	Point p1, p2;
	p1.setX(l1.getX());
	p1.setY(l1.getY());
	p1.setZ(l1.getZ());


	p2.setX(l2.getX());
	p2.setY(l2.getY());
	p2.setZ(l2.getZ());

	Vector v1(p1.getX(), p1.getY(), p1.getZ());
	Vector v2(p2.getX(), p2.getY(), p2.getZ());

	double c1;
	c1 = v1.ScalarProduct(v1, v2);
	if (c1 == 0) {
		return true;
	}
	else {
		return false;
	}
}

ostream & operator << (ostream &out, Line &l1) {
	out << "x = " << l1.getX() << endl << "y = " << l1.getY() << endl << "z =" << l1.getZ() << endl << "x1 = " << l1.getX1() << endl << "y1 = " << l1.getY1() << endl << "z1 = " << l1.getZ1() << endl;
	return out;
}
istream & operator >> (istream &in, Line &l1) {
	double x1, y1, z1, x2, y2, z2;
	cout << "Enter x: ";
	in >> x1;
	cout << "Enter y: ";
	in >> y1;
	cout << "Enter z: ";
	in >> z1;
	cout << "Enter x1: ";
	in >> x2;
	cout << "Enter y1: ";
	in >> y2;;
	cout << "Enter z1: ";
	in >> z2;

	l1.setX(x1);
	l1.setY(y1);
	l1.setZ(z1);
	l1.setX1(x2);
	l1.setY1(y2);
	l1.setZ1(z2);


	return in;
}

Segment::Segment() {
	x = 0;
	y = 0;
	z = 0;
}

Segment:: Segment(Line l1) {
	x = l1.getX() + l1.getX1();
	y = l1.getY() + l1.getY1();
	z = l1.getZ() + l1.getZ1();
}
double Segment::SegmentLength(Segment s1) {
	Vector v1(s1.getX(), s1.getY(), s1.getZ());
	double l;
	l = v1.VectorLength(v1);
	return l;
}
Point Segment::MidPoint(Segment s1) {
	Point p1;
	p1.setX((s1.getX() + s1.getX1()) / 2);
	p1.setY((s1.getY() + s1.getY1()) / 2);
	p1.setZ((s1.getZ() + s1.getZ1()) / 2);

	return p1;
}
bool operator == (Segment s1, Point p2) {
	Point p1, p3;
	p1.setX(s1.getX());
	p1.setY(s1.getY());
	p1.setZ(s1.getZ());

	p3.setX(s1.getX1());
	p3.setY(s1.getY1());
	p3.setZ(s1.getZ1());

	Vector v1(p1, p2);
	Vector v2(p2, p3);
	Vector v3(p1, p3);

	double len1, len2, len3;
	len1 = v1.VectorLength(v1);
	len2 = v2.VectorLength(v2);
	len3 = v3.VectorLength(v3);

	if (len1 + len2 == len3) {
		return true;
	}
	else {
		return false;
	}
}

ostream & operator << (ostream &out, Segment &s1) {
	out << "x = " << s1.getX() << endl << "y = " << s1.getY() << endl << "z =" << s1.getZ() << endl << "x1 = " << s1.getX1() << endl << "y1 = " << s1.getY1() << endl << "z1 = " << s1.getZ1() << endl;
	return out;
}
istream & operator >> (istream &in, Segment &s1) {
	double x1, y1, z1, x2, y2, z2;
	cout << "Enter x: ";
	in >> x1;
	cout << "Enter y: ";
	in >> y1;
	cout << "Enter z: ";
	in >> z1;
	cout << "Enter x1: ";
	in >> x2;
	cout << "Enter y1: ";
	in >> y2;;
	cout << "Enter z1: ";
	in >> z2;

	s1.setX(x1);
	s1.setY(y1);
	s1.setZ(z1);
	s1.setX1(x2);
	s1.setY1(y2);
	s1.setZ1(z2);

	return in;
}

double Triangle::getX1() {
	return x1;
}
double Triangle::getY1() {
	return y1;
}
double Triangle::getZ1() {
	return z1;
}


void Triangle::setX1(double x1) {

	this->x1 = x1;
}
void Triangle::setY1(double y1) {
	this->y1 = y1;
}
void Triangle::setZ1(double z1) {
	this->z1 = z1;
}


double Triangle::getX2() {
	return x2;
}
double Triangle::getY2() {
	return y2;
}
double Triangle::getZ2() {
	return z2;
}


void Triangle::setX2(double x2) {

	this->x2 = x2;
}
void Triangle::setY2(double y2) {
	this->y2 = y2;
}
void Triangle::setZ2(double z2) {
	this->z2 = z2;
}

Triangle::Triangle() {
	x = 0;
	y = 0;
	z = 0;

	x1 = 1;
	y1 = 1;
	z1 = 1;

	x2 = 2;
	y2 = 2;
	z2 = 2;
}
Triangle::Triangle(Point p1, Point p2, Point p3) {
	x = p1.getX();
	y = p1.getY();
	z = p1.getZ();

	x1 = p2.getX();
	y1 = p2.getY();
	z1 = p2.getZ();

	x2 = p3.getX();
	y2 = p3.getY();
	z2 = p3.getZ();

}

int Triangle::TypeofTriangle(Triangle t1) {
	Point p1, p2, p3;
	p1.setX(t1.getX());
	p1.setY(t1.getY());
	p1.setZ(t1.getZ());

	p2.setX(t1.getX1());
	p2.setY(t1.getY1());
	p2.setZ(t1.getZ1());

	p3.setX(t1.getX2());
	p3.setY(t1.getY2());
	p3.setZ(t1.getZ2());

	Vector v1(p1, p2);
	Vector v2(p2 ,p3);
	Vector v3(p1 ,p3);

	int a = v1.VectorLength(v1);
	int b = v2.VectorLength(v2);
	int c = v3.VectorLength(v3);

	if (a == b) {
		return 1;
	}
	else if (a == b && b == c) {
		return 2;
	}
	else if (pow(a, 2) + pow(b, 2) > pow(c, 2)) {
		return 3;
	}
	else if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
		return 4;
	}
	else if (pow(a, 2) + pow(b, 2) < pow(c, 2)) {
		return 5;
	}
}

float Triangle::CalculateArea(Point p1, Point p2, Point p3) {
	return abs (p1.getX() *(p2.getY() - p3.getY()) + p2.getX() * (p3.getY() - p1.getY()) + p3.getX()*(p1.getY() - p2.getY()) / 2.0);
}

int Triangle::Inside(Triangle t1, Point p4) {
	Point p1, p2, p3;
	p1.setX(t1.getX());
	p1.setY(t1.getY());
	p1.setZ(t1.getZ());

	p2.setX(t1.getX1());
	p2.setY(t1.getY1());
	p2.setZ(t1.getZ1());

	p3.setX(t1.getX2());
	p3.setY(t1.getY2());
	p3.setZ(t1.getZ2());

	int temp = 0;
	float area, area1, area2, area3;
	area = CalculateArea(p1, p2, p3);
	area1 = CalculateArea(p4, p2, p3);
	area2 = CalculateArea(p1, p4, p3);
	area3 = CalculateArea(p1, p2, p4);

	if (area == area1 + area2 + area3) {
		Vector v1(p4, p1);
		Vector v2(p4, p2);
		Vector v3(p4, p3);

		Vector v11(p1, p2);
		Vector v21(p2, p3);
		Vector v31(p1, p3);
		double a = v1.VectorLength(v1);
		double b = v2.VectorLength(v2);
		double c = v3.VectorLength(v3);

		double a1 = v11.VectorLength(v11);
		double b1 = v21.VectorLength(v21);
		double c1 = v31.VectorLength(v31);


		if (a + b == a1 || c + b == b1 || a + c == c1) {
			temp = 1;
			return temp;
		}
		return temp;
	}
	else {
		temp = 2;
		return temp;
	}
}

bool operator > (Triangle t1, Point p4) {
	Point p1, p2, p3;
	p1.setX(t1.getX());
	p1.setY(t1.getY());
	p1.setZ(t1.getZ());

	p2.setX(t1.getX1());
	p2.setY(t1.getY1());
	p2.setZ(t1.getZ1());

	p3.setX(t1.getX2());
	p3.setY(t1.getY2());
	p3.setZ(t1.getZ2());

	int temp = t1.Inside(t1, p4);
	if (temp == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool operator < (Triangle t1, Point p4) {
	Point p1, p2, p3;
	p1.setX(t1.getX());
	p1.setY(t1.getY());
	p1.setZ(t1.getZ());

	p2.setX(t1.getX1());
	p2.setY(t1.getY1());
	p2.setZ(t1.getZ1());

	p3.setX(t1.getX2());
	p3.setY(t1.getY2());
	p3.setZ(t1.getZ2());

	int temp = t1.Inside(t1, p4);
	if (temp == 2) {
			return true;
	}
	else {
		return false;
	}
}
bool operator == (Triangle t1, Point p4) {
	Point p1, p2, p3;
	p1.setX(t1.getX());
	p1.setY(t1.getY());
	p1.setZ(t1.getZ());

	p2.setX(t1.getX1());
	p2.setY(t1.getY1());
	p2.setZ(t1.getZ1());

	p3.setX(t1.getX2());
	p3.setY(t1.getY2());
	p3.setZ(t1.getZ2());

	int temp = t1.Inside(t1, p4);
	if (temp == 1) {
		return true;
	}
	else {
		return false;
	}
}
int Triangle::FindS(Triangle t1) {
	Point p1, p2, p3;
	p1.setX(t1.getX());
	p1.setY(t1.getY());
	p1.setZ(t1.getZ());

	p2.setX(t1.getX1());
	p2.setY(t1.getY1());
	p2.setZ(t1.getZ1());

	p3.setX(t1.getX2());
	p3.setY(t1.getY2());
	p3.setZ(t1.getZ2());

	Vector v1(p1, p2);
	Vector v2(p2, p3);
	Vector v3(p1, p3);

	int a = v1.VectorLength(v1);
	int b = v2.VectorLength(v2);
	int c = v3.VectorLength(v3);

	int p = (a + b + c) / 2;
	int s = sqrt(p*(p - a)*(p - b)*(p - c));
	return s;
}
int Triangle::FindP(Triangle t1) {
	Point p1, p2, p3;
	p1.setX(t1.getX());
	p1.setY(t1.getY());
	p1.setZ(t1.getZ());

	p2.setX(t1.getX1());
	p2.setY(t1.getY1());
	p2.setZ(t1.getZ1());

	p3.setX(t1.getX2());
	p3.setY(t1.getY2());
	p3.setZ(t1.getZ2());

	Vector v1(p1, p2);
	Vector v2(p2, p3);
	Vector v3(p1, p3);

	int a = v1.VectorLength(v1);
	int b = v2.VectorLength(v2);
	int c = v3.VectorLength(v3);
	int P = a + b + c;
	return P;
}
Point Triangle::Medicenter(Triangle t1) {
	Point p1,p2,p3,p4;

	p1.setX(t1.getX());
	p1.setY(t1.getY());
	p1.setZ(t1.getZ());

	p2.setX(t1.getX1());
	p2.setY(t1.getY1());
	p2.setZ(t1.getZ1());

	p2.setX(t1.getX2());
	p2.setY(t1.getY2());
	p2.setZ(t1.getZ2());

	p4.setX((p1.getX() + p2.getX() + p3.getX()) / 3);
	p4.setY((p1.getY() + p2.getY() + p3.getY()) / 3);
	p4.setZ((p1.getZ() + p2.getZ() + p3.getZ()) / 3);
	return p4;
}

ostream & operator << (ostream &out, Triangle &t1) {
	out << "x = " << t1.getX() << endl << "y = " << t1.getY() << endl << "z =" << t1.getZ() << endl << "x1 = " << t1.getX1() << endl << "y1 = " << t1.getY1() << endl << "z1 = " << t1.getZ1() << endl << "x2 = " << t1.getX2() << endl << "y2 = " << t1.getY2() << endl << "z2 = " << t1.getZ2() << endl;
	return out;
}
istream & operator >> (istream &in, Triangle &t1) {
	double x1, y1, z1, x2, y2, z2, x3, y3, z3;
	cout << "Enter x: ";
	in >> x1;
	cout << "Enter y: ";
	in >> y1;
	cout << "Enter z: ";
	in >> z1;
	cout << "Enter x1: ";
	in >> x2;
	cout << "Enter y1: ";
	in >> y2;;
	cout << "Enter z1: ";
	in >> z2;
	cout << "Enter x2: ";
	in >> x3;
	cout << "Enter y2: ";
	in >> y3;;
	cout << "Enter z2: ";
	in >> z3;

	t1.setX(x1);
	t1.setY(y1);
	t1.setZ(z1);
	t1.setX1(x2);
	t1.setY1(y2);
	t1.setZ1(z2);
	t1.setX2(x3);
	t1.setY2(y3);
	t1.setZ2(z3);

	return in;
}