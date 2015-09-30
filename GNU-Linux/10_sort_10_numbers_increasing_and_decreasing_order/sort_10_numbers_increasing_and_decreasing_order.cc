/*
 *	Write a program which sorts 10 integer numbers entered by the user in both
 *	increasing and decreasing order
 */
#include <iostream>
#include <cstdlib>

using namespace std;

const int NBNUM = 10;

typedef int t_number[NBNUM];

void swap(int &a, int &b) {

	int t;

	t = a;
	a = b;
	b = t;
}

void decreasing_order_sort(t_number &ds) {

	int i, j;

	for (i = 0 ; i < NBNUM - 1; i++)
		for (j = 0 ; j < NBNUM - i - 1; j++)
			if (ds[j] < ds[j+1]) // decreasing order
				swap(ds[j], ds[j+1]);
}

void increasing_order_sort(t_number &ds) {

	int i, j;

	for (i = 0 ; i < NBNUM - 1; i++)
		for (j = 0 ; j < NBNUM - i - 1; j++)
			if (ds[j] > ds[j+1]) // increasing order
				swap(ds[j], ds[j+1]);
}


int main() {

	int count;
	t_number nmbrs;

	cout << "Enter " << NBNUM << " numbers separated by spaces:" << endl;
	for(count = 0; count < NBNUM; count++) 
		cin >> nmbrs[count];

	decreasing_order_sort(nmbrs);

	cout << "Numbers displayed in decreasing order" << endl;
	for(count = 0; count < NBNUM; count++) 
		cout << nmbrs[count] << " : ";
	cout << endl;

	increasing_order_sort(nmbrs);

	cout << "Numbers displayed in increasing order" << endl;
	for(count = 0; count < NBNUM; count++) 
		cout << nmbrs[count] << " : ";
	cout << endl;

	cout << "Bye." << endl;

	return EXIT_SUCCESS;
}
