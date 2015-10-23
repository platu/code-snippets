/* Hailstone Sequence
 * Starting from a random integer value (n), compute the Hailstone sequence
 *
 * if n = 1, the sequence is over
 * if n is even then n = n / 2
 * if n is odd then n = n * 3 + 1
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

	int number, ncount = 0;

	srand(time(NULL));

	// 2 < number < 100
	number = rand() % 99 + 2;

	do {
		cout << number << " : ";
		if (number % 2 == 0) 
			number = number / 2;
		else
			number = number * 3 + 1;
		ncount++;
	} while (number != 1);

	cout << number << endl;
	ncount++;
	cout << "This sequence has " << ncount << " numbers." << endl;  

	return EXIT_SUCCESS;
}
