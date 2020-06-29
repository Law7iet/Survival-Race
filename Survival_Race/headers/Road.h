#pragma once

#define LENGTH 50
#define WIDTH 11

struct Segment
{
	// the road, a matrix of char
	char field[LENGTH][WIDTH];
	// the next segment
	Segment* next;
};

typedef Segment* p_segment;

struct Level
{
	// it is the level's difficulty
	int difficulty;
	// it is the level's speed
	float speed;
	// it is the first segment of the level
	p_segment segment;
	// it is the next level
	Level* next;
};

typedef Level* p_level;

class Road
{
protected:
	// it indicates the difficult of the level
	int current_difficulty;
	// it indicates the speed of the game
	float current_speed;
	// it is the object that contains the road
	p_level level;
	// it indicates the current segment and the next segment to print in the display
	p_segment current, after;
public:
	// it creates a segment of the first level
	Road();
	// it returns the current segment
	p_segment get_current();
	// it returns the current difficulty
	int get_current_difficulty();
	// it returns the current speed
	float get_current_speed();
	// it creates a new level if there isn't the current's next level
	void new_level();
	// add in the tail of the level "difficulty" a new segment
	void new_segment(int difficulty);
	// change the current segment
	void shift(int y);
	// check if there's the next segment of  current (could be a segment of the same level or different level)
	void after(int y);
	// search the first segment of the next level and assign it to after
	void level_up();
	// search the first segment of the pre level and assin it to after
	void level_down();
	// print a part of road, depending on the index
	void print_level(int y);
};
