#include <iostream> // Include iostream library to make use of "chrono" and "thread" functions
#include <iomanip> // Include iomanip library to make use of put_time for formatting purposes

#include "GameComponent.h" // Include GameComponent header file to make use of class declarations

int GameComponent::instances; // Defining static instance variable

GameComponent::GameComponent(){
    id = ++instances; // Constructor for GameComponent; the creation of each new component generates a new ID
    // and increases the number of instances
}

void GameComponent::Update(const tm* time) {
    cout << "ID : " << id << " Updated @ " << put_time(time, "%X") << endl; // Display object's ID and time of
    // invocation
};