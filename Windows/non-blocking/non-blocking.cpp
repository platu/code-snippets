#include <iostream>
#include <clocale>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include "conio21/constream"

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
	gotoxy(5,10);
	cout << setclr(LIGHTGRAY) << "Choix de la couleur ou sortie du programme" << endl;
	clreol();
	gotoxy(5,12);
	cout << setclr(RED) << "[R]ouge" << endl;
	clreol();
	gotoxy(5,13);
	cout << setclr(GREEN) << "[V]ert" << endl;
	clreol();
	gotoxy(5,14);
	cout << setclr(BLUE) << "[B]leu" << endl;
	clreol();
	gotoxy(5,16);
	cout << setclr(WHITE) << "[Q]uitter" << endl;
	clreol();
}

void drawline(int l)
{
	int i;

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
		length = rand() % 50;
		usleep(1000);
		gotoxy(5,20);
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
			break;
		}
		drawline(length);
		// Détection appui touche
		if (_kbhit()) {
			// Lecture d'un caractère au clavier
			c = toupper(_getch());
			clearkeybuf();
		}
	} while (c != 'Q');
	// Sortie
	gotoxy(5,25);
	clreol();
	cout << setbk(BLACK) << setclr(LIGHTGRAY)
	     << "Fin du programme avec le caractère [" << c << "] !" << endl;

	return 0;
}
