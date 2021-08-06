#include <thread> // Include thread library to make use of "chrono" and "thread" functions
#include "Game.h" // Include Game header file to make use of class declarations

void Game::Add(GameComponent *gameComponent) {
    components[componentCount++] = gameComponent; // Add GameComponent / DrawableGameComponent object to array of
    // pointers of type GameComponent
}

Game::Game(int maxComponents) {}; // MaxComponents parameter not actually used / mentioned in assignment

void Game::SetInitialise(FP init) { initialise = init; } // Assigns address of function to "Initialise" data member

void Game::SetTerminate(FP term) { terminate = term; } // Assigns address of function to "Terminate" data member

void Game::Run() {
    initialise(); // Invokes function with address assigned to "Initialise" pointer
    for (auto &component : components) { // For each component in the components array...
        for (int j = 0; j < componentCount; j++) { //...loop through the number of Components
            auto currentTime = chrono::system_clock::now(); // Time point representing current time
            auto inTimeT = chrono::system_clock::to_time_t(currentTime); // Convert current time to time type
            tm *time = localtime(&inTimeT); // Fill tm struct with current time
            components[j]->Update(time); // Call update function on component using current time
        }
        this_thread::sleep_for(chrono::milliseconds(TICKS_1000MS)); // Pause for one second
    }
    terminate(); // Invokes function with address assigned to "Terminate" pointer
}