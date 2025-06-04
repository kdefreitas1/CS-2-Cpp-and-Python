#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

struct movie
{
    string title, actor;
    int year;
    double rating;
};

movie getMovie(string line)
{
    vector<string> newMovie;
    istringstream stream(line);
    string token;
    while(getline(stream,token,';'))
    {
        newMovie.push_back(token);
    }
    movie m;
    m.title = newMovie[0];
    m.year = stoi(newMovie[1]);
    m.actor = newMovie[2];
    m.rating = stod(newMovie[3]);
    return m;
}

void list(vector<movie> movies, int count)
{
    for(int i = 0; i < movies.size(); i++)
    {
        cout << "Title: " << movies[i].title << endl;
        cout << "Year: " << movies[i].year << endl;
        cout << "Actor: " << movies[i].actor << endl;
        cout << "Rating: " << movies[i].rating << endl;
        cout << endl;
    }
    cout << "Total Count: " << count << endl;
}

void search(vector<movie> movies)
{
    cout << "Search menu:" << endl;
    cout << "1. Search by Title" << endl;
    cout << "2. Search by Year" << endl;
    cout << "3. Search by Actor" << endl;
    cout << "4. Search by Rating" << endl;
    int choice;
    while(true)
    {
        cout << "Enter option: ";
        string line;
        getline(cin,line);
        try
        {
            choice = stoi(line);
            if(choice == 1)
            {
                cout << "Please enter a title to search for: ";
                string title;
                getline(cin,title);
                vector<movie> foundMovies;
                int count = 0;
                for(int i = 0; i < movies.size(); i++)
                {
                    if(movies[i].title.find(title) != string::npos)
                    {
                        movie foundMovie;
                        foundMovie.title = movies[i].title;
                        foundMovie.year = movies[i].year;
                        foundMovie.actor = movies[i].actor;
                        foundMovie.rating = movies[i].rating;
                        foundMovies.push_back(foundMovie);
                        count++;
                    }
                }
                list(foundMovies,count);
                break;
            }
            else if(choice == 2)
            {
                cout << "Please enter the starting year to search: ";
                int startYear;
                cin >> startYear;
                
                cout << "Please enter the ending year to search: ";
                int endYear;
                cin >> endYear;
                cin.ignore();
                
                vector<movie> foundMovies;
                int count = 0;
                for(int i = 0; i < movies.size(); i++)
                {
                    if(movies[i].year >= 2010 && movies[i].year <= 2012)
                    {
                        movie foundMovie;
                        foundMovie.title = movies[i].title;
                        foundMovie.year = movies[i].year;
                        foundMovie.actor = movies[i].actor;
                        foundMovie.rating = movies[i].rating;
                        foundMovies.push_back(foundMovie);
                        count++;
                    }
                }
                list(foundMovies,count);
                break;
            }
            else if(choice == 3)
            {
                cout << "Please enter a actor to search for: ";
                string actor;
                getline(cin,actor);
                vector<movie> foundMovies;
                int count = 0;
                for(int i = 0; i < movies.size(); i++)
                {
                    if(movies[i].actor.find(actor) != string::npos)
                    {
                        movie foundMovie;
                        foundMovie.title = movies[i].title;
                        foundMovie.year = movies[i].year;
                        foundMovie.actor = movies[i].actor;
                        foundMovie.rating = movies[i].rating;
                        foundMovies.push_back(foundMovie);
                        count++;
                    }
                }
                list(foundMovies,count);
                break;
            }
            else if(choice == 4)
            {
                cout << "Please enter a rating to search for: ";
                double rating;
                cin >> rating;
                cin.ignore();
                vector<movie> foundMovies;
                int count = 0;
                for(int i = 0; i < movies.size(); i++)
                {
                    if(movies[i].rating == rating)
                    {
                        movie foundMovie;
                        foundMovie.title = movies[i].title;
                        foundMovie.year = movies[i].year;
                        foundMovie.actor = movies[i].actor;
                        foundMovie.rating = movies[i].rating;
                        foundMovies.push_back(foundMovie);
                        count++;
                    }
                }
                list(foundMovies,count);
                break;
            }
            else if(choice < 1 || choice > 4)
            {
                cout << "Please enter a number between 1 and 4." << endl;
                continue;
            }
        }
        catch(invalid_argument)
        {
            cout << "Not a valid number. Please try again." << endl;
            continue;
        }
    }
}

int main()
{
    vector<movie> movies;
    
    ifstream in;
    in.open("movies.txt");
    if(in.fail()) 
        cout << "File didn't open" << endl;
    
    int count = 0;
    string line;
    while(getline(in,line))
    {
        movies.push_back(getMovie(line));
        count++;
    }
    while(true)
    {
        string choice;
        cout << "Would you like to (s)earch, (l)ist movies, or (e)xit? ";
        getline(cin, choice);
        
        if(choice == "e")
        {
            break;
        }
        else if(choice == "l")
        {
            list(movies,count);
        }
        else if(choice == "s")
        {
            search(movies);
        }
        else
        {
            cout << "That is not an option please try again." << endl;
        }
    }
    return 0;
}