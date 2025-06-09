# Here are instructions for the Game of Nim project given by CodeHS

Now that you have a basic game on Nim down, you are going to make a variation. For this variation, you are going to create three stacks, each stack containing 10 items. The goal is still the same, take the last item, but now the players can take any number of items as long as they are from the same stack.

For example, in the first round, the user could take as few as 1 item or as many as 10 items from any one of the stacks.

Your program will get more complicated. You now need to ask the user which stack they want to take from and then ask how many items, from 1 to the number in the stack.

To help with this, you will be given 3 global variables defined at the top of the program. Since these are defined at the top of the program and not in any function, the variables can be used throughout the program without the need to pass them between functions.

The computer turn will function similarly to the player with the computer randomly picking a stack and then randomly picking the number of items in the stack.

Remember, you can only pick a stack if there is at least 1 item in the stack. You will want to make sure both the user and the computer follow this rule.

You will need to modify your userTurn and computerTurn functions and will likely benefit from some additional helper functions.

Sample Output:

Stack 1  Stack 2  Stack 3
  10        10        10
Pick a stack: 1
Pick up to 10: 9

Stack 1  Stack 2  Stack 3
  1        10        10
Computer removes 1 from stack 3

Stack 1  Stack 2  Stack 3
  1        10        9
Pick a stack: 2
Pick up to 10: 9

Stack 1  Stack 2  Stack 3
  1        1        9
Computer removes 1 from stack 3

Stack 1  Stack 2  Stack 3
  1        1        8
Pick a stack: 3
Pick up to 8: 4

Stack 1  Stack 2  Stack 3
  1        1        4
Computer removes 1 from stack 2

Stack 1  Stack 2  Stack 3
  1        0        4
Pick a stack: 3
Pick up to 4: 3

Stack 1  Stack 2  Stack 3
  1        0        1
Computer removes 1 from stack 3

Stack 1  Stack 2  Stack 3
  1        0        0
Pick a stack: 1
Pick up to 1: 1

Game over: User wins!
