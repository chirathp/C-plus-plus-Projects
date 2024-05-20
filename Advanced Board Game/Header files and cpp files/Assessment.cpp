#include "Assessment.h"
#include "CPlayer.h"

// Constructor
Assessment::Assessment(int type, string name, int motivation, int success, int year) : CSpace(type, name), mMotivation(motivation), mSuccess(success), mYear(year) {
    mCompleted[0] = nullptr;
    mCompleted[1] = nullptr;
}

// Setters
void Assessment::SetMotivation(int motivation) {
    mMotivation = motivation;
}

void Assessment::SetSuccess(int success) {
    mSuccess = success;
}

void Assessment::SetYear(int year) {
    mYear = year;
}

// Getters
int Assessment::GetMotivation() {
    return mMotivation;
}

int Assessment::GetSuccess() {
    return mSuccess;
}

int Assessment::GetYear() {
    return mYear;
}

// Output message
void Assessment::OutputMsg(CPlayer* player) {
    cout << player->GetName() << " completes the " << mName << " for " << mMotivation << " and achieves " << mSuccess << endl;
}

// Effect on player
void Assessment::effect(CPlayer* player) {
    int motivationCost;
    int AchievementScore = mSuccess;
    bool playerFound = false;
    CSpace::OutputMsg(player); // Call the base class's OutputMsg function

    // Check if player has enough motivation to complete the assessment
    if (player->GetMotivation() > mMotivation)
    {
        // Check if player has already completed the assessment
        for (int i = 0; i < 2; i++)
        {
            if (player == mCompleted[i])
            {
                playerFound = true;
            }
        }

        // If player has not completed the assessment
        if (playerFound == false)
        {
            // Calculate motivation cost and achievement score based on completion status
            if (mCompleted[0] == nullptr)
            {
                motivationCost = mMotivation;
                AchievementScore = mSuccess;
            }
            else
            {
                motivationCost = mMotivation / 2;
                AchievementScore = mSuccess / 2;
                mCompleted[0]->SetSuccess(mCompleted[0]->GetSuccess() + AchievementScore); // Update the other player's success
            }

            // Update player's motivation and success
            player->SetMotivation(player->GetMotivation() - motivationCost);
            player->SetSuccess(player->GetSuccess() + AchievementScore);

            // Set player as completed the assessment
            if (mCompleted[0] == nullptr)
            {
                mCompleted[0] = player;
            }
            else
            {
                mCompleted[1] = player;
            }
        }

        OutputMsg(player); // Output completion message
        if (mCompleted[0] != nullptr)
        {
            cout << mCompleted[0]->GetName() << " helps and achieves " << AchievementScore << endl; // Output message if another player helped
        }
    }
}
