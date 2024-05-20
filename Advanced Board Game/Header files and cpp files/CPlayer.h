#pragma once

#include <iostream>
#include <string>
using namespace std;

class CPlayer
{
private:
    string mName;             // Player's name
    int mMotivation = 1000;   // Player's motivation level (initialized to 1000)
    unsigned int mSuccess = 0; // Player's success level (initialized to 0)
    int mYear = 1;            // Player's year of study (initialized to 1)
    int mPosition = 0;        // Player's position on the board (initialized to 0)

public:
    // Constructor
    CPlayer(string);

    // Setter methods
    void SetName(string);
    void SetMotivation(int);
    void SetSuccess(unsigned int);
    void SetYear(int);
    void SetPosition(int);

    // Getter methods
    string GetName();
    int GetMotivation();
    unsigned int GetSuccess();
    int GetYear();
    int GetPosition();
};

