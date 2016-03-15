/*
 *	Write a program which computes different shapes areas given a single
 *	dimension
 */
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef enum {SQUARE, CIRCLE, TRIANGLE} t_shape;

float square_area (const float side) {
	return side * side;
}

float circle_area (const float radius) {
	return radius * radius * M_PI;
}

float triangle_area (const float height) {
	return height * height / 2;
}

float shape_area (t_shape shape, const float dim) {

	float area;

	switch(shape) {
		case SQUARE: area = square_area(dim); break;
		case CIRCLE: area = circle_area(dim); break;
		case TRIANGLE: area = triangle_area(dim); break;
		default: area = 0.0;
	}

	return area;
}


int main() {

	float val, s_area, c_area, t_area;

	cout << "Enter dimension value: ";
	cin >> val;

	s_area = shape_area(SQUARE, val);
	c_area = shape_area(CIRCLE, val);
	t_area = shape_area(TRIANGLE, val);

	cout << "The square area is " << s_area << endl;
	cout << "The circle area is " << c_area << endl;
	cout << "The triangle area is " << t_area << endl;

    cout << "The triangle area is " << t_area / s_area * 100 << " percent of the square area" << endl;
    cout << "The quadrant area is " << c_area / 4 / s_area * 100 << " percent of the square area" << endl;
	cout << "Bye." << endl;

	return EXIT_SUCCESS;
}
