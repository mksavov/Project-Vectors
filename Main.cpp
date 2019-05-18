#include <iostream>
#include "Vectors.h"
#include <cmath>
#include <exception>

using namespace std;

int main() {
	int UInput;

	do {
		cout << "Choose geometric object: " << endl << "1 - Point" << endl << "2 - Vector" << endl <<  "3 - Line" << endl << "4 - Segment" << endl << "5 - Triangle" << endl << "To close the program type 0" << endl;
		cin >> UInput;
		if (UInput == 1) {
			Point p1;
			cin >> p1;
			cout << "Choose operations with object Point:" << "1 - Check if two Points match" << endl;
			cin >> UInput;
			if (UInput == 1) {
				Point p2;
				cin >> p2;
				if (p1 == p2) {
					cout << "Points match." << endl;
				}
				else {
					cout << "Points don't match." << endl;
				}
			}

		}
		if (UInput == 2) {
			Vector v1;
			cin >> v1;
			int UInput2;
			cout << "Choose operations with object Vector:" << endl << "1 - Vector Length" << endl << "2 - Direction vector" << endl << " 3 - Check for null vector"
				<< endl << "4 - Check if two vectors are parallel" << endl << "5 - Check if two vectors are perpendicular" << endl
				<< "6 - Add two vectors" << endl << "7 - Multiply a vector with a number" << endl << "8 - Dot product of two vectors" <<
				endl << "9 - Cross product of two vectors" << endl << "10 - Triple product of three vectors" << endl;
			cin >> UInput2;
			if (UInput2 == 1) {
				cout << "Vector length is: " << v1.VectorLength(v1) << endl;
			}
			if (UInput2 == 2) {
				try {
					if (v1.VectorLength(v1) == 0) {
						throw VectorLengthException();
					}
				}
				catch(VectorLengthException ex) {
					cout << ex.what() << endl;
				}
				cout << "Direction vector is: " << v1.VectorDir(v1) << endl;
			}
			if (UInput2 == 3) {
				if (v1.nullvector(v1)) {
					cout << "This is a null vector" << endl;
				}
				else {
					cout << "This is NOT a null vector" << endl;
				}
			}
			if (UInput2 == 4) {
				cout << "Enter second vector: " << endl;
				Vector v2;
				cin >> v2;
				try {
					if (v1.VectorLength(v1) == 0 || v2.VectorLength(v2) == 0) {
						throw VectorLengthException();
					}
				}
				catch (VectorLengthException ex) {
					cout << ex.what() << endl;
				}
				if (v1.isparallel(v1, v2)) {
					cout << "The two vectors are parallel." << endl;
				}
				else {
					cout << "The two vectors are NOT parallel." << endl;
				}
			}
			if (UInput2 == 5) {
				cout << "Enter second vector: " << endl;
				Vector v2;
				cin >> v2;
				try {
					if (v1.VectorLength(v1) == 0 || v2.VectorLength(v2) == 0) {
						throw VectorLengthException();
					}
				}
				catch (VectorLengthException ex) {
					cout << ex.what() << endl;
				}
				if (v1.isperpendicular(v1, v2)) {
					cout << "The two vectors are perpendicular." << endl;
				}
				else {
					cout << "The two vectors are NOT perpendicular." << endl;
				}
			}
			if (UInput2 == 6) {
				cout << "Enter second vector: " << endl;
				Vector v2;
				cin >> v2;
				cout << "The new vector is: " << v1 + v2 << endl;
			}
			if (UInput2 == 7) {
				int num;
				cout << "Enter a number to multiply with the vector: " << endl;
				cin >> num;
				cout << "The new vector is: " << v1 * num << endl;
			}
			if (UInput2 == 8) {
				cout << "Enter second vector: " << endl;
				Vector v2;
				cin >> v2;

				cout << "The dot product is: " << v1.ScalarProduct(v1, v2) << endl;
			}
			if (UInput2 == 9) {
				cout << "Enter second vector: " << endl;
				Vector v2;
				cin >> v2;

				cout << "The cross product is: " << v1.CrossProduct(v1, v2) << endl;
			}
			if (UInput2 == 10) {
				cout << "Enter second vector: " << endl;
				Vector v2;
				cin >> v2;

				cout << "Enter third vector: " << endl;
				Vector v3;
				cin >> v3;

				cout << "The triple product is: " << v1.TripleProduct(v1, v2, v3) << endl;
			}
		}
		if (UInput == 3) {
			Line l1;
			cin >> l1;
			cout << "Choose operations with object Line:" << endl << "1 - Direction of line " << endl << "2 - Normal vector" << endl << "3 - Find angle between two lines" << endl <<
				"4 - Find out if a point lies on the line" << endl << "5 - Check if two lines are parallel" << endl << "6 - Check if two lines match" << endl <<
				"7 - Check if two lines are intersected" << endl << "8 - Check if two lines are crossed" << endl << "9 - Check if two lines are perpendicular" << endl;
			int UInput3;
			cin >> UInput3;
			if (UInput3 == 1) {
				cout << "Direction is: " << l1.LineDir(l1) << endl;
			}
			if (UInput3 == 2) {
				cout << "Normal vector is: " << l1.LinePerpendicular(l1) << endl;
			}
			if (UInput3 == 3) {
				cout << "Enter second line: " << endl;
				Line l2;
				cin >> l2;
				cout << "The angle between the two lines is: " << l1.FindAngle(l1, l2) << endl;
			}
			if (UInput3 == 4) {
				cout << "Enter Point: " << endl;
				Point p1;
				cin >> p1;
				if (l1 + p1) {
					cout << "Point lies on line" << endl;
				}
				else {
					cout << "Point doesn't lie on line" << endl;
				}
			}
			if (UInput3 == 5) {
				cout << "Enter second line: " << endl;
				Line l2;
				cin >> l2;
				if (l1 || l2) {
					cout << "Lines are parallel" << endl;
				}
				else {
					cout << "Lines are not parallel" << endl;
				}
			}
			if (UInput3 == 6) {
				cout << "Enter second line: " << endl;
				Line l2;
				cin >> l2;

				if (l1 == l2) {
					cout << "Lines are matched" << endl;
				}
				else {
					cout << "Lines are not matched" << endl;
				}
			}
			if (UInput3 == 7) {
				cout << "Enter second line: " << endl;
				Line l2;
				cin >> l2;

				if (l1 && l2) {
					cout << "Lines are intersected" << endl;
				}
				else {
					cout << "Lines are not intersected" << endl;
				}
			}
			if (UInput3 == 8) {
				cout << "Enter second line: " << endl;
				Line l2;
				cin >> l2;

				if (l1 != l2) {
					cout << "Lines are crossed" << endl;
				}
				else {
					cout << "Lines are not crossed" << endl;
				}
			}
			if (UInput3 == 9) {
				cout << "Enter second line: " << endl;
				Line l2;
				cin >> l2;

				if (l1 | l2) {
					cout << "Lines are perpendicular" << endl;
				}
				else {
					cout << "Lines are not perpendicular" << endl;
				}
			}
		}
		if (UInput == 4) {
			Segment s1;
			cin >> s1;
			cout << "Choose operations with object Segment:" << endl << "1 - Length of Segment" << endl << "2 - Find middle of Segment" <<
				endl << "3 - find if a point lies on the segment" << endl;
			int UInput4;
			cin >> UInput4;
			if (UInput4 == 1) {
				cout << "The segment's length is: " << s1.SegmentLength(s1) << endl;
			}
			if (UInput4 == 2) {
				cout << "The middle point of the segment is: " << s1.MidPoint(s1) << endl;
			}
			if (UInput4 == 3) {
				cout << "Enter point: " << endl;
				Point p1;
				cin >> p1;
				if (s1 == p1) {
					cout << "Point lies on segment." << endl;
				}
				else {
					cout << "Point does NOT lie on segment." << endl;
				}
 			}

		}
		if (UInput == 5) {
			Triangle t1;
			cin >> t1;
			try {
				Point p1,p2,p3;
				p1.setX(t1.getX());
				p1.setY(t1.getY());
				p1.setZ(t1.getZ());

				p2.setX(t1.getX1());
				p2.setY(t1.getY1());
				p2.setZ(t1.getZ1());

				p3.setX(t1.getX2());
				p3.setY(t1.getY2());
				p3.setZ(t1.getZ2());
				if (p1 == p2 || p2 == p3 || p1 == p3) {
					throw EqualPointException();
				}
			}
			catch (EqualPointException e) {
				cout << e.what() << endl;
			}
			cout << "Choose operations with object Triangle:" << endl << "1 - Find the type of the triangle" << endl << "2 - find S" << endl <<
				"3 - Find P" << endl << "4 - Find the Centroid" << endl << "5 - Find if a point lies inside the triangle, outside or on one of the sides of the triangle" << endl;
			int UInput5;
			cin >> UInput5;

			if (UInput5 == 1) {
				if (t1.TypeofTriangle(t1) == 1) {
					cout << "Triangle is an Isosceles triangle." << endl;
				}
				else if (t1.TypeofTriangle(t1) == 2) {
					cout << "Triangle is an Equilateral triangle" << endl;
				}
				else if (t1.TypeofTriangle(t1) == 3) {
					cout << "Triangle is an Acute triangle" << endl;
				}
				else if (t1.TypeofTriangle(t1) == 4) {
					cout << "Triangle is a Right triangle" << endl;
				}
				else if (t1.TypeofTriangle(t1) == 5) {
					cout << "Triangle is an Obtuse triangle" << endl;
				}
			}
			else if (UInput5 == 2) {
				cout << "The S of the triangle is: " << t1.FindS(t1) << endl;
			}
			else if (UInput5 == 3) {
				cout << "The P of the triangle is: " << t1.FindP(t1) << endl;
			}
			else if (UInput5 == 4) {
				cout << "The Centroid of the triangle is: " << t1.Medicenter(t1) << endl;
			}
			else if (UInput5 == 5) {
				cout << "Enter Point: " << endl;
				Point p1;
				cin >> p1;
				if (t1.Inside(t1, p1) == 0) {
					cout << "Point is inside the triangle." << endl;
				}
				else if (t1.Inside(t1, p1) == 1) {
					cout << "Point is on one of the sides of the triangle" << endl;
				}
				else if (t1.Inside(t1, p1) == 2) {
					cout << "Point is outside the triangle" << endl;
				}
			}
		}

	} while (UInput != 0);
	system("pause");
}

