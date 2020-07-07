// to use standar ASCII, put '|' as value of variables in raw 99

#define LENGTH 50
#define WIDTH 11
#define DISPLAY_Y 20
#define OFFSET_X 15
#define OFFSET_Y 1

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../headers/Locate.h"
#include "../headers/Road.h"

using namespace std;

Road::Road()
{
	// create the first level and set its members
	this->level = new Level;
	this->level->difficulty = 1;
	this->level->speed = 1;
	this->level->segment = NULL;
	new_segment(this->level->difficulty);
	this->level->next = NULL;

	// setup the members with the first level
	this->current_speed = 1;
	this->current_difficulty = 1;
	this->current_segment = this->level->segment;
	this->next_segment = NULL;
}

int Road::get_current_difficulty()
{
	return current_difficulty;
}

float Road::get_current_speed()
{
	return this->current_speed;
}

p_segment Road::get_current_segment()
{
	return this->current_segment;
}

p_segment Road::get_next_segment()
{
	return this->next_segment;
}

p_level Road::get_current_level()
{
	return this->level;
}

void Road::new_level()
{
	// search the next new level, i indicates the difficulty of the level
	int i = 2;
	p_level tmp = this->level;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = new Level;
	tmp->next->difficulty = i;
	// setup the level's speed
	if (i >= 5)
	{
		// if the difficulty is bigger than 5, the speed increments of 0.2 for each level
		tmp->next->speed = 1 + ((i - 5.0) / 5.0);
	}
	else
	{
		tmp->next->speed = 1;
	}
	tmp->next->segment = NULL;
	tmp->next->next = NULL;
}

void Road::new_segment(int difficulty)
{
	// tmp is the new segment
	p_segment tmp = new Segment;
	tmp->next = NULL;
	// initialize field.
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{

			if (j == 0 || j == WIDTH - 1)
			{
				tmp->field[i][j] = char(186);
			}
			else
			{
				tmp->field[i][j] = ' ';
			}
		}
	}
	// calculate the number of the items in the level.
	int item = 0;
	switch (difficulty)
	{
	case 1:
		// 10% of the number of the length
		item = LENGTH * 10 / 100;
		break;
	case 2:
		// 20% of the number of the length
		item = LENGTH * 20 / 100;
		break;
	case 3:
		// 30% of the number of the length
		item = LENGTH * 30 / 100;
		break;
	case 4:
		// 40% of the number of the length
		item = LENGTH * 40 / 100;
		break;
	case 5:
		// 50% of the number of the length
		item = LENGTH * 50 / 100;
	default:
		item = LENGTH * 60 / 100;
	}
	// assignment item in field
	char A[] = { 'x', '*', '+', 'O' };
	int x = 0;
	int y = 0;
	int type = 0;
	srand((unsigned)time(NULL));
	while (item > 0)
	{
		type = rand() % 4;
		x = rand() % (LENGTH - 1);
		y = rand() % (WIDTH - 1);
		if (tmp->field[x][y] == ' ')
		{
			tmp->field[x][y] = A[type];
			item--;
		}
	}

	// search the right level for tmp
	p_level i = new Level;
	i = this->level;
	// assume there's a i->difficulty == difficulty
	while (i->difficulty != difficulty)
	{
		i = i->next;
	}
	// check if level is empty
	if (i->segment == NULL)
	{
		// if yes, add tmp as the first segment
		i->segment = new Segment;
		i->segment = tmp;
	}
	else
	{
		// if not, iterate and add in queue
		p_segment k = new Segment;
		k = i->segment;
		while (k->next != NULL)
		{
			k = k->next;
		}
		k->next = tmp;
	}
}

void Road::shift(int y)
{
	int r = y % LENGTH;
	// check r, if condition is true, means the next iteration the currents segments is all printed
	// so it changes the next segment, that is "after"
	if (r == 49)
	{
		this->current_segment = this->next_segment;
		this->next_segment = this->next_segment->next;
	}
}

void Road::after(int y)
{
	int r = y % LENGTH;
	// check r, if condition is true, means the next iteration it prints 2 segments
	// so check if the next segment, "after", is there, otherwise it creates
	if (r == 30)
	{
		if (this->next_segment == NULL)
		{
			new_segment(this->current_difficulty);
			this->next_segment = this->current_segment->next;
		}
	}
}

void Road::level_up()
{
	int i = 1;
	int n = this->current_difficulty;
	p_level tmp = this->level;
	// search the next level, that is the next number of current_difficulty
	while (i < n)
	{
		tmp = tmp->next;
		i++;
	}
	// i indicates the difficulty of the new level
	i++;
	// if there isn't the next level, it creates the new level and the first segment of the new level
	if (tmp->next == NULL)
	{
		new_level();
		new_segment(i);
	}
	// change the current variables
	this->current_speed = tmp->next->speed;
	this->current_difficulty = i;
	// the next segment to print is the next level
	this->next_segment = tmp->next->segment;
	}

void Road::level_down()
{
	int i = 1;
	int n = this->current_difficulty - 1;
	p_level tmp = this->level;
	// search the pre-level that has the difficulty as the current_difficulty - 1
	while (i < n)
	{
		tmp = tmp->next;
		i++;
	}
	// change the current variables
	this->current_speed = tmp->next->speed;
	this->current_difficulty = i;
	// the next segment to print is the first segment of the pre-level
	this->next_segment = tmp->segment;
}

void Road::print(int y)
{
	p_segment tmp = new Segment;
	p_segment pre = new Segment;
	int q = (y + DISPLAY_Y) / LENGTH;
	int r = y % LENGTH;
	// if q is 0 then means y indicate the first segment
	// if r is bigger than 20, means that the level to print is in a segment
	if (r < 30)
	{
		// print the level
		for (int i = 0; i < DISPLAY_Y; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				Locate(j + OFFSET_X, i + OFFSET_Y);
				cout << this->current_segment->field[i + (y % LENGTH)][j];
			}
		}
	}
	// otherwise the level to print is between 2 segments
	else
	{
		// calculate q, the numbers of rows to print of the first segment
		q = LENGTH - r;
		// print the first q rows in the first segment
		for (int i = 0; i < q; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				Locate(j + OFFSET_X, i + OFFSET_Y);
				// y is the first row and i is an offset to print the first q rows
				cout << this->current_segment->field[(y % LENGTH) + i][j];
			}
		}
		// print the second segment
		// i is the y-value of the display
		for (int i = q; i < DISPLAY_Y; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				Locate(j + OFFSET_X, i + OFFSET_Y);
				// the right row in the level is i (the offset) minus the value of q
				// in fact, it prints the rows 0, 1,... of the second segment
				cout << this->next_segment->field[i - q][j];
			}
		}
	}
}
