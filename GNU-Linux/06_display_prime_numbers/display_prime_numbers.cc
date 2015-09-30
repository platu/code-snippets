/*
 *	Write a program to display a given number of ... prime numbers
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

	int n, count, prime_count = 0, number = 1;
	bool is_a_prime = true;

	cout << "Enter the number of prime numbers to display: ";
	cin >> n;

	if (n >= 1) {
		prime_count = 1;
		do {
			if (is_a_prime) {
				cout << number << " : ";
				prime_count++;
			}
			number++;
			is_a_prime = true;
			count = 2;
			do {
				if (number % count == 0)
					is_a_prime = false;
				else 
					count++;
			} while (is_a_prime && count < number);
		} while (prime_count <= n);
	}
	else
		cout << "No prime number to display" << endl;

	cout << "Bye." << endl;

	return EXIT_SUCCESS;
}
