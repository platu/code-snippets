/*
 * Write a program which displays an integer number binary value
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

	int i, shifted, number, size;

	cout << "Enter the decimal number you want to be displayed in binary: ";
	cin >> number;

	size = sizeof number * 8;
	cout << "This number is stored in a variable which type size is "
	     << size << "bits" << endl;
    
	cout << "Its binary value is: ";
	for(i = size - 1; i >= 0; i--) {
		shifted = number >> i;

		if(shifted & 1)
			cout << '1';
		else
			cout << '0';
	}
	cout << endl;

	cout << "Bye." << endl;

	return EXIT_SUCCESS;
}
