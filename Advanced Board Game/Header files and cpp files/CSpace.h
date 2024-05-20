#pragma once 

#include "CPlayer.h" // Include the CPlayer header file
#include <iostream> // Include the iostream standard library for input/output
#include <string> // Include the string standard library for string manipulation
using namespace std; // Use the standard namespace

class CPlayer; // Forward declaration of the CPlayer class

// Declaration of the CSpace class
class CSpace
{
protected:
    int mType; // Type of the space
    string mName; // Name of the space

public:
    // Constructor for the CSpace class, taking type and name as parameters
    CSpace(int, string);

    // Setter method for setting the type of the space
    void SetType(int);

    // Setter method for setting the name of the space
    void SetName(string Name);

    // Getter method for getting the type of the space
    int GetType();

    // Getter method for getting the name of the space
    string GetName();

    // Virtual method for outputting a message when a player lands on the space
    virtual void OutputMsg(CPlayer*);

    // Virtual method for the effect of the space on the player
    virtual void effect(CPlayer*);
};
