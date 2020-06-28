#pragma once

#define LENGTH 50
#define WIDTH 11

struct Segment
{
	char field[LENGTH][WIDTH];
	Segment* next;
};

typedef Segment* p_segment;

struct Level
{
	int difficulty;
	float speed;
	p_segment segment;
	Level* next;
};

typedef Level* p_level;

class Road
{
protected:
	int current_difficulty;
	float current_speed;
	p_level level;
	p_segment current, after;
public:
	Road();
	p_segment get_current();
	int get_current_difficulty();
	float get_current_speed();
	void new_level();
	void new_segment(int difficulty);
	void shift(int y);
	void check_after(int y);
	void level_up();
	void level_down();
	void print_level(int y);
};
