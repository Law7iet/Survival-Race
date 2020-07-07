#define BEGIN 0
#define LENGTH 21
#define WIDTH 70
#define TEXT_X 42
#define TEXT_Y 2

#include <iostream>
#include "../headers/Locate.h"
#include "../headers/Graphics.h"
#include "../headers/Words.h"

using namespace std;

// if can't print, change global variables in '#' (from ASCII)
char TopCornerLeft = '#';//218;
char TopCornerRight = '#';//191;
char MidTop = '#';//194;
char MidBottom = '#';//193;
char BottomCornerLeft = '#';//192;
char BottomCornerRight = '#'; //217;
char Raw = '#';//196;
char Column = '#';//179;

void Border() {                     //External frame 

    for (int i = 1; i < LENGTH; i++)//for the column
    {
        Locate(BEGIN, i);           //from (0,1) ~ (0,20)
        cout << Column;
        Locate(WIDTH, i);           //from (70,1) ~ (70,20)
        cout << Column;
    }
    for (int i = 1; i < WIDTH; i++)//for the raw
    {
        Locate(i, BEGIN);           //from(1,0) ~ (69,0)
        cout << Raw;
        Locate(i, LENGTH);          //from(1,21) ~ (69,21)
        cout << Raw;
    }
    //for the 4 corners
    Locate(BEGIN, BEGIN);
    cout << TopCornerLeft;
    Locate(WIDTH, BEGIN);
    cout << TopCornerRight;
    Locate(BEGIN, LENGTH);
    cout << BottomCornerLeft;
    Locate(WIDTH, LENGTH);
    cout << BottomCornerRight;
   
}

void Intro()                        //at the beginning write the words"WELCOME TO SURVIVAL RACE"
{
    Border();                       //External frame

    int x = 11;
    int y = 4;
                                    
    W(x, y);
    E(x, y);
    L(x, y);
    C(x, y);
    O(x, y);
    M(x, y);
    E(x, y);

    x = x + 1;
    T(x, y);
    O(x, y);

    y = y + 6;
    x = 6;
    S(x, y);
    U(x, y);
    R(x, y);
    V(x, y);
    I(x, y);
    V(x, y);
    A(x, y);
    L(x, y);

    x = x + 1;
    R(x, y);
    A(x, y);
    C(x, y);
    E(x, y);
}

void Score(int score, int difficulty)     //print the score and difficulty and Some introduction
{
    Border();
    for (int i = BEGIN; i <= LENGTH; i++) //Inner border
    {
        Locate(TEXT_X - 2, i);
        cout << Column;
    }
    Locate(TEXT_X - 2, BEGIN);
    cout << MidTop;
    Locate(TEXT_X - 2, LENGTH);
    cout << MidBottom;

    int Y = TEXT_Y;

    Locate(TEXT_X, Y);                      //print score and level
    cout << "Score: " << score;
    Y = Y + 1;
    Locate(TEXT_X,Y);
    cout << "Level: " << difficulty;
    Y = Y + 2;
    Locate(TEXT_X,Y);
    cout << "Move left: A";                 //print some introduction
    Y = Y + 1;
    Locate(TEXT_X, Y);
    cout << "Move right: D";
    Y = Y + 2;
    Locate(TEXT_X, Y);
    cout << "Object:         Score:";
    Y = Y + 1;
    Locate(TEXT_X, Y);
    cout << "Car:   x        -200";
    Y = Y + 1;
    Locate(TEXT_X, Y);
    cout << "Rocks: *        -100";
    Y = Y + 1;
    Locate(TEXT_X, Y);
    cout << "Nail:  +        -50";
    Y = Y + 1;
    Locate(TEXT_X, Y);
    cout << "Fuel:  O         +50";
    Y = Y + 1;
}

void TheEnd() {                     //at the end write the words"GAME OVER"
    Border();
    int x = 0;
    int y = 0;

    x = 14;
    y = 8;
    G(x, y);
    A(x, y);
    M(x, y);
    E(x, y);

    x = x + 1;
    O(x, y);
    V(x, y);
    E(x, y);
    R(x, y);
}
