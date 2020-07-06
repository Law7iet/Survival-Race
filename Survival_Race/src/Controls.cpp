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
	// Uppercase letter and Lower case letters can controlled the car
	switch (key) {
	case 'a':
		if (car.get_x() > BORDER_LEFT)
		{
			car.set_x(car.get_x() - MOVE);
		}
		break;
	case 'A':
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
	case 'D':
		if (car.get_x() < BORDER_RIGHT)
		{
			car.set_x(car.get_x() + MOVE);
		}
		break;
	case 'q':
		points.set_value(-1);
		break;
	case 'Q':
		points.set_value(-1);
		break;
	default:
		break;
	}
}

void Hit(Car& car, Points& points, Road road, int index)
{
	p_segment tmp = new Segment;
	tmp = road.get_current_segment();
	// r is the top-raw printed in the display
	int r = index % LENGTH;
	int x = car.get_x();
	char key = tmp->field[r][x];
	// check if in the current segment there is an element in (r, x) position
	if (key != ' ')
	{
		// clean the display beacuse the points could change
		system("CLS");
		// depending on the element, it decrease or increase points
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

void Change_Level(Points points, Road& road, int index)
{
	// r is the y coord of the current field of the road's stream
	int r = index % LENGTH;
	// check r, if the condition is true, means the next iteration it prints 2 segments
	if (r == 30)
	{
		int score = points.get_value();
		// x is the new road's level
		int x = (score / 200) + 1;
		// if x is higher than the past difficulty, there's level up
		while (x > road.get_current_difficulty())
		{
			road.level_up();
			x--;
		}
		// if x is lower than the past difficulty, there's level down
		while (x < road.get_current_difficulty())
		{
			road.level_down();
			x++;
		}
	}
}
