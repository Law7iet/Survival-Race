# Survival Race
## Game Description
Survival Race is a 2D infinite racing game written in **C++**.
The game doesn't use graphics library and it's implemented using ASCII characters.\
The main objects are:
- `V` is the car
- `x`, `+` and `*`are obstacles
- `O` is the fuel

The road is marked by `|`, and the car can move inside the road using the keyboards `A` to move on the left, and `D` to move on the right.
The car can't move along (vertically) the road and it's on the top of the view.
The car's speed depends on the current level.\
The game's difficult increase with the points gained, and after reach a score multple of 200 there's a level-up.
As you level-up there will be more items on the road and the car's speed will increase.\
Hitting obstaces will reduce the points, and it could be decrease your current level.
If the points will be less than 0 the game ends.

## Compiling and Running
This project uses [Make](https://en.wikipedia.org/wiki/Make_(software)) and [GCC](https://en.wikipedia.org/wiki/GNU_Compiler_Collection) to compile.
The program is runnable on **Windows** and it needs these libraries:
* Windows.h
* conio.h
* iostream
* stdlib.h
* time.h

After download the repository, open the repository with Windows PowerShell.
The PowerShell screen-size should be 75x25.\
To compile the program, write `make`.\
To execute the program, write `.\Main.exe`.\

To control the project's requirements you can add `#define DEBUG` in the `Survival-Race.cpp` file (and maximize the window-size).
Running the program in *DEBUG* mode the game could be less smooth, but on the right there're details of the level.\
The program uses extended ASCII table; if there're some problems with the graphics, change `Graphics.cpp` and `Road.cpp` as written in the first comments.