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
	cout << "\x1b[2J\x1b[0;0f" << flush;
}

void cleareol() {

	// Efface la ligne à partir de la position du curseur
	cout << "\x1b[K" << flush;
}

void gotoxy(int x, int y) {

	// Place le curseur à la position x sur la ligne y
	cout << "\x1b[" << y << ';' << x << 'f' << flush;
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

int main() {

	char c;

	// Initialisation
	clear();
	gotoxy(5,10);
	cout << "Programme de détection d'appui sur les touches flèches" << endl;

	// Tâche de fond
	do {

		usleep(1000);
		gotoxy(5,20);
		cout << '.';

		// Détection appui touche
		if (keypressed()) {
			// Lecture d'un caractère au clavier
			c = getchar();
			if (c == '\x1b') {
				//cout << '\\';
				c = getchar();
				//cout << c;
				c = getchar();
				//cout << c;
				switch(c) {
					case 'A':
						cout << "haut";
						break;
					case 'B': 
						cout << "bas";
						break;
					case 'C': 
						cout << "droite";
						break;
					case 'D': 
						cout << "gauche";
						break;
					default: 
						cout << c;
						break;
				}
			}
			fflush(stdin);
			cleareol();
		}

	} while (toupper(c) != 'Q');

	// Sortie
	gotoxy(5,25);
	cout << "Fin du programme avec le caractère [" << c << "] !" << endl;

	return 0;
}
