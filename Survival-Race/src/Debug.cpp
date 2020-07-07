#include "../headers/Debug.h"
#include "../headers/Locate.h"
#include <iostream>

void print_index(int index, int x, int y)
{
    Locate(x, y);
    std::cout << "Index value: " << index;
}

void print_current_speed(Road road, int x, int y)
{
    Locate(x, y);
    std::cout << "Current speed: " << 200 / road.get_current_speed();
}

void print_current_segment(Road road, int x, int y)
{
    Locate(x, y);
    // C stands for "Current segment"
    std::cout << "C: " << road.get_current_segment();
}

void print_next_segment(Road road, int x, int y)
{
    Locate(x, y);
    // N stands for "Next segment"
    std::cout << "N: " << road.get_next_segment();
}

void print_all_segment(Road road, int x, int y)
{
    p_level tmp1 = road.get_current_level();
    p_segment tmp2;
    int j = 0;
    // iterate all the levels
    while (tmp1 != NULL)
    {
        tmp2 = tmp1->segment;
        Locate(x, y + j);
        j++;
        std::cout << "Level " << tmp1->difficulty << ":";
        // for each levels iterates visit all its segments
        while (tmp2 != NULL)
        {
            Locate(x + 3, y + j);
            std::cout << tmp2;
            j++;
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }
}