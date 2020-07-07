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

void Points::subpoints(int x)
{
	this->value = this->value - x;
}

void Points::addpoints(int x)
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
