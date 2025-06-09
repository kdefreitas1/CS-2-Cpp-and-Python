# Instructions for the Game of Pig project given by CodeHs

(The project was split into 2 parts the current code is from the **final** part).

## Part 1
The Game of Pig is a classic game played with a 6 sided die. In the game a player rolls the die. If they roll a 2 through 6, they add that score to their round score, but if they roll a 1, their round is over and their round score resets to zero.

At any point, the player can choose to bank their round score. When they do that, the points are added to their overall score and their round score resets back to zero.

Once the player’s overall score reaches 100, they win. While the die roll is random, there is a little strategy when deciding whether to bank or continue in the round. If you try to be a pig and get more points, you may lose everything and have to start over!

More information on the game can be found on wikipedia.

For the first part of this project, you are going to make the basic gameplay and keep track of how many turns it takes to win. At the start of each turn, you should display the turn number and the player’s score. Each round, you should ask the player if they want to roll or bank the points. If they bank, you move on to the next turn, otherwise you roll again. If they roll a 1, then that round ends and the round score is reset. Otherwise, add the number from the die to the round score. Play continues like that until you get to 100 or more.

You can implement this several different ways, but you should make use of the `util` library. One thing to consider is that in the next activity, you will be adding a computer player. Keep that in mind as you think about the design.

Partial Sample Output:
```
Turn 1
Your Current Score is: 0
This round you have: 0
Would you like to roll or bank? roll

You rolled a 2.
This round you have: 2
Would you like to roll or bank? roll

You rolled a 3.
This round you have: 5
Would you like to roll or bank? bank

Turn 2
Your Current Score is: 5
This round you have: 0
Would you like to roll or bank? roll

You rolled a 4.
This round you have: 4
Would you like to roll or bank? roll

You rolled a 4.
This round you have: 8
Would you like to roll or bank? roll

You rolled a 6.
This round you have: 14
Would you like to roll or bank? roll

You rolled a 1.
You rolled a 1! You get a zero for this round!

...

Congratulation! You won on 13 turns!
```
## Part 2
For the second part of this project, you are going to add a computer opponent.

The game play is essentially the same. The player will take their turn and then the computer will take a turn. When the computer is playing, it will always continue while the round score is less than or equal to 15. Once they are over 15, it will bank its point (unless it rolls a 1 first).

The game should continue until either the player or computer roll over 100 in the round. If both roll over 100 in the same round, the winner is the player with the higher total.

**Sample Output:**
```
Turn 1
Your Current Score is: 0
Computer Current Score is: 0
This round you have: 0
Would you like to roll or bank? roll

You rolled a 6.
This round you have: 6
Would you like to roll or bank? roll

You rolled a 1.
You rolled a 1! You get a zero for this round!

The computer rolled a 5
This round the computer has: 5
The computer chooses to roll again.

The computer rolled a 3
This round the computer has: 8
The computer chooses to roll again.

The computer rolled a 1. End of turn
...
Good try! The Computer won on 10 turns.
```
