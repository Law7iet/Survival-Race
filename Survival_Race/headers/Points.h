#pragma once

class Points {
protected:
	int value;
public:
	Points();
	int get_value();
	void set_value(int x);
	void subpoints(int x);
	void addpoints(int x);
	bool check_value();
};
