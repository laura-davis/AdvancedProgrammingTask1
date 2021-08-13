#pragma once // Use header file only once when compiling source code

#include <string> // Include string library for purposes of printing currentDirection
#include "GameComponent.h" // Include GameComponent header file to make use of declarations

using namespace std; // Use standard namespace to make use of string library

class DrawableGameComponent : public GameComponent { // DrawableGameComponent class inherits from GameComponent class
public:
    enum Direction : unsigned char { // Assign directions to integers 1 - 4
        Left = 1,
        Right = 2,
        Up = 3,
        Down = 4
    };
    Direction direction; // Direction variable

    DrawableGameComponent(int x, int y); // Signature declaration for DrawableGameComponent constructor

    const int SCREEN_HEIGHT = 20; // SCREEN_HEIGHT should always equal 20
    const int SCREEN_WIDTH = 80; // SCREEN_WIDTH should always equal 80

    void Update(const tm *eventTime) override ; // Signature declaration for Update function

private:
    void ChangeDirection(); // Signature declaration for ChangeDirection function

    void Draw(); // Signature declaration for Draw function

    int x; // X co-ordinate variable
    int y; // Y co-ordinate variable

    void CurrentPosition(); // New signature declaration for CurrentPosition function, to calculate current position /
    // direction - not mentioned in assignment brief

    string currentDirection; // New string variable to hold value of current direction - not mentioned in assignment
    // brief
};