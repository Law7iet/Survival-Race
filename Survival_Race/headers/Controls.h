#pragma once
#include "Car.h"
#include "Points.h"
#include "Road.h"

// move the car
void Move(Car& car, Points& points);
// check if the car hit an object on the road
void Hit(Car& car, Points&, Road road, int index);
// check if it needs to change level
void Change_Level(Points points, Road& road, int index);
