#include "../headers/Locate.h"

#include <Windows.h>

void Locate(int x, int y)           //Posizionamento del cursore
{
	COORD point = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
