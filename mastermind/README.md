# Instructions for the Mastermind Project given by CodeHS

## Instructions
Mastermind is a strategy game where a player is trying to break a code. The code is expressed as pegs of a variety of colors and the player tries to guess the specific colors and order of the code. In this project, you are going to create your own version of this classic game.

The game will start by asking the user how many pegs and how many colors they want to use. Based on this, you should create a board with the given number of pegs and randomly pick colors for each of these pegs. The colors will be represented by numbers from 1 to the number of colors chosen.

Once the code has been created, the game will ask the player for a color for each peg. Based on the user input, two numbers will be returned:

1. The number of pegs correct, which represents the number of pegs in the code that are the right color AND in the correct location.
2. The number of pegs with the right color, but not in the right place. You should be careful not to double-count pegs. If the board has one peg with a particular color and the user guesses that color twice, you should only report one number.

Here are a few examples.

- If the code is 3, 4, 5 and the user guesses 1, 2, 3, you should return 0 correct and 1 color correct, but the wrong place.
- If the code is 3, 4, 5 and the user guesses 4, 4, 1, you should return 1 correct and 0 colors correct, but in the wrong place. Even though the first 4 is a correct number, you don’t want to double count it.
- If the code is 3, 4, 5 and the user guesses 2, 3, 3 you should return 0 correct and 1 color correct, but in the wrong place.

Once the user guesses the correct code, print out the number of turns it took to get correct.

**Sample Output:**
```
Please select the number of pegs (1-8): 3
Please select the number of colors (1-8): 4
Please enter the color for peg 1: 1
Please enter the color for peg 2: 2
Please enter the color for peg 3: 3
You have 1 pegs correct and 1 colors correct but in the wrong place.
Please enter the color for peg 1: 1 
Please enter the color for peg 2: 3
Please enter the color for peg 3: 4
You have 0 pegs correct and 2 colors correct but in the wrong place.
Please enter the color for peg 1: 2
Please enter the color for peg 2: 4
Please enter the color for peg 3: 3
Great job! You solved the puzzle in 3 turns.
```
