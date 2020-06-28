#include <iostream>
#include "../headers/Locate.h"
#include "../headers/Words.h"

using namespace std;

void A(int& x, int y)
{
	Locate(x, y);
	cout << " ## " << endl;
	Locate(x, y + 1);
	cout << "#  #" << endl;
	Locate(x, y + 2);
	cout << "####" << endl;
	Locate(x, y + 3);
	cout << "#  #" << endl;
	Locate(x, y + 4);
	cout << "#  #" << endl;
	x = x + 5;
}

void C(int& x, int y)
{
	Locate(x, y);
	cout << "####" << endl;
	Locate(x, y + 1);
	cout << "#   " << endl;
	Locate(x, y + 2);
	cout << "#   " << endl;
	Locate(x, y + 3);
	cout << "#   " << endl;
	Locate(x, y + 4);
	cout << "####" << endl;
	x = x + 5;
}

void E(int& x, int y)
{
	Locate(x, y);
	cout << "####" << endl;
	Locate(x, y + 1);
	cout << "#   " << endl;
	Locate(x, y + 2);
	cout << "### " << endl;
	Locate(x, y + 3);
	cout << "#   " << endl;
	Locate(x, y + 4);
	cout << "####" << endl;
	x = x + 5;
}

void G(int& x, int y)
{
	Locate(x, y);
	cout << "####" << endl;
	Locate(x, y + 1);
	cout << "#   " << endl;
	Locate(x, y + 2);
	cout << "# ##" << endl;
	Locate(x, y + 3);
	cout << "#  #" << endl;
	Locate(x, y + 4);
	cout << "####" << endl;
	x = x + 5;
}

void I(int& x, int y)
{
	Locate(x, y);
	cout << "#" << endl;
	Locate(x, y + 1);
	cout << "#" << endl;
	Locate(x, y + 2);
	cout << "#" << endl;
	Locate(x, y + 3);
	cout << "#" << endl;
	Locate(x, y + 4);
	cout << "#" << endl;
	x = x + 2;
}

void L(int& x, int y)
{
	Locate(x, y);
	cout << "#    " << endl;
	Locate(x, y + 1);
	cout << "#    " << endl;
	Locate(x, y + 2);
	cout << "#    " << endl;
	Locate(x, y + 3);
	cout << "#    " << endl;
	Locate(x, y + 4);
	cout << "####" << endl;
	x = x + 5;
}

void M(int& x, int y)
{
	Locate(x, y);
	cout << "## ##" << endl;
	Locate(x, y + 1);
	cout << "# # #" << endl;
	Locate(x, y + 2);
	cout << "#   #" << endl;
	Locate(x, y + 3);
	cout << "#   #" << endl;
	Locate(x, y + 4);
	cout << "#   #" << endl;
	x = x + 6;
}

void O(int& x, int y)
{
	Locate(x, y);
	cout << "####" << endl;
	Locate(x, y + 1);
	cout << "#  #" << endl;
	Locate(x, y + 2);
	cout << "#  #" << endl;
	Locate(x, y + 3);
	cout << "#  #" << endl;
	Locate(x, y + 4);
	cout << "####" << endl;
	x = x + 5;
}

void R(int& x, int y)
{
	Locate(x, y);
	cout << "### " << endl;
	Locate(x, y + 1);
	cout << "#  #" << endl;
	Locate(x, y + 2);
	cout << "### " << endl;
	Locate(x, y + 3);
	cout << "# # " << endl;
	Locate(x, y + 4);
	cout << "#  #" << endl;
	x = x + 5;
}

void S(int& x, int y)
{
	Locate(x, y);
	cout << "####" << endl;
	Locate(x, y + 1);
	cout << "#   " << endl;
	Locate(x, y + 2);
	cout << "####" << endl;
	Locate(x, y + 3);
	cout << "   #" << endl;
	Locate(x, y + 4);
	cout << "####" << endl;
	x = x + 5;
}

void T(int& x, int y)
{
	Locate(x, y);
	cout << "#####" << endl;
	Locate(x, y + 1);
	cout << "  #  " << endl;
	Locate(x, y + 2);
	cout << "  #  " << endl;
	Locate(x, y + 3);
	cout << "  #  " << endl;
	Locate(x, y + 4);
	cout << "  #  " << endl;
	x = x + 6;
}

void U(int& x, int y)
{
	Locate(x, y);
	cout << "#  #" << endl;
	Locate(x, y + 1);
	cout << "#  #" << endl;
	Locate(x, y + 2);
	cout << "#  #" << endl;
	Locate(x, y + 3);
	cout << "#  #" << endl;
	Locate(x, y + 4);
	cout << "####" << endl;
	x = x + 5;
}

void V(int& x, int y)
{
	Locate(x, y);
	cout << "#   #" << endl;
	Locate(x, y + 1);
	cout << "#   #" << endl;
	Locate(x, y + 2);
	cout << "#   #" << endl;
	Locate(x, y + 3);
	cout << " # # " << endl;
	Locate(x, y + 4);
	cout << "  #  " << endl;
	x = x + 6;
}

void W(int& x, int y)
{
	Locate(x, y);
	cout << "#   #" << endl;
	Locate(x, y + 1);
	cout << "#   #" << endl;
	Locate(x, y + 2);
	cout << "# # #" << endl;
	Locate(x, y + 3);
	cout << "# # #" << endl;
	Locate(x, y + 4);
	cout << " # # " << endl;
	x = x + 6;
}