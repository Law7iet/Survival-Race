#pragma once

class Points {
protected:
	int value;
public:
	Points();
	int get_value();
	void set_value(int x);
	void decrease_points(int x);
	void increase_points(int x);
	bool check_value();
};