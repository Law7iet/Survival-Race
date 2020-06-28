#define BORDER_LEFT 1
#define BORDER_RIGHT 9
#define MOVE 1


#include "..\headers\Controls.h"
#include <conio.h>
#include <Windows.h>

void Move(Car& car, Points& points)
{
	char key = ' ';
	if (_kbhit())
	{
		key = _getch();
	}
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

	int r = index % LENGTH;
	int x = car.get_x();

	char key = tmp->field[r][x];

	if (key != ' ')
	{
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
		}
	}
}

void Level(Points points, Road& road, int index)
{
	int r = index % LENGTH;
	if (r == 30)
	{
		int score = points.get_value();
		int x = road.get_current_difficulty() * 200;
		if (score > x)
		{
			road.level_up();
		}
		if (score <= x - 200)
		{
			road.level_down();
		}
	}
}
