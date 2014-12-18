#include <iostream>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stropts.h>
#include <unistd.h>

using namespace std;

void clear() {

	// Efface l'écran et place le curseur en (0,0):
	cout << "\x1b[2J\x1b[0;0f";
}

void cleareol() {

	// Efface la ligne à partir de la position du curseur
	cout << "\x1b[K";
}

void clearattr() {

	// Efface les attributs de couleurs
	cout << "\x1b[0m";
}

void gotoxy(int x, int y) {

	// Place le curseur à la position x sur la ligne y
	cout << "\x1b[" << y << ';' << x << 'f';
}

int keypressed() {

	static const int STDIN = 0;
	static bool initialized = false;
	termios term;
	int bytesWaiting;

	if (! initialized) {
		// Désactivation du tampon mémoire sur le flux standard
		tcgetattr(STDIN, &term);
		term.c_lflag &= ~ICANON;
		tcsetattr(STDIN, TCSANOW, &term);
		setbuf(stdin, NULL);
		// Synchronisation entre flux standard et iostream
		cin.sync_with_stdio();

		initialized = true;
	}

	ioctl(STDIN, FIONREAD, &bytesWaiting);
	return bytesWaiting;
}

void menu() {

	gotoxy(5,10);
	cout << "\x1b[1mChoix de la couleur ou sortie du programme\x1b[0m" << endl;
	gotoxy(5,12);
	cout << "\x1b[31m[R]ouge\x1b[0m" << endl;
	gotoxy(5,13);
	cout << "\x1b[32m[V]ert\x1b[0m" << endl;
	gotoxy(5,14);
	cout << "\x1b[34m[B]leu\x1b[0m" << endl;
	gotoxy(5,16);
	cout << "[Q]uitter" << endl;
}

void drawline(int l) {

	int i;

	for (i = 0; i < l; i++)
		cout << ' ';
}

int main() {

	char c;
	int length;

	// Initialisation
	srand(time(NULL));
	clear();
	menu();

	// Tâche de fond
	do {
		length = rand() % 50;

		usleep(1000);
		gotoxy(5,20);
		cleareol();

		switch(c) {
			case 'R':
				cout << "\x1b[41m";
				break;
			case 'V': 
				cout << "\x1b[42m";
				break;
			case 'B': 
				cout << "\x1b[44m";
				break;
			default: 
				cout << "\x1b[107m";
				break;
		}
		drawline(length);
		clearattr();

		// Détection appui touche
		if (keypressed()) {
			// Lecture d'un caractère au clavier
			c = toupper(getchar());
			fflush(stdin);
		}

	} while (c != 'Q');

	// Sortie
	gotoxy(5,25);
	cout << "Fin du programme avec le caractère [" << c << "] !" << endl;

	return 0;
}
