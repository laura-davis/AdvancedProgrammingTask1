#include <iostream> // Include iostream library to abbreviate cout and endl commands
#include "DrawableGameComponent.h" // Include DrawableGameComponent header file to make use of class declarations

DrawableGameComponent::DrawableGameComponent(int x, int y) : GameComponent() {
    this->x = x; // Set X co-ordinate passed via constructor
    this->y = y; // Set Y co-ordinate passed via constructor
    direction = Up; // Set default direction to "Up"
}

void DrawableGameComponent::ChangeDirection() {
    srand(time(nullptr)); // Generate rand seed using Epoch time
    int randomNumber = (rand() % 4) + 1; // Generate a random number between 1 - 4
    while (randomNumber == direction) // While the random number equates to that of the current direction...
        randomNumber = (rand() % 4) + 1; // ...Generate a new random number
    direction = static_cast<Direction>(randomNumber); // Set new direction according to random number generated
};

void DrawableGameComponent::Draw() {
    cout << currentDirection << " : " << "X : " << x << ", Y : " << y
         << endl; // Output current direction and co-ordinates
}

void DrawableGameComponent::CurrentPosition() {
    switch (direction) {
        case Left: // Complete below steps if ChangeDirection function has generated a direction of "Left"
            x--; // Decrement X co-ordinate by 1
            if (x < 0) { // Check that new value of X is not less than 0
                x = 0; // If X is now less than 0, reset to 0
            }
            currentDirection = "Left"; // Set currentDirection string for Draw method to "Left"
            break;
        case Right: // Complete below steps if ChangeDirection function has generated a direction of "Right"
            x++; // Increment X co-ordinate by 1
            if (x >
                SCREEN_WIDTH) { // Check that new value of X is not more than the width of the screen (set to 80 in Header file)
                x = SCREEN_WIDTH; // If X is now more than 80, reset to 80
            }
            currentDirection = "Right"; // Set currentDirection string for Draw method to "Right"
            break;
        case Up: // Complete below steps if ChangeDirection function has generated a direction of "Up"
            y++; // Increment X co-ordinate by 1
            if (y >
                SCREEN_HEIGHT) { // Check that new value of Y is not more than the height of the screen (set to 20 in Header file)
                y = SCREEN_HEIGHT; // If X is now more than 20, reset to 20
            }
            currentDirection = "Up"; // Set currentDirection string for Draw method to "Left"
            break;
        case Down: // Complete below steps if ChangeDirection function has generated a direction of "Down"
            y--;// Decrement Y co-ordinate by 1
            if (y < 0) { // Check that new value of Y is not less than 0
                y = 0; // If Y is now less than 0, reset to 0
            }
            currentDirection = "Down"; // Set currentDirection string for Draw method to "Down"
            break;
        default:
            break;
    }
}

void DrawableGameComponent::Update(const tm *eventTime) {
    GameComponent::Update(eventTime); // Call inherited "Update" method from GameComponent to print ID and updated time
    CurrentPosition(); // Calculate current co-ordinates and direction
    Draw(); // Output current direction and co-ordinates
    ChangeDirection(); // Generate a random number to cast new direction
}