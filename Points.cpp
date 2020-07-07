#include "../headers/Points.h"

Points::Points()
{
	this->value = 0;
}

int Points::get_value()
{
	return this->value;
}

void Points::set_value(int x)
{
	this->value = x;
}

void Points::sub_points(int x)
{
	this->value = this->value - x;
}

void Points::add_points(int x)
{
	this->value = this->value + x;
}

bool Points::check_value()
{
	if (value > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}