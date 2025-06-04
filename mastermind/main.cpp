#include "util.h"
#include <vector>

// function checks user inputs returns # of correct pegs and # correct colors but wrong place
vector<int> checkInputs(int numPegs, vector<int> userColors, vector<int> correctColors)
{
    vector<int> correct{0,0}; // the first num is # of correct pegs and the other is # of correct color but wrong place
    vector<bool> check; // to store if user has correctly guessed the certain peg or not
    
    // loops through each guess to see if they the peg correct
    for(int i = 0; i < numPegs; i++)
    {
        check.push_back(false);
        if(userColors[i] == correctColors[i])
        {
            correct[0]++;
            check[i] = true;
        }
    }
    
    // loops through each guess to see if they got the correct color but in wrong place 
    for(int i = 0; i < numPegs; i++)
    {
        /* 
        this prevents double checks 
        if the peg is already correct it prevents checking if user got color correct but in wrong place
        */
        if(check[i] == true)
        {
            continue;
        }
        
        // this is to check if user has correct color but in the wrong place (peg)
        for(int j = 0; j < numPegs; j++)
        {
            // checks if user has correct color wrong place
            if(userColors[i] == correctColors[j] && check[j] == false)
            {
                correct[1]++;
                check[j] = true;
            }
        }
    }
    return correct;
}

int main()
{
    int turns; // counts # of turns 
    int numPegs = readInt(1,8,"Please select the number of pegs (1-8): ", "Not in range of numbers try again: "); // asks user for # of pegs
    int numColors = readInt(1,8,"Please selct the number of colors (1-8): ", "Not in range of numbers try again: "); // asks user for # of colors
    vector<int> correctColors; // this stores the correct colors
    vector<int> userColors; // this stores waht the user guesses as the correct colors
    
    // this for loop puts random nums as correct colors and temp fills up user colors
    for(int i = 0; i < numPegs; i++)
    {
        correctColors.push_back(randInt(1,numColors)); 
        userColors.push_back(0); 
    }
    
    // the loop goes through until user correctly guesses all pegs
    while(true)
    {
        turns++;
        // for loop asks user for their guess per each peg
        for(int i = 0; i < numPegs; i++)
        {
            cout << "Please enter the color for peg " << i+1;
            int getColor = readInt(1,numColors,": ","That is not one of the colors you can pick: ");
            userColors[i] = getColor;
        }
        vector<int> checked = checkInputs(numPegs,userColors,correctColors); //this checks the users colros to see if theyre correct or not
        
        //breaks if user correctly guesses all pegs
        if(checked[0] == numPegs)
        {
            break;
        }
        cout << "You have " << checked[0] << " pegs correct and " << checked[1] << " colors correct but in the wrong place." << endl;
    }
    cout << "Great job! You solved the puzzle in " << turns << " turns." << endl;
    return 0;
}