#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int fgbg, color;

	for (fgbg = 38; fgbg <= 48; fgbg += 10) {
		for (color = 0; color < 256; color++) {
			cout << "\x1b[" << fgbg << ";5;" << color << "m " << setw(5) << color << "\x1b[0m";
			if ((color + 1) % 10 == 0)
				cout << endl;
		}
		cout << endl;
	}

	cout << endl;

	return 0;
}
