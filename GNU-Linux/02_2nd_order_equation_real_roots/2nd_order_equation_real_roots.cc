/*
 * Write a program to compute real roots of a quadratic equation
 */
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {

	float a, b, c, delta;

	cout << "Compute real roots of the equation a*x^2 + b*x + c = 0" << endl
	     << "Enter values of a b c separated by space: ";
	cin >> a >> b >> c;

	if (a == 0 && b == 0)
		cout << "No roots" << endl;
	else if (a == 0)
		cout << "One real root: " << -c/b << endl;
	else {
		delta = b*b - 4*a*c;
		if (delta < 0)
			cout << "No real roots" << endl;
		else if (delta == 0)
			cout << "One real double root: " << -b/(2*a) << endl;
		else
			cout << "The equation has 2 real roots: " << endl
			     << (-b + sqrt(delta)) / (2*a)
				 << " and " 
			     << (-b - sqrt(delta)) / (2*a) << endl;
	}

	cout << "Bye." << endl;

	return EXIT_SUCCESS;
}
