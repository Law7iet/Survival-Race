#pragma once

class Car
{
protected:
	// it rappresent car in the window
	char symbol;
	// is the car's position in the window
	int x_pos;
public:
	// set car's symbol and set car's position in the center
	Car();
	// get car's x_pos
	int get_x();
	// set car's x_pos
	void set_x(int x_new_pos);
	// print car in the window
	void print();
};
