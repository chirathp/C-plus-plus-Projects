#include <iostream>
#include <memory>
#include "CSpace.h"
#include "CPlayer.h"
#include <fstream> // For file input/output
#include <sstream> // For string stream
#include <vector>  // For vector container
#include <string>  // For string manipulation
#include "Assessment.h" // Assuming Assessment is a class or struct used in the code
#include <crtdbg.h>

using namespace std;

// Function to generate a random number between 1 and 10
int Random()
{
    return static_cast<int>(static_cast<double>(rand()) / (RAND_MAX + 1) * 10.0f + 1);
}

// Function to read space information from a file and populate a vector of spaces
void ReadSpaceInfo(vector<shared_ptr<CSpace>>& pSpaces)
{
    ifstream file("degrees.txt"); // Open the file
    if (!file.is_open())
    {
        cout << "Failed to open the file." << endl; // Display error message if file opening fails
    }
    else
    {
        string line; // String to store each line of the file
        int spaceType = 0; // Variable to store space type
        string spaceName; // Variable to store space name
        string spaceMotivation; // Variable to store space motivation
        string spaceScore; // Variable to store space score
        string spaceYear; // Variable to store space year

        // Read each line of the file
        while (getline(file, line))
        {
            spaceType = line[0] - '0'; // Extract space type from the first character of the line
            spaceName = "";
            spaceMotivation = "";
            spaceScore = "";
            spaceYear = "";
            int spaceCounter = 0;

            // Parse the rest of the line to extract space information
            for (int i = 2; i < line.length(); i++)
            {
                // Extract space name
                if (!(47 < line[i] && line[i] < 58) && line[i] != 32) {
                    spaceName = spaceName + line[i];
                }
                else if (line[i] == 32 && spaceCounter == 0) {
                    spaceName = spaceName + line[i];
                }
                else
                {
                    // Determine which field (motivation, score, or year) the current character belongs to
                    switch (spaceCounter)
                    {
                    case 0:
                        spaceMotivation = spaceMotivation + line[i]; // Append characters to space motivation
                        break;
                    case 1:
                        spaceScore = spaceScore + line[i]; // Append characters to space score
                        break;
                    case 2:
                        spaceYear = spaceYear + line[i]; // Append characters to space year
                        break;
                    }

                    // If the next character is a space, move to the next field
                    if (i != line.length() && line[i + 1] == 32)
                        spaceCounter++;
                }
            }

            // Create a new shared pointer to a space object based on the space type
            if (spaceType == 1)
            {
                pSpaces.push_back(make_shared<Assessment>(spaceType, spaceName, stoi(spaceMotivation), stoi(spaceScore), stoi(spaceYear)));
            }
            else
            {
                pSpaces.push_back(make_shared<CSpace>(spaceType, spaceName));
            }
        }
    }
}

// Function to read the seed for the random number generator from a file
int GetSrand()
{
    ifstream file("seed.txt"); // Open the file
    string number;
    getline(file, number); // Read the number from the file
    return (stoi(number)); // Convert the number to an integer and return it
}

// Function to move a player based on a spin number
void Move(CPlayer* player, int spinNumber, vector<shared_ptr<CSpace>>* pSpaces)
{
    cout << player->GetName() << " spins " << spinNumber << endl;
    int spaceNumber = player->GetPosition() + spinNumber;

    // If the player moves past the last space, wrap around to the beginning
    if (spaceNumber > 35)
    {
        spaceNumber = spaceNumber - 36;
        player->SetMotivation(player->GetMotivation() + 250);
        player->SetYear(player->GetYear() + 1);
        cout << player->GetName() << " Attends welcome week and starts year " << player->GetYear() << " more motivated!" << endl;
    }

    player->SetPosition(spaceNumber); // Set the player's position to the new space number

    // Call the effect function of the space the player landed on
    (*pSpaces)[spaceNumber]->effect(player);

    // Output the player's motivation and score
    cout << player->GetName() << "'s motivation is " << player->GetMotivation() << " and score is " << player->GetSuccess() << endl << endl;
}

// Main function
int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    vector<shared_ptr<CSpace>> pSpaces; // Vector to store shared pointers to spaces
    CPlayer player1("Vyvyan"); // Create player 1
    CPlayer player2("Rick"); // Create player 2

    cout << "Welcome to Scumbag College" << endl << endl;

    ReadSpaceInfo(pSpaces); // Read space information from file
    srand(GetSrand()); // Seed the random number generator

    // Play 20 rounds of the game
    for (int i = 0; i < 20; i++)
    {
        cout << "Round " << i + 1 << endl << "==========" << endl;
        int spinNumber = Random(); // Generate a random spin number for player 1
        Move(&player1, spinNumber, &pSpaces); // Move player 1

        spinNumber = Random(); // Generate a random spin number for player 2
        Move(&player2, spinNumber, &pSpaces); // Move player 2
    }

    // Output the final scores and the winner of the game
    cout << endl << "Game Over " << endl << "===========" << endl << endl;
    cout << "Vyvyan has achieved " << player1.GetSuccess() << endl;
    cout << "Rick has achieved " << player2.GetSuccess() << endl;

    if (player1.GetSuccess() > player2.GetSuccess())
    {
        cout << "Vyvyan Wins!" << endl;
    }
    else
    {
        cout << "Rick Wins!" << endl;
    }

    return 0;
}
