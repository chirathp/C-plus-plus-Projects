#pragma once

#include "CPlayer.h" // Include the CPlayer header file
#include <iostream>
#include <string>
#include "CSpace.h" // Include the CSpace header file
using namespace std;

class CPlayer; // Forward declaration of the CPlayer class

// Definition of the Assessment class, which inherits from CSpace
class Assessment : public CSpace
{
protected:
    // Member variables for motivation, success, year, and an array of completed players
    int mMotivation;
    int mSuccess;
    int mYear;
    CPlayer* mCompleted[2]; // Array to hold pointers to two completed players

public:
    // Constructor for the Assessment class, taking type, name, motivation, success, and year as parameters
    Assessment(int, string, int, int, int);

    // Setter methods for motivation, success, and year
    void SetMotivation(int);
    void SetSuccess(int);
    void SetYear(int);

    // Getter methods for motivation, success, and year
    int GetMotivation();
    int GetSuccess();
    int GetYear();

    // Output message method, which overrides the base class method
    void OutputMsg(CPlayer*) override;

    // Effect method, which defines the effect of the assessment on a player
    void effect(CPlayer*);
};
