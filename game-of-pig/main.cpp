#include "util.h"

int main()
{
    int turn = 0;
    int totalScore = 0;
    int cpuTotal = 0;
    while(true)
    {
        turn++;
        int roundScore = 0;
        string userChoice;
        cout << "Turn " << turn << endl;
        cout << "Your Current Score is: " << totalScore << endl;
        cout << "Computer Current Score is: " << cpuTotal << endl;
        cout << "This round you have: " << roundScore << endl;
        while(true)
        {
            userChoice = toLowerCase(readLine("Would you like to roll or bank? "));
            cout << endl;
            if(userChoice == "roll")
            {
                int roll = randInt(1,6);
                cout << "You rolled a " << roll << endl;
                if(roll == 1)
                {
                    cout << "You rolled a 1! You get a zero for this round!" << endl;
                    cout << endl;
                    break;
                }
                roundScore += roll;
                cout << "This round you have: " << roundScore << endl;
                continue;
            }
            else if(userChoice == "bank")
            {
                totalScore += roundScore;
                break;
            }
            else
            {
                cout << "Please only type roll or bank." << endl;
                continue;
            }
        }
        while(true)
        {
            int roll = randInt(1,6);
            if(roll == 1)
            {
                cout << "The computer rolled a 1. End of turn" << endl;
                cout << endl;
                break;
            }
            roundScore += roll;
            cout << "The computer rolled a " << roll << endl;
            cout << "This round the computer has: " << roundScore << endl;
            
            if(roundScore > 15)
            {
                cout << "The computer chooses to bank. " << endl;
                cout << endl;
                cpuTotal += roundScore; 
                break;
            }
            cout << "The computer chooses to roll again. " << endl;
            cout << endl;
        }
        if(totalScore >= 100 || cpuTotal >= 100)
        {
            break;
        }
    }
    if(totalScore > cpuTotal)
    {
        cout << "Congratulation! You won on " << turn << " turns!" << endl;
    }
    else if(totalScore < cpuTotal)
    {
        cout << "Good try! The Computer won on " << turn << " turns." << endl;
    }
    else
    {
        cout << "You both got the same score and tied in " << turn << " turns." << endl;
    }
    return 0;
}