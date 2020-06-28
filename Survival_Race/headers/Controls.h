#pragma once
#include "Car.h"
#include "Points.h"
#include "Road.h"

void Move(Car& car, Points& points);
void Hit(Car& car, Points&, Road road, int index);
void Level(Points points, Road& road, int index);