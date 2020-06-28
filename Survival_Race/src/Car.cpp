#define BORDER_LEFT 1
#define BORDER_RIGHT 9
#define MOVE 1
#define OFFSET_X 15
#define OFFSET_Y 1

#include <conio.h>
#include <iostream>
#include <Windows.h>
#include "../headers/Car.h"
#include "../headers/Locate.h"

using namespace std;

Car::Car()
{
	this->symbol = 'V';
	this->x_pos = 5;
}

int Car::get_x()
{
	return this->x_pos;
}

void Car::set_x(int x_new_pos)
{
	this->x_pos = x_new_pos;
}

void Car::print()
{
	Locate(x_pos + OFFSET_X, OFFSET_Y);
	cout << symbol;
}
