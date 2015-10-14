/*
 *	Write a program which determines the two largest values among 5 integer
 *	numbers
 */
#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

void find2largest(int r, int s, int t, int u, int v, int &second_largest, int &largest) {

	largest = r;
	
	if(s > largest)
		largest = s;
	if(t > largest)
		largest = t;
	if(u > largest)
		largest = u;
	if(v > largest)
		largest = v;
	
	second_largest = INT_MIN;

	if(r > second_largest && r < largest)
		second_largest = r;
	if(s > second_largest && s < largest)
		second_largest = s;
	if(t > second_largest && t < largest)
		second_largest = t;
	if(u > second_largest && u < largest)
		second_largest = u;
	if(v > second_largest && v < largest)
		second_largest = v;
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
