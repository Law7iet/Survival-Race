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
	// it indicates the speed of the level
	float current_speed;
	// it indicates the current segment and the next segment to print in the display
	p_segment current_segment, next_segment;
	// it is the object that contains the road
	p_level level;
public:
	// it creates the first segment of the first level
	Road();
	// it returns current_difficulty
	int get_current_difficulty();
	// it returns current_speed
	float get_current_speed();
	// it returns current_segment
	p_segment get_current_segment();
	// it returns next_segment
	p_segment get_next_segment();
	// it returns level
	p_level get_current_level();
	// if there isn't, it creates the next level of the current level
	void new_level();
	// it creates and adds a new segment in the tail of the segment of the level "difficulty"
	void new_segment(int difficulty);
	// it changes the current_segment with the next_segment
	void shift(int y);
	// it checks if there's the next segment of current_segment
	void after(int y);
	// change the level difficulty with the next level
	void level_up();
	// change the level difficulty with the pre level
	void level_down();
	// print a part of road, depending on the index
	void print(int y);
};
