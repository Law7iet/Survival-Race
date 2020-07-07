#pragma once

class Points {
protected:
	int value;
public:
	// set points' value with 0
	Points();
	// get the value
	int get_value();
	// set the value with x
	void set_value(int x);
	// add x to value
	void add_points(int x);
	// sub x to value
	void sub_points(int x);
	// check if value is bigger than 0
	bool check_value();
};
