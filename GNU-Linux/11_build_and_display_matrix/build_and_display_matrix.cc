/*
 *	Write a program which builds and displays a 6 rows and columns matrix like
 *	the example below
 *	   0   1   1   1   1   1
 *    -1   0   1   1   1   1
 *    -1  -1   0   1   1   1
 *    -1  -1  -1   0   1   1
 *    -1  -1  -1  -1   0   1
 *    -1  -1  -1  -1  -1   0
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int DSPWDTH = 4;
const int NBNUM = 6;

typedef int t_matrix[NBNUM][NBNUM];

void build_matrix(t_matrix &bldmtrx) {

	int i, j;

	for(i = 0; i < NBNUM; i++)
		for(j = 0; j < NBNUM; j++)
			if(i == j)
				bldmtrx[i][j] = 0;
			else if (i > j)
				bldmtrx[i][j] = -1;
			else
				bldmtrx[i][j] = 1;
}

void display_matrix(t_matrix dspmtrx) {

	int k, l;

	for(k = 0; k < NBNUM; k++) {
		for(l = 0; l < NBNUM; l++)
			cout << setw(DSPWDTH) << dspmtrx[k][l];
		cout << endl;
	}
}

int main() {

	t_matrix mtrx;

	cout << "First build matrix..." << endl;

	build_matrix(mtrx);

	cout << "\tthen display it!" << endl;

	display_matrix(mtrx);

	cout << endl;

	cout << "Bye." << endl;

	return EXIT_SUCCESS;
}
