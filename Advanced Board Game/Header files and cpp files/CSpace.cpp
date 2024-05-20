#include "CSpace.h" // Include the CSpace header file
#include "CPlayer.h" // Include the CPlayer header file
#include <iostream> // Include the iostream standard library for input/output
using namespace std; // Use the standard namespace

/**
 * @brief Constructor for CSpace
 * @param type The type of the space
 * @param name The name of the space
*/
// Constructor for the CSpace class, taking type and name as parameters
CSpace::CSpace(int type, string name) : mType(type), mName(name) {}

// Setter method for setting the type of the space
void CSpace::SetType(int type) {
    mType = type;
}

/**
 * @brief Setter function for setting the name of the space
 * @param name The name to set
*/
// Setter method for setting the name of the space
void CSpace::SetName(string name) {
    mName = name;
}

/**
 * @brief Getter function for getting the type of the space
 * @return The type of the space
*/
// Getter method for getting the type of the space
int CSpace::GetType() {
    return mType;
}

/**
 * @brief Getter function for getting the name of the space
 * @return The name of the space
*/
// Getter method for getting the name of the space
string CSpace::GetName() {
    return mName;
}

// Output message method, which prints the player's name and the space they landed on
void CSpace::OutputMsg(CPlayer* player) {
   cout <<  player->GetName() << " lands on " << mName << endl;
}

// Effect method, which simply calls the OutputMsg method
void CSpace:: effect(CPlayer* player) {
    OutputMsg(player);
}
