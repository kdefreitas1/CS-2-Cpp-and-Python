# Instructions for the Movies Project given by CodeHS
(The project was split into 3 parts the current code is from the **final** part)

(All instructions are given from each part)
## Part 1
The Internet Movie Database (IMDB) is a wealth of knowledge for movie lovers. It stores information about particular movies, actors, and ratings. Over the next few lessons, you will be building out a movie database program that can search for content in movies similar to how the IMDB works.. In this lesson, we will start by setting up the structure for our movies.

Each movie should have 4 pieces of data: a `string` title, `string` actor, an `int` year it was made, and a `double rating` on a scale from 1 to 10.

Your program should run off a main menu that gives the user the option to add a movie, list the current movies, or exit. If they are adding a movie, you should prompt for the title, actor, the year it was released, and the rating.

Movies should be stored in a vector of movie structs.

**Sample Output:**
```
Would you like to (a)dd a movie, (l)ist movies, or (e)xit? a
Please enter the title:Star Wars
Please enter an actor(Last, First): Ford, Harrison
Please enter the year: 1977
Please enter the rating (1-10): 9.7
Would you like to (a)dd a movie, (l)ist movies, or (e)xit? a
Please enter the title: Back To The Future
Please enter an actor(Last, First): Fox, Michael J
Please enter the year: 1985
Please enter the rating (1-10): 9.2
Would you like to (a)dd a movie, (l)ist movies, or (e)xit? l
Title: Star Wars
Year: 1977
Actor: Ford, Harrison
Rating: 9.7

Title: Back To The Future
Year: 1985
Actor: Fox, Michael J
Rating: 9.2

Would you like to (a)dd a movie, (l)ist movies, or (e)xit? e
```
## Part 2


You are going to continue working on our version of the IMDB. In this part, you are going to refactor your part 1 so that your program can now read in values from a file.

Start by copying over your solution from Movies - Part 1. You are going to replace your function that added a movie via user prompts with a function that will add a movie from a file line input.

Each line of the file is a separate entry, semicolon `;` separated in the following order:

`title; year; actor; rating`

Modify your list function to print out all the movies followed by the total count that you printed.

The file should be read in automatically, so you do not need a menu option to import it. You can modify your menu to have just two options at this point, list and exit.

**Sample Output:**
```
Would you like to (l)ist movies or (e)xit? l
Title: Biography
Year: 1987
Actor: Freeman, Morgan
Rating: 8.1

...

Title: American Playhouse
Year: 1981
Actor: Sinise, Gary
Rating: 7.4
```
Total Count: 483
Would you like to (l)ist movies or (e)xit? x
## Part 3

For this final part of our Movie Database in this unit, we are going to add a search feature to the menu.

Once the user selects to search, you should call the search function that prompts the user for a field to search. If they search for an Actor or Title, then prompt them for a string to search for. If they choose to search for a year or rating, prompt them for a range (i.e. starting and ending year or min and max rating).

Your search menu should take a numeric option and you should catch any invalid characters and separately catch any value that is not in the range. (See sample output). As a challenge, see if you can also catch invalid entries for the year and rating search.

Once you have a valid search criteria, use the list function you created earlier to print out the results.

**Sample Output:**
```
Would you like to (s)earch, (l)ist movies or (e)xit? s
Search menu:
1. Search by Title
2. Search by Year
3. Search by Actor
4. Search by Rating
Enter option: title
Not a valid number. Please try again. 
Enter option: 0
Please enter a number between 1 and 4.
Enter option: 1
Please enter a title to search for: star
Title: Secrets of Superstar Fitness
Year: 2002
Actor: Schwarzenegger, Arnold
Rating: 5.3

Total Count: 1
Would you like to (s)earch, (l)ist movies or (e)xit? s
Search menu:
1. Search by Title
2. Search by Year
3. Search by Actor
4. Search by Rating
Enter option: y
Not a valid number. Please try again. 
Enter option: 2
Please enter the starting year to search: 2010
Please enter the ending year to search: 2012
Title: MSN Exclusives
Year: 2012
Actor: Hanson, Zac
Rating: 6.7

...

Title: MSN Exclusives
Year: 2012
Actor: Hanson, Taylor (III)
Rating: 6.7

Total Count: 11
Would you like to (s)earch, (l)ist movies or (e)xit? e
```
