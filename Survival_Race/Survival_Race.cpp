#include <iostream>
#include <Windows.h>
#include "headers/Car.h"
#include "headers/Controls.h"
#include "headers/Graphics.h"
#include "headers/Locate.h"
#include "headers/Points.h"
#include "headers/Road.h"

int main()
{
    int index = 0;
    Points points = Points();
    Car car = Car();
    Road road = Road();

    Intro();
    Sleep(2000);
    system("CLS");

    do
    {
        Move(car, points);
        Hit(car, points, road, index);

        points.increase_points(1);
        road.print_level(index);
        car.print();
        Score(points.get_value(), road.get_current_difficulty());

        Level(points, road, index);

        index++;

        road.after(index);
        road.shift(index);

        Sleep(200/road.get_current_speed());

        // DEBUG
        Locate(80, 2);
        std::cout << "y: " << index;
        Locate(80, 3);
        std::cout << "Speed: " << (float)(200 / road.get_current_speed());
        // end DEBUG

    } while (points.check_value());

    system("CLS");
    TheEnd();
    Sleep(5000);
    system("CLS");
    exit(0);
}
