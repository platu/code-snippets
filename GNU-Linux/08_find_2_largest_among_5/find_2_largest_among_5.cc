/*
 *	Write a program which determines the two largest values among 5 integer
 *	numbers
 */
#include <iostream>
#include <cstdlib>

using namespace std;

void find2largest(int r, int s, int t, int u, int v, int &second_largest, int &largest) {

	largest = r;

	if(s > largest) {
		second_largest = largest;
		largest = s;
	}
	if(t > largest) {
		second_largest = largest;
		largest = t;
	}
	if(u > largest) {
		second_largest = largest;
		largest = u;
	}
	if(v > largest) {
		second_largest = largest;
		largest = v;
	}
}

int main() {

	int a, b, c, d, e, scnd_lrgst, lrgst;

	cout << "Enter 5 values separated by space: ";
	cin >> a >> b >> c >> d >> e;

	find2largest(a, b, c, d, e, scnd_lrgst, lrgst);
	cout << "The two largest values are: " << scnd_lrgst << " and " << lrgst << endl;

	cout << "Bye." << endl;

	return EXIT_SUCCESS;
}
