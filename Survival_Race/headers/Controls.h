#pragma once
#include "Car.h"
#include "Points.h"
#include "Road.h"

// move the car's x position
void Move(Car& car, Points& points);
// check if the car hit an object on the road
void Hit(Car& car, Points&, Road road, int index);
// check if level-up or level-down
void Level(Points points, Road& road, int index);
