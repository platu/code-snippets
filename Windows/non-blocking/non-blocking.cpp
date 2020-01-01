#include <iostream>
#include <clocale>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <constream>

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

void menu()
{
	cout << setxy(5,10) << setclr(LIGHTGRAY) << "Choix de la couleur ou sortie du programme" << endl;
	clreol();
	cout << setxy(5,12) << setclr(RED) << "[R]ouge" << endl;
	clreol();
	cout << setxy(5,13) << setclr(GREEN) << "[V]ert" << endl;
	clreol();
	cout << setxy(5,14) << setclr(BLUE) << "[B]leu" << endl;
	clreol();
	cout << setxy(5,16) << setclr(WHITE) << "[Q]uitter" << endl;
	clreol();
}

void drawline(int l)
{
	int i;

	cout << setxy(5,20);
	for (i = 0; i < l; i++)
		cout << ' ';
	cout << setbk(BLACK);
	clreol();
}

int main()
{
	char c;
	int length;

	setlocale(LC_ALL, "french");

	// Initialisation
	srand(time(NULL));
	clrscr();
	menu();
	// Tâche de fond
	do {
		// Base de temps
		usleep(1000);	
		// Détection appui touche
		if (_kbhit()) {
			// Lecture d'un caractère au clavier
			c = toupper(_getch());
			clearkeybuf();
		}
		switch(c) {
			case 'R':
				cout << setbk(RED);
				break;
			case 'V':
				cout << setbk(GREEN);
				break;
			case 'B':
				cout << setbk(BLUE);
				break;
			default:
				cout << setbk(WHITE);
		}
		// Dessin d'une ligne de longueur aléatoire
		length = rand() % 50;
		drawline(length);
	} while (c != 'Q');
	// Sortie du programme
	cout << setxy(5,25) << setbk(BLACK) << setclr(LIGHTGRAY)
	     << "Fin du programme avec le caractère [" << c << "] !" << endl;
	clreol();

	return 0;
}
