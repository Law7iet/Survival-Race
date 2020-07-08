// to use standar ASCII, put '#' as value of variables in raws 16-17-18-19-20-21-22-23

#define BEGIN 0
#define LENGTH 21
#define WIDTH 70
#define POS_X_TEXT 42
#define POS_Y_TEXT 2

#include <iostream>
#include "../headers/Locate.h"
#include "../headers/Graphics.h"
#include "../headers/Words.h"

using namespace std;

char TopCornerLeft = 218;
char TopCornerRight = 191;
char MiddleTop = 194;
char MiddleBottom = 193;
char BottomCornerLeft = 192;
char BottomCornerRight = 217;
char Raw = 196;
char Column = 179;

void Border() {
    // print colums
    for (int i = 1; i < LENGTH; i++)
    {
        // from (0, 1) to (0, 20)
        Locate(BEGIN, i);
        cout << Column;
        // from (70, 1) to (70, 20)
        Locate(WIDTH, i);
        cout << Column;
    }
    // print raws
    for (int i = 1; i < WIDTH; i++)
    {
        // from (1, 0) to (69, 0)
        Locate(i, BEGIN);
        cout << Raw;
        // from (1, 21) to (69, 21)
        Locate(i, LENGTH);
        cout << Raw;
    }
    // print 4 corners
    Locate(BEGIN, BEGIN);
    cout << TopCornerLeft;
    Locate(WIDTH, BEGIN);
    cout << TopCornerRight;
    Locate(BEGIN, LENGTH);
    cout << BottomCornerLeft;
    Locate(WIDTH, LENGTH);
    cout << BottomCornerRight;
}

void Intro()
{
    Border();

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

void Score(int score, int difficulty)
{
    Border();
    // an inner border
    for (int i = BEGIN; i <= LENGTH; i++)
    {
        Locate(POS_X_TEXT - 2, i);
        cout << Column;
    }
    Locate(POS_X_TEXT - 2, BEGIN);
    cout << MiddleTop;
    Locate(POS_X_TEXT - 2, LENGTH);
    cout << MiddleBottom;

    int PosText = POS_Y_TEXT;

    // print score and level
    Locate(POS_X_TEXT, PosText);
    cout << "Score: " << score;
    PosText = PosText + 1;
    Locate(POS_X_TEXT, PosText);
    cout << "Level: " << difficulty;
    PosText = PosText + 2;
    // print istructions
    Locate(POS_X_TEXT, PosText);
    cout << "Move left: A";
    PosText = PosText + 1;
    Locate(POS_X_TEXT, PosText);
    cout << "Move right: D";
    PosText = PosText + 2;
    Locate(POS_X_TEXT, PosText);
    cout << "Object:         Score:";
    PosText = PosText + 1;
    Locate(POS_X_TEXT, PosText);
    cout << "Car:   x        - 200";
    PosText = PosText + 1;
    Locate(POS_X_TEXT, PosText);
    cout << "Rocks: *        - 100";
    PosText = PosText + 1;
    Locate(POS_X_TEXT, PosText);
    cout << "Nail:  +        -  50";
    PosText = PosText + 1;
    Locate(POS_X_TEXT, PosText);
    cout << "Fuel:  O        +  50";
    PosText = PosText + 1;
}

void TheEnd() {
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
