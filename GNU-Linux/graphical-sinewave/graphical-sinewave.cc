/* Sine Wave */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double TWO_PI = 2 * M_PI;
const float A_MAX = 2.0;
const int MAX_WDTH = 30;

int main() {

	float ampl, freq, smplnb, w, t, sine;
	int smplcnt, spcnb, spccnt;

	cout << "Enter maximum amplitude, frequency and number of samples: ";
	cin >> ampl >> freq >> smplnb;

	cout << fixed << showpos << setprecision(4);

	w = TWO_PI*freq; 
	for (smplcnt = 0; smplcnt <= smplnb; smplcnt++) {
		t = smplcnt / (freq * smplnb);
		sine = ampl * sin(w*t);
		cout << "t= " << t << " sine= " << sine << ": ";
		spcnb = (int) MAX_WDTH / 2 * (sine/A_MAX + 1.0);
		if (spcnb > MAX_WDTH)
			spcnb = MAX_WDTH;
		if (spcnb < 0)
			spcnb = 0;
		// cout << spcnb << ": ";
		for(spccnt = 0; spccnt < spcnb; spccnt++)
			cout << ' ';
		cout << '*' << endl;
	}

	cout << endl;
	return 0;
}
