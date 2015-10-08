/*
 * Write a program to display a digit triangle like the example given below
 *	1....
 *	12...
 *	123..
 *	1234.
 *	12345
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

	int i, j, k, lines;

	cout << "How many lines would you like to display? ";
	cin >> lines;

	for(i = 1; i <= lines; i++) {
		for(j = 1; j <=i ; j++)
			cout << j;
		for(k = j; k <= lines; k++)
			cout << '.';
		cout << endl;
	}

	cout << "Bye." << endl;

	return EXIT_SUCCESS;
}

