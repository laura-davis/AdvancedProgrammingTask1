#pragma once // // Use header file only once when compiling source code

#include "GameComponent.h" // Include GameComponent header file to make use of declarations

using namespace std; // Use standard namespace to make use of string library

typedef void(*FP)(); // A typedef representing a type of function that returns void and has no parameters

class Game { // Controlling class which manages GameComponent and DrawableGameComponent entities

public:

    void Add(GameComponent *); // Signature declaration for Add function

    Game(int maxComponents); // Constructor - maxComponents not actually defined in assignment

    void Run(); // Signature declaration for Run function

    void SetInitialise(FP init);// Signature declaration for SetInitialise function

    void SetTerminate(FP term); // Signature declaration for SetTerminate function

private:

    int componentCount = 0; // Variable holding the number of components in array

    GameComponent *components[5]{}; // Initialising GameComponent array to 5

    const int TICKS_1000MS = 1000; // Variable to hold the value of one second when using chrono library, ::milliseconds

    FP initialise{}; // Pointer to standalone initialise function

    FP terminate{}; // Pointer to standalone terminate function
};