#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAXCHAR = 80;

typedef char CHAINE80[MAXCHAR+1];

int main() {

	CHAINE80 ligne;
	ifstream fichierEnLecture;

	cout << "Donner le nom du fichier à lire" << endl;
	cin >> ligne;

	fichierEnLecture.open(ligne);
	if (fichierEnLecture) {
		do {
			fichierEnLecture.getline(ligne, MAXCHAR);
			cout << ligne << endl;
		} while (! fichierEnLecture.eof());
		fichierEnLecture.close();
	}
	else
		cerr << "Ouverture du fichier " << ligne << " impossible" << endl;

	return 0;
}
