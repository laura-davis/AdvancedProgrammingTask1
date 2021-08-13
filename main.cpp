#include <iostream> // Include iostream library to abbreviate cout and endl commands

#include "Game.h" // Include Game header file to make use of class declarations
#include "GameComponent.h" // Include GameComponent header file to make use of class declarations
#include "DrawableGameComponent.h" // Include DrawableGameComponent header file to make use of class declarations

void Initialise() {
    cout << "Initialising game" << endl; // Declaration and definition of Initialise function - prints to console;
    // invoked by passing standalone function address
}

void Terminate() {
    cout << "Terminating game" << endl; // Declaration and definition of Terminate function - prints to console;
    // invoked by passing standalone function address
}

int main() {
    Game game(1); // Create a dynamic instance of Game

    game.SetInitialise(Initialise); // Invoke SetInitialise

    game.SetTerminate(Terminate); // Invoke SetTerminate

    game.Add(new GameComponent()); // Add GameComponent with an ID of 1 to the game object

    game.Add(new DrawableGameComponent(0, 0)); // Add DrawableGameComponent with an ID of 2
    // and a position with co-ordinates of X = 0, Y = 0 to the game object

    game.Run(); // Invoke game object's Run member function
}