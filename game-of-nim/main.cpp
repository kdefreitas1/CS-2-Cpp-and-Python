#include "util.h"

// Variables defined here can be used in any function
int stack1 = 10;
int stack2 = 10;
int stack3 = 10;
vector<int> stacks = {stack1,stack2,stack3};

int userTurn()
{
    int stack = readInt(1,3,"Pick a stack: ");
    while(stacks[stack-1] == 0)
    {
        stack = readInt(1,3,"Stack has 0 items pick another: ");
    }
    cout << "Pick up to " << stacks[stack-1];
    int pick = readInt(1,stacks[stack-1],": ");
    stacks[stack-1] -= pick;
    return pick;
}

int computerTurn()
{
    int stack = randInt(0,2);
    while(stacks[stack] == 0)
    {
        stack = randInt(0,2);
    }
    int pick = randInt(1,stacks[stack]);
    stacks[stack] -= pick;
    cout << "Computer removes " << pick << " from stack " << stack+1 << endl;    
    return pick;
}

int main()
{
    int allStacks = stack1+stack2+stack3;
    int turn = 0;
    while(allStacks > 0)
    {
        cout << "Stack 1 Stack 2 Stack 3" << endl;
        cout << "  " << stacks[0] << "      " << stacks[1] << "      " << stacks[2] << endl;
        if(turn % 2 == 0)
        {
            allStacks -= userTurn();
        }
        else
        {
            allStacks -= computerTurn();
        }
        cout << endl;
        if(allStacks <= 0)
        {
            break;
        }
        turn++;
    }
    
    if(turn % 2 == 0)
    {
        cout << "Game over: User wins!" << endl;
    }
    else
    {
        cout << "Game over: Computer wins!" << endl;
    }
    return 0;
}