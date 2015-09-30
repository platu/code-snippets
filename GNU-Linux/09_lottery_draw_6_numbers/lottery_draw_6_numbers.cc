/*
 *	Write a program which draws six different random integer numbers
 */
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NBNUM = 6;

typedef int t_lottery[NBNUM];

bool alreadythere(t_lottery d, int v, int c) {

	int i = 0;
	bool there = false;

	do {
		if (v == d[i])
			there = true;
		else
			i++;
	} while (!there && i < c);

	return there;
}

int main() {

	int count = 0, val;
	t_lottery draw;

	srand(time(NULL));

	do {
		do {
			val = rand() % 50;
			if (alreadythere(draw, val, count))
				cout << "New round: " << val << " is already there!" << endl;
		} while(alreadythere(draw, val, count));
		draw[count] = val;
		count++;
	} while (count < NBNUM);

	for(count = 0; count < NBNUM; count++)
		cout << draw[count] << " : ";
	cout << endl;

	cout << "Bye." << endl;

	return EXIT_SUCCESS;
}
