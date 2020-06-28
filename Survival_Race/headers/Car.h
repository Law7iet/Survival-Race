#pragma once

class Car
{
protected:
	char symbol;
	int x_pos;
public:
	Car();
	int get_x();
	void set_x(int x_new_pos);
	void print();
};