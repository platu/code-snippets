/*
 *	Write a program which determines the minimum and maximum values among 3
 *	integer numbers
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int minval(int x, int y, int z) {

	int min = x;

	if(y < min)
		min = y;
	if(z < min)
		min = z;

	return min;
}

int maxval(int r, int s, int t) {

	int max = r;

	if(s > max)
		max = s;
	if(t > max)
		max = t;

	return max;
}

int main() {

	int a, b, c;

	cout << "Enter 3 values separated by space: ";
	cin >> a >> b >> c;

	cout << "The minimum value is: " << minval(a, b, c) << endl;
	cout << "The maximum value is: " << maxval(a, b, c) << endl;

	cout << "Bye." << endl;

	return EXIT_SUCCESS;
}
