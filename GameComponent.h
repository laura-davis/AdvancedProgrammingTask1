#pragma once // Use header file only once when compiling source code

#include <ctime> // Include ctime library to make use of time functions

using namespace std; // Use standard namespace to make use of string library

class GameComponent { // Represents non-visual entities in the game
public:
    GameComponent(); // Signature declaration for GameComponent constructor

    virtual void Update(const tm *time); // Signature declaration for Update method

private:
    static int instances; // Static variable to hold number of instances of GameComponent / DrawableGameComponent

protected:
    int id; // Protected int variable (amended from private) to store GameComponent / DrawableGameComponent ID
};