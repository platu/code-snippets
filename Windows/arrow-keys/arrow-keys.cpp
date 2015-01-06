#include <iostream>
#include <clocale>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include "../conio21/constream"

using namespace std;
using namespace conio;

void usleep(__int64 usec)
{
	HANDLE timer;
	LARGE_INTEGER ft;

	ft.QuadPart = -(10*usec); // Convert to 100 nanosecond interval, negative value indicates relative time

	timer = CreateWaitableTimer(NULL, TRUE, NULL);
	SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
	WaitForSingleObject(timer, INFINITE);
	CloseHandle(timer);
}

int main()
{
	char c;

	setlocale(LC_ALL, "french");

	// Initialisation
	clrscr();
	gotoxy(5,10);
	cout << "Programme de d�tection d'appui sur les touches fl�ches" << endl;

	// T�che de fond
	do {
		usleep(1000);
		gotoxy(5,20);
		cout << '.';

		// D�tection appui touche
		if (_kbhit()) {
			// Lecture d'un caract�re au clavier
			c = _getch();
			//cout << hex << int(c);
			if (c == '\xe0') {
				//cout << '\\';
				c = _getch();
				switch(c) {
					case 'H':
						cout << "haut  ";
						break;
					case 'P':
						cout << "bas   ";
						break;
					case 'M':
						cout << "droite";
						break;
					case 'K':
						cout << "gauche";
						break;
					default:
						cout << c;
						break;
				}
			}
			cout << flush;
			clearkeybuf();
		}
	} while (toupper(c) != 'Q');
	// Sortie
	gotoxy(5,25);
	clreol();
	cout << setbk(BLACK) << setclr(LIGHTGRAY)
	     << "Fin du programme avec le caract�re [" << c << "] !" << endl;

	return 0;
}
