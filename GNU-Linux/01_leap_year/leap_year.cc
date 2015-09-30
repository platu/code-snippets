/* 
 * Write a program to know if a year is leap
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

	int year;

	cout << "Enter a year to check if it is a leap year: ";
	cin >> year;

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		cout << year << " is a leap year" << endl;
	else
		cout << year << " is not a leap year" << endl;

	cout << "Bye." << endl;

	return EXIT_SUCCESS;
}
