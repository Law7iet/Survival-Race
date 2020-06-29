#define BORDER_LEFT 1
#define BORDER_RIGHT 9
#define MOVE 1


#include "..\headers\Controls.h"
#include <conio.h>
#include <Windows.h>

void Move(Car& car, Points& points)
{
	char key = ' ';
	// catch the input from the terminal
	if (_kbhit())
	{
		key = _getch();
	}
	// depending on the key the car moves or ends the game
	switch (key) {
	case 'a':
		if (car.get_x() > BORDER_LEFT)
		{
			car.set_x(car.get_x() - MOVE);
		}
		break;
	case 'd':
		if (car.get_x() < BORDER_RIGHT)
		{
			car.set_x(car.get_x() + MOVE);
		}
		break;
	case 'q':
		points.set_value(-1);
		break;
	default:
		break;
	}
}

void Hit(Car& car, Points& points, Road road, int index)
{
	p_segment tmp = new Segment;
	tmp = road.get_current();
	// r is the top-raws printed in the display
	int r = index % LENGTH;
	// x is the car's location
	int x = car.get_x();
	// checks the the current segment element in (r, x) position
	char key = tmp->field[r][x];
	if (key != ' ')
	{
		// clean the display beacuse the points could change
		system("CLS");
		switch (key)
		{
		case('x'):
			points.decrease_points(200);
			break;
		case('*'):
			points.decrease_points(100);
			break;
		case('+'):
			points.decrease_points(50);
			break;
		case('O'):
			points.increase_points(50);
			break;
		default:
			break;
		}
	}
}

void Level(Points points, Road& road, int index)
{
	// r is the y-coordinate of the current field of the road's stream
	int r = index % LENGTH;
	// check r, if condition is true, means the next iteration it prints 2 segments
	if (r == 30)
	{
		int score = points.get_value();
		// x is the higest score of the level
		int x = road.get_current_difficulty() * 200;
		// if score is higher than x, there's level up
		if (score > x)
		{
			road.level_up();
		}
		// if score is lower than x - 200, there's level down
		if (score <= x - 200)
		{
			road.level_down();
		}
	}
}
