/*
 * Write a program to draw a triangle given its width from the left side of the
 * screen. Here is an example:
 *	How wide is the triangle: 5
 *	*
 *	**
 *	***
 *	****
 *	*****
 *	****
 *	***
 *	**
 *	*
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

	int i, j, width;

	cout << "How wide is the triangle: ";
	cin >> width;

	for(i = 0; i < width; i++) {
		for(j = 0; j <= i; j++)
			cout << '*';
		cout << endl;
	}
	for(i = 0; i < width-1; i++) {
		for(j = i; j < width-1; j++)
			cout << '*';
		cout << endl;
	}

	cout << "Bye." << endl;

	return EXIT_SUCCESS;
}
