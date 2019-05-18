#pragma once

using namespace std;

class VectorLengthException : public exception {
public:
	char * what() {
		return "Vector length can't be 0.";
	}
};
class EqualPointException : public exception {
public:
	char * what() {
		return "Points cannot be the same.";
	}
};


class Element {

};


class Point : public Element{

protected:
	double x;
	double y;
	double z;
public:
	Point(); //Default constructor

	void setX(double x);

	void setY(double y);

	void setZ(double z);

	double getX();
	double getY();
	double getZ();

	friend bool Point::operator == (Point &p1, Point &p2);	//overloading '==' operator
	friend ostream & operator << (ostream &out, Point &p1);
	friend istream & operator >> (istream &in, Point &p1);
};


class Vector : public Point {
public:
	Vector();
	Vector::Vector(Point p1, Point p2);
	Vector::Vector(double x1, double y1, double z1);


	double VectorLength(Vector v1);
	Vector VectorDir(Vector v1);
	bool nullvector(Vector v1);
	bool isparallel(Vector v1, Vector v2);
	bool isperpendicular(Vector v1, Vector v2);

	friend Vector operator + (Vector &v1, Vector &v2);
	friend Vector operator - (Vector &v1, Vector &v2);
	friend Vector operator * (Vector &v1, int a);

	double ScalarProduct(Vector v1, Vector v2);
	Vector CrossProduct(Vector v1, Vector v2);
	double TripleProduct(Vector v1, Vector v2, Vector v3);

	friend ostream & operator << (ostream &out, Vector &v1);
	friend istream & operator >> (istream &in, Vector &v1);
};

class Line : public Vector {
protected:
	double x1, y1, z1;
public:
	double getX1();
	double getY1();
	double getZ1();

	void setX1(double x1);
	void setY1(double y1);
	void setZ1(double z1);

	Line();
	Line::Line(Point p1, Vector v1);
	Line::Line(Point p1, Point p2);
	Vector LineDir(Line l1);
	Vector LinePerpendicular(Line l1);
	float FindAngle(Line l1, Line l2);
	friend bool operator +(Line l1, Point p1);
	friend bool operator || (Line l1, Line l2);
	friend bool operator == (Line l1, Line l2);
	friend bool operator && (Line l1, Line l2);
	friend bool operator != (Line l1, Line l2);
	friend bool operator | (Line l1, Line l2);

	friend ostream & operator << (ostream &out, Line &l1);
	friend istream & operator >> (istream &in, Line &l1);
};
class Segment : public Line {
public:
	Segment();
	Segment(Line l1);
	double SegmentLength(Segment s1);
	Point MidPoint(Segment s1);
	friend bool operator == (Segment s1, Point p1);

	friend ostream & operator << (ostream &out, Segment &s1);
	friend istream & operator >> (istream &in, Segment &s1);
};

class Triangle : public Point {
protected:
	double x1, y1, z1, x2, y2, z2;
public:
	double getX1();
	double getY1();
	double getZ1();

	double getX2();
	double getY2();
	double getZ2();

	void setX1(double x1);
	void setY1(double y1);
	void setZ1(double z1);

	void setX2(double x2);
	void setY2(double y2);
	void setZ2(double z2);

	Triangle();
	Triangle::Triangle(Point p1, Point p2, Point p3);
	int TypeofTriangle(Triangle t1);
	int FindS(Triangle t1);
	int FindP(Triangle t1);
	Point Medicenter(Triangle t1);
	friend bool operator > (Triangle t1, Point p4);
	friend bool operator < (Triangle t1, Point p4);
	friend bool operator == (Triangle t1, Point p4);
	float CalculateArea(Point p1, Point p2, Point p3);
	int Inside(Triangle t1, Point p4);


	friend ostream & operator << (ostream &out, Triangle &t1);
	friend istream & operator >> (istream &in, Triangle &t1);
};