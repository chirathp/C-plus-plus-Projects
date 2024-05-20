#include "CPlayer.h" // Include the CPlayer header file
#include <iostream> // Include the iostream standard library for input/output
using namespace std; // Use the standard namespace

/**
 * @brief Constructor for CPlayer
 * @param name The name of the player
 */
 // Constructor for the CPlayer class, taking the player's name as a parameter
CPlayer::CPlayer(string name) : mName(name) {}

/**
* @brief Set the name of the player
* @param name The name of the player
*/
// Setter method for setting the player's name
void CPlayer::SetName(string name) {
    mName = name;
}

/**
* @brief Set the motivation level of the player
* @param motivation The motivation level to set
*/
// Setter method for setting the player's motivation level
void CPlayer::SetMotivation(int motivation) {
    mMotivation = motivation;
}

/**
 * @brief Set the success of the player
 * @param success The success level to set
*/
// Setter method for setting the player's success level
void CPlayer::SetSuccess(unsigned int success) {
    mSuccess = success;
}

/**
* @brief Set the year of study of the player
* @param year The year of study to set
*/
// Setter method for setting the player's year of study
void CPlayer::SetYear(int year) {
    mYear = year;
}

/**
* @brief Set the position of the player on the board
* @param position The position to set
*/
// Setter method for setting the player's position on the board
void CPlayer::SetPosition(int position) {
    mPosition = position;
}


/**
* @brief Get the name of the player
* @return The name of the player
*/
// Getter method for getting the player's name
string CPlayer::GetName() {
    return mName;
}

/**
* @brief Get the motivation level of the player
* @return The motivation level of the player
*/
// Getter method for getting the player's motivation level
int CPlayer::GetMotivation() {
    return mMotivation;
}


/**
* @brief Get the success level of the player
* @return The success level of the player
*/
// Getter method for getting the player's success level
unsigned int CPlayer::GetSuccess() {
    return mSuccess;
}

/**
* @brief Get the year of study of the player
* @return The year of study of the player
*/
// Getter method for getting the player's year of study
int CPlayer::GetYear() {
    return mYear;
}


/**
* @brief Get the position of the player on the board
* @return The position of the player on the board
*/
// Getter method for getting the player's position on the board
int CPlayer::GetPosition() {
    return mPosition;
}


