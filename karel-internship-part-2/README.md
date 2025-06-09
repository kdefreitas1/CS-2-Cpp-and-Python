# Instructions for the Karel Internship Project given by CodeHS

(The project was split into 2 parts the current code is from the **final** part).

## Insturctions

### Background

You have been hired by Karel Inc, a new dog training company, to help build out a dog training simulation. In this simulator, we are trying to teach Karel to sit. As he sits, he accumulates treats.

Unfortunately, the previous intern didn’t get a chance to debug his code and he left it in a state of an infinite loop. Your job is to figure out how many treats Karel has accumulated before the program starts looping.

### Information

You will complete this in two parts. In part one, you are going to create a struct that can store an instruction. The instruction should hold the following three values:
```
string inst 
int value
bool visited
```
The `inst` value will be one of three values:

`acc` - Accumulate the number of treats denoted by the value. Go on to the next line of code.

`jmp` - Jump forwards or backwards in the code by the number of lines in the value. Execute that line of code next.

`sit` - Sit for the number of seconds denoted by the value, then go on to the next line of code. (Note, you do not need to pause the code in this step, but go on to the next line.)

The `value` value will tell you how much of the step to do. Note that it will either have a plus or a minus. You can include the plus or minus when converting to an integer without a problem.

The `visited` variable is going to keep track of whether we have visited that instruction before. Once you hit an instruction that we have previously visited, you will know that we are in a loop. (Note: you will not visit every instruction.)
### Part 2

For part 2, you are going to take the struct you built in part 1 and use it to analyze the program.

Start by prompting the user for a name of an input file. Once they provide the name, you should open the file and read in each line as a new instruction and save to a vector. Make sure you use error handling in case the user enters a file name that is not found!

After reading in all the instructions, you will process them to determine how many treats Karel accumulates before the program loops. Once the program visits the same instruction a second time, you know you are looping and should output the number of treats accumulated.

Here is an example. If you are given the following file as input:
```
jmp +3
acc +17
jmp +3
acc +8
sit +45
jmp -4 
acc -5
```
Your program should then output 25.

The steps in the program will execute in the following order:
```
jmp +3   (1)
acc +17  (5)
jmp +3   (6)
acc +8   (2)
sit +45  (3)
jmp -4  (4) / (7)
acc -5
```
The first step is to jump 3, which then takes you to the accumulate 8 step. Next, the program advances to the sit and then jump -4 step, where it jumps back to line 2 and accumulate 17. It then steps forward followed by a jump 3 which takes it back to the jump -4 line. Since we already visited the jump -4 line, we know we are in a loop and can print out 25 and exit.

Included are two test files, the example above and another larger test. For the larger test, you should get 1489 for your output. Test both of these.
