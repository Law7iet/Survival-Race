#define DEBUG
 
#include <Windows.h>
#include "headers/Car.h"
#include "headers/Controls.h"
#include "headers/Graphics.h"
#include "headers/Locate.h"
#include "headers/Points.h"
#include "headers/Road.h"
#include "headers/Debug.h"

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
        road.print(index);
        car.print();
        points.add_points(1);
        Score(points.get_value(), road.get_current_difficulty());
        Change_Level(points, road, index);
        road.shift(index);
        road.after(index);
        index++;
        Sleep(200/road.get_current_speed());

        #ifdef DEBUG
        system("CLS");
        print_index(index, 80, 1);
        print_current_speed(road, 80, 2);
        print_current_segment(road, 80, 3);
        print_next_segment(road, 80, 4);
        print_all_segment(road, 80, 5);
        #endif

    } while (points.check_value());

    system("CLS");
    TheEnd();
    Sleep(5000);
    system("CLS");
    exit(0);
}
